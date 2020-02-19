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
		AfxMessageBox("���������ID��");
		return;
	}
	CFineDataSet m_rsFineDataset;
	if (!m_rsFineDataset.Open())
	{
		AfxMessageBox("���ݴ�ʧ�ܣ�");
	}
	if(m_rsFineDataset.IsBOF())
	{
		AfxMessageBox("����û�з����¼��");
		m_rsFineDataset.Close();
		return ;
	}

	CString INFO;
	INFO.Format("��ֹ��%s\n���ĳ�����������%s��\nΥԼ�𹲼�%sԪ\n���ȷ�����и���",CTime::GetCurrentTime().Format("%Y��%m��%d�� %X"),DAY,MONEY);
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
		AfxMessageBox("���ݱ�򿪴���!");
		return;
	}
	if (!m_rsFineDataSet.Open())
	{
		AfxMessageBox("���ݱ�򿪴���!");
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
			AfxMessageBox("û�и������ݣ�");
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
        m_book.SetItemText(i, 0, m_BOOK_ID);									//��ӵ�list Control �еĵ�i�еĵ�һ����
        m_book.SetItemText(i, 1, BOOK_NAME);		 							//��ӵ�list Control �еĵ�i�еĵڶ�����
        m_book.SetItemText(i, 2, m_BORROW_DATE.Format("%Y��%m��%d��"));			//��ӵ�list Control �еĵ�i�еĵ�������
        m_book.SetItemText(i, 3, m_FINE_DATE.Format("%Y��%m��%d��"));			//��ӵ�list Control �еĵ�i�еĵ�������
        m_book.SetItemText(i, 4, m_DAYS_);										//��ӵ�list Control �еĵ�i�еĵ�������
		m_book.SetItemText(i, 5, m_AMOUNT_);										//��ӵ�list Control �еĵ�i�еĵ�������
        i += 1;																	//�´�ѭ��ָ���2��
        m_rsFineDataSet.MoveNext();												//�ƶ�����һ����¼
	}
	m_rsDataSet.Close();
	m_rsFineDataSet.Close();
	info.Format("������������%d�죬ΥԼ�𹲼�%.2fԪ",Day,Money);
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
	//��ͷ
	m_book.InsertColumn(0,_T("ͼ��ID"), LVCFMT_LEFT,rect.Width()/5,0);
	m_book.InsertColumn(1,_T("ͼ������"), LVCFMT_LEFT,rect.Width()/5,1);
	m_book.InsertColumn(2,_T("��������"), LVCFMT_LEFT,rect.Width()/5,2);
	m_book.InsertColumn(3,_T("�黹����"), LVCFMT_LEFT,rect.Width()/5,3);
	m_book.InsertColumn(4,_T("ΥԼ����"), LVCFMT_LEFT,rect.Width()/5,4);
	m_book.InsertColumn(5,_T("���"), LVCFMT_LEFT,rect.Width()/5,5);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CFineDlg::Inster_Fine_History()
{
	UpdateData();
	CFineHistoryDataSet m_rsFineHisDataSet;
	if(!m_rsFineHisDataSet.Open())
	{
		AfxMessageBox("���ݱ��ʧ�ܣ�");
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


