// FineDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "FineDlg.h"

#include "ReaderDataSet.h"
#include "FineDataSet.h"
#include "FineHistoryDataSet.h"

#include "stdlib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFineDlg dialog


CFineDlg::CFineDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFineDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFineDlg)
	m_strReaderID = _T("");
	m_info = _T("");
	//}}AFX_DATA_INIT
}


void CFineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFineDlg)
	DDX_Control(pDX, IDC_LIST1, m_book);
	DDX_Text(pDX, IDC_READER_ID, m_strReaderID);
	DDV_MaxChars(pDX, m_strReaderID, 8);
	DDX_Text(pDX, IDC_EDIT1, m_info);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFineDlg, CDialog)
	//{{AFX_MSG_MAP(CFineDlg)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_CONFIRM, OnConfirm)
	ON_BN_CLICKED(IDC_ENQUERY, OnEnquery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFineDlg message handlers

void CFineDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

void CFineDlg::OnConfirm() 
{
    // TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_strReaderID.IsEmpty())
	{
		AfxMessageBox("请输入读者ID！");
		return;
	}
	CFineDataSet m_rsFineDataset;
	if (!m_rsFineDataset.Open())
	{
		AfxMessageBox("数据打开失败！");
	}
	if(m_rsFineDataset.IsBOF())
	{
		AfxMessageBox("读者没有罚款记录！");
		m_rsFineDataset.Close();
		return ;
	}

	CString INFO;
	INFO.Format("截止到%s\n您的超期天数共计%s天\n违约金共计%s元\n点击确定进行付款",CTime::GetCurrentTime().Format("%Y年%m月%d日 %X"),DAY,MONEY);
	AfxMessageBox(INFO,MB_YESNO|MB_ICONQUESTION);

	m_rsFineDataset.m_strFilter="READER_ID='"+m_strReaderID+"'";

	while(!m_rsFineDataset.IsEOF())
	{
		m_AMOUNT=m_rsFineDataset.m_AMOUNT;
		m_DAYS=m_rsFineDataset.m_DAYS;
		m_FINE_DATE=m_rsFineDataset.m_FINE_DATE;
		m_BOOK_ID=m_rsFineDataset.m_BOOK_ID;
		m_BORROW_DATE=m_rsFineDataset.m_BORROW_DATE;
		Inster_Fine_History();
		CRecordsetStatus status;
		m_rsFineDataset.GetStatus(status);
		m_rsFineDataset.Delete();
		if (status.m_lCurrentRecord==0)
			m_rsFineDataset.MoveNext();
		else
			m_rsFineDataset.MoveFirst();
	}
	m_rsFineDataset.Requery();
	m_rsFineDataset.Close();
}

void CFineDlg::OnEnquery() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString info;
	int i=0;
	if (!m_rsDataSet.Open())
	{
		AfxMessageBox("数据表打开错误!");
		return;
	}
	if (!m_rsFineDataSet.Open())
	{
		AfxMessageBox("数据表打开错误!");
		return;
	}
	m_rsFineDataSet.MoveNext();
	m_rsFineDataSet.m_strFilter="READER_ID='"+m_ReaderID+"'";
	while(!m_rsFineDataSet.IsEOF())
	{
		m_BOOK_ID=m_rsFineDataSet.m_BOOK_ID;

		m_rsDataSet.m_strFilter="BOOK_ID='"+m_BOOK_ID+"'";
		if (m_rsDataSet.IsEOF())
		{
			AfxMessageBox("没有该书数据！");
			m_rsDataSet.Close();
			return ;
		}
		BOOK_NAME=m_rsDataSet.m_BOOK_NAME;
		m_BORROW_DATE=m_rsFineDataSet.m_BORROW_DATE;
		m_DAYS_.Format(_T("%d"),m_rsFineDataSet.m_DAYS);
		Day+=m_rsFineDataSet.m_DAYS;
		m_AMOUNT_.Format(_T("%.2f"),Day*0.2);
		Money+=m_rsFineDataSet.m_AMOUNT;
		m_FINE_DATE=m_rsFineDataSet.m_FINE_DATE;
				
		m_book.InsertItem(i, _T(""));
        m_book.SetItemText(i, 0, m_BOOK_ID);									//添加到list Control 中的第i行的第一列下
        m_book.SetItemText(i, 1, BOOK_NAME);		 							//添加到list Control 中的第i行的第二列下
        m_book.SetItemText(i, 2, m_BORROW_DATE.Format("%Y年%m月%d日"));			//添加到list Control 中的第i行的第三列下
        m_book.SetItemText(i, 3, m_FINE_DATE.Format("%Y年%m月%d日"));			//添加到list Control 中的第i行的第四列下
        m_book.SetItemText(i, 4, m_DAYS_);										//添加到list Control 中的第i行的第五列下
		m_book.SetItemText(i, 5, m_AMOUNT_);										//添加到list Control 中的第i行的第六列下
        i += 1;																	//下次循环指向第2行
        m_rsFineDataSet.MoveNext();												//移动到下一个记录
	}
	m_rsDataSet.Close();
	m_rsFineDataSet.Close();
	info.Format("超期天数共计%d天，违约金共计%.2f元",Day,Money);
	m_info=info;
	UpdateData(FALSE);

}

BOOL CFineDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	MONEY.Format("%f",0);
	DAY.Format("%d",0);
	Day=0;
	Money=0;
	// TODO: Add extra initialization here
	CRect rect;
	m_book.GetClientRect(&rect);
	m_book.SetExtendedStyle( LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//表头
	m_book.InsertColumn(0,_T("图书ID"), LVCFMT_LEFT,rect.Width()/5,0);
	m_book.InsertColumn(1,_T("图书名称"), LVCFMT_LEFT,rect.Width()/5,1);
	m_book.InsertColumn(2,_T("借阅日期"), LVCFMT_LEFT,rect.Width()/5,2);
	m_book.InsertColumn(3,_T("归还日期"), LVCFMT_LEFT,rect.Width()/5,3);
	m_book.InsertColumn(4,_T("违约天数"), LVCFMT_LEFT,rect.Width()/5,4);
	m_book.InsertColumn(5,_T("金额"), LVCFMT_LEFT,rect.Width()/5,5);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CFineDlg::Inster_Fine_History()
{
	UpdateData();
	CFineHistoryDataSet m_rsFineHisDataSet;
	if(!m_rsFineHisDataSet.Open())
	{
		AfxMessageBox("数据表打开失败！");
		return FALSE;
	}
	m_rsFineHisDataSet.AddNew();
	m_rsFineHisDataSet.m_AMOUNT=m_AMOUNT;
	m_rsFineHisDataSet.m_DAYS=m_DAYS;
	m_rsFineHisDataSet.m_FINE_DATE=m_FINE_DATE;
	m_rsFineHisDataSet.m_OK_DATE=CTime::GetCurrentTime();
	m_rsFineHisDataSet.m_READER_ID=m_strReaderID;
	m_rsFineHisDataSet.m_BOOK_ID=m_BOOK_ID;
	m_rsFineHisDataSet.m_BORROW_DATE=m_BORROW_DATE;

	m_rsFineHisDataSet.Update();
	m_rsFineHisDataSet.Requery();
	m_rsFineHisDataSet.Close();
	return TRUE;
}


