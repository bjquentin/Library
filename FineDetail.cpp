// FineDetail.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "FineDetail.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFineDetail dialog


CFineDetail::CFineDetail(CWnd* pParent /*=NULL*/)
	: CDialog(CFineDetail::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFineDetail)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFineDetail::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFineDetail)
	DDX_Control(pDX, IDC_LIST1, m_book);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFineDetail, CDialog)
	//{{AFX_MSG_MAP(CFineDetail)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFineDetail message handlers

BOOL CFineDetail::OnInitDialog() 
{
	CDialog::OnInitDialog();
	long day=0;
	long money=0;

	// TODO: Add extra initialization here
	i=0;
	if(!m_rsFineDataSet.Open(AFX_DB_USE_DEFAULT_TYPE))
	{
		AfxMessageBox("数据表打开失败！");
		return FALSE;
	}
	if(!m_rsDataSet.Open(AFX_DB_USE_DEFAULT_TYPE))
	{
		AfxMessageBox("数据表打开失败！");
		return FALSE;
	}
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
	m_rsFineDataSet.m_strFilter="READER_ID='"+m_ReaderID+"'";
	while(!m_rsFineDataSet.IsEOF())
	{
		m_rsDataSet.m_strFilter="READER_ID='"+m_ReaderID+"'";
		if (m_rsDataSet.IsEOF())
		{
			AfxMessageBox("没有该书数据！");
			m_rsDataSet.Close();
			return FALSE;
		}
		BOOK_NAME=m_rsDataSet.m_BOOK_NAME;
		m_BOOK_ID=m_rsFineDataSet.m_BOOK_ID;
		m_AMOUNT.Format(_T("%ld"),m_rsFineDataSet.m_AMOUNT);
		money+=m_rsFineDataSet.m_AMOUNT;
		m_BORROW_DATE=m_rsFineDataSet.m_BORROW_DATE;
		m_DAYS.Format(_T("%d"),m_rsFineDataSet.m_DAYS);
		day+=m_rsFineDataSet.m_DAYS;
		m_FINE_DATE=m_rsFineDataSet.m_FINE_DATE;
				
		m_book.InsertItem(i, _T(""));
        m_book.SetItemText(i, 0, m_BOOK_ID);									//添加到list Control 中的第i行的第一列下
        m_book.SetItemText(i, 1, BOOK_NAME);		 							//添加到list Control 中的第i行的第二列下
        m_book.SetItemText(i, 2, m_BORROW_DATE.Format("%Y年%m月%d日"));			//添加到list Control 中的第i行的第三列下
        m_book.SetItemText(i, 3, m_FINE_DATE.Format("%Y年%m月%d日"));			//添加到list Control 中的第i行的第四列下
        m_book.SetItemText(i, 4, m_DAYS);										//添加到list Control 中的第i行的第五列下
		m_book.SetItemText(i, 5, m_AMOUNT);										//添加到list Control 中的第i行的第六列下
        i += 1;																	//下次循环指向第2行
        m_rsFineDataSet.MoveNext();												//移动到下一个记录
	}
	m_rsDataSet.Close();
	m_rsFineDataSet.Close();
	DAYS.Format(_T("%ld"),day);
	MONEY.Format(_T("%ld"),money);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
