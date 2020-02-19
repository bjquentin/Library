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
		AfxMessageBox("���ݱ��ʧ�ܣ�");
		return FALSE;
	}
	if(!m_rsDataSet.Open(AFX_DB_USE_DEFAULT_TYPE))
	{
		AfxMessageBox("���ݱ��ʧ�ܣ�");
		return FALSE;
	}
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
	m_rsFineDataSet.m_strFilter="READER_ID='"+m_ReaderID+"'";
	while(!m_rsFineDataSet.IsEOF())
	{
		m_rsDataSet.m_strFilter="READER_ID='"+m_ReaderID+"'";
		if (m_rsDataSet.IsEOF())
		{
			AfxMessageBox("û�и������ݣ�");
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
        m_book.SetItemText(i, 0, m_BOOK_ID);									//��ӵ�list Control �еĵ�i�еĵ�һ����
        m_book.SetItemText(i, 1, BOOK_NAME);		 							//��ӵ�list Control �еĵ�i�еĵڶ�����
        m_book.SetItemText(i, 2, m_BORROW_DATE.Format("%Y��%m��%d��"));			//��ӵ�list Control �еĵ�i�еĵ�������
        m_book.SetItemText(i, 3, m_FINE_DATE.Format("%Y��%m��%d��"));			//��ӵ�list Control �еĵ�i�еĵ�������
        m_book.SetItemText(i, 4, m_DAYS);										//��ӵ�list Control �еĵ�i�еĵ�������
		m_book.SetItemText(i, 5, m_AMOUNT);										//��ӵ�list Control �еĵ�i�еĵ�������
        i += 1;																	//�´�ѭ��ָ���2��
        m_rsFineDataSet.MoveNext();												//�ƶ�����һ����¼
	}
	m_rsDataSet.Close();
	m_rsFineDataSet.Close();
	DAYS.Format(_T("%ld"),day);
	MONEY.Format(_T("%ld"),money);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
