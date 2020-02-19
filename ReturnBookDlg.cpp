// ReturnBookDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "time.h"
#include "ReturnBookDlg.h"
#include "FineDataSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReturnBookDlg dialog

int result;
CReturnBookDlg::CReturnBookDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReturnBookDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReturnBookDlg)
	m_Book_ID = _T("");
	m_BorrowDate = _T("");
	m_Days = 0;
	m_ReaderName = _T("");
	m_ReturnDate = _T("");
	m_Reader_ID = _T("");
	m_BOOK_NAME = _T("");
	//}}AFX_DATA_INIT
}


void CReturnBookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReturnBookDlg)
	DDX_Text(pDX, IDC_EDITBook_ID, m_Book_ID);
	DDV_MaxChars(pDX, m_Book_ID, 8);
	DDX_Text(pDX, IDC_EDITBorrowDate, m_BorrowDate);
	DDX_Text(pDX, IDC_EDITDays, m_Days);
	DDX_Text(pDX, IDC_READER_NAME, m_ReaderName);
	DDX_Text(pDX, IDC_EDITReturnDate, m_ReturnDate);
	DDX_Text(pDX, IDC_EDITReader_ID, m_Reader_ID);
	DDV_MaxChars(pDX, m_Reader_ID, 8);
	DDX_Text(pDX, IDC_BOOK_NAME, m_BOOK_NAME);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReturnBookDlg, CDialog)
	//{{AFX_MSG_MAP(CReturnBookDlg)
	ON_BN_CLICKED(IDC_ENQUERY, OnEnquery)
	ON_BN_CLICKED(IDC_CONFIRM, OnConfirm)
	ON_COMMAND(ID_APP_EXIT, OnAppExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReturnBookDlg message handlers

BOOL CReturnBookDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CString Time;
	CTime time=CTime::GetCurrentTime();
	Time=time.Format("�����������  %Y��%m��%d�� %X");
	GetDlgItem(IDC_NOW_TIME)->SetWindowText(Time);
	// TODO: Add extra initialization here
	setTxtDisable();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CReturnBookDlg::OnEnquery() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	GetDlgItem(IDC_CONFIRM)->EnableWindow(true);
	CTime  m_ReturnDate_tmp;
	CTime  m_Current_Time=CTime::GetCurrentTime();
	CTimeSpan m_TimeSpan_tmp(30,24,59,59);
	if (!m_Reader_ID.IsEmpty() && !m_Book_ID.IsEmpty())
	{
		m_rsDataSet.m_strFilter ="reader.reader_ID=borrow.reader_ID and BOOK_ID='"+m_Book_ID+"' and borrow.READER_ID='"+m_Reader_ID+"'";
	}
	else
	{
		AfxMessageBox("����ID��ͼ��ID����Ϊ�գ���");
		return;
	}
	if (!m_rsDataSet.Open())
	{
		AfxMessageBox("���ݴ�ʧ�ܣ�");
	}
	
	m_rsDataSet.Requery();
	if (m_rsDataSet.GetRecordCount()!=0) 
	{
			m_ReaderName=m_rsDataSet.m_ReaderName;
			m_rsBOOKNAMESet.m_strFilter="BOOK_ID='"+m_Book_ID+"'";
		if (!m_rsBOOKNAMESet.Open())
		{
			AfxMessageBox("���ݴ�ʧ�ܣ�");
		}
	
		m_rsBOOKNAMESet.Requery();
		if(	m_rsBOOKNAMESet.GetRecordCount()!=0)
		{
			m_BOOK_NAME=m_rsBOOKNAMESet.m_BOOK_NAME;
		}
		m_BorrowDate=m_rsDataSet.m_BORROW_DATE.Format("%Y��%m��%d��") ;
		m_ReturnDate_tmp=m_rsDataSet.m_BORROW_DATE+m_TimeSpan_tmp;
		m_ReturnDate=m_ReturnDate_tmp.Format("%Y��%m��%d��");
		if (m_ReturnDate_tmp<m_Current_Time)
		{
			m_TimeSpan_tmp=CTime::GetCurrentTime()-m_ReturnDate_tmp;
			m_Days=m_TimeSpan_tmp.GetDays();
			UpdateData(false);
			result=1;
		}
		else
		{
			UpdateData(false);
			result=2;
		
		}
	
		m_rsDataSet.Close();
		m_rsBOOKNAMESet.Close();
	}
	else
	{
		AfxMessageBox("���ݿⲻ���������Ϣ�������������Ϣ�Ƿ���ȷ��");
		OnAppExit();
		return ;
	}
}
void CReturnBookDlg::OnConfirm() 
{
	// TODO: Add your control notification handler code here
	CString m_strtmp;
	if (result==1)
	{
		m_strtmp.Format("����%d�죬���鴦��������ɡ��Ƿ�������������̣�",m_Days);
		if(::MessageBox(this->m_hWnd,m_strtmp,"��ʾ",MB_YESNO)==IDYES)
		{
			Insert_Fine();
			SetTxtNull();
		}
		else
			CDialog::OnClose();
	}
	else if(result==2)
	{
		if(::MessageBox(this->m_hWnd,"���鴦���������","��ʾ",MB_YESNO)==IDYES)
		{
			Insert_History();
			SetTxtNull();
		}
		else
			CDialog::OnClose();
	}
	else
	{
		CDialog::OnClose();
	}
	GetDlgItem(IDC_EDITBook_ID)->SetFocus();
	
}



BOOL CReturnBookDlg::setTxtDisable()
{
	GetDlgItem(IDC_BOOK_NAME)->EnableWindow(false);
	GetDlgItem(IDC_READER_NAME)->EnableWindow(false);
	GetDlgItem(IDC_EDITBorrowDate)->EnableWindow(false);
	GetDlgItem(IDC_EDITReturnDate)->EnableWindow(false);
	GetDlgItem(IDC_EDITDays)->EnableWindow(false);
	GetDlgItem(IDC_CONFIRM)->EnableWindow(false);
	return TRUE;
}

BOOL CReturnBookDlg::SetTxtNull()
{
	//m_Book_ID="";
	m_BorrowDate="";
	m_Days=0;
	m_ReaderName="";
	m_ReturnDate="";
	m_BOOK_NAME="";
	UpdateData(false);
	GetDlgItem(IDC_EDITBook_ID)->SetFocus();
	return TRUE;
}

BOOL CReturnBookDlg::Insert_History()
{
	CDatabase mdb;
	CString   m_strsql;

	if(!mdb.Open(_T("library")))
	{
		AfxMessageBox("���ݿ�ִ�г���");
		return FALSE;
	}

	m_strsql="INSERT INTO HISTORY (READER_ID,BOOK_ID,BORROW_DATE,RETURN_DATE) VALUES ('"+m_rsDataSet.m_READER_ID+"'";
	m_strsql=m_strsql+",'"+m_rsDataSet.m_BOOK_ID+"'";
	m_strsql=m_strsql+",'"+m_BorrowDate+"'";
	m_strsql=m_strsql+",'"+(CTime::GetCurrentTime()).Format("%Y,%B %d")+"')";
	try
	{
		mdb.BeginTrans();
		mdb.ExecuteSQL(m_strsql);
		mdb.CommitTrans();
	}
	catch(CDBException e)
	{
		AfxMessageBox("���ݿ�ִ�г���");
		return FALSE;
	}
	Process();
	Inset_Borrow_History();
	return TRUE;
}

BOOL CReturnBookDlg::Insert_Fine()
{
	UpdateData();
	CFineDataSet m_rsFineDataSet;
	int   a,b,c   ;   
	sscanf(m_BorrowDate.GetBuffer(m_BorrowDate.GetLength()),"%d��%d��%d��",&a,&b,&c);   
	CTime   time(a,b,c,0,0,0); 
	if (!m_rsFineDataSet.Open())
	{
		AfxMessageBox("���ݴ�ʧ�ܣ�");

	}
	m_rsFineDataSet.AddNew();

	m_rsFineDataSet.m_AMOUNT=m_Days*0.2;
	m_rsFineDataSet.m_BOOK_ID=m_Book_ID;
	m_rsFineDataSet.m_DAYS=m_Days;
	m_rsFineDataSet.m_BORROW_DATE=time;
    m_rsFineDataSet.m_FINE_DATE=CTime::GetCurrentTime();
	m_rsFineDataSet.m_READER_ID=m_Reader_ID;
	m_rsFineDataSet.Update();
	m_rsFineDataSet.Requery();
	m_rsFineDataSet.Close();
	Process();
	Inset_Borrow_History();
	return TRUE;
}

BOOL CReturnBookDlg::Process()
{
	CBookDataSet m_rsBookDataSet;
	CReaderDataSet m_rsReaderDataSet;
	if (!m_rsReaderDataSet.Open())
	{
		AfxMessageBox("���ݱ�򿪴���!");
		return FALSE;
	}
	m_rsReaderDataSet.m_strFilter="READER_ID='"+m_Reader_ID+"'";
	m_rsReaderDataSet.Requery();
	m_rsReaderDataSet.Edit();
	m_rsReaderDataSet.m_BORROW_NUM--;
	m_rsReaderDataSet.Update();
	m_rsReaderDataSet.Requery();
	m_rsReaderDataSet.Close();

	if(!m_rsBookDataSet.Open())
	{
		AfxMessageBox("���ݱ�򿪴���");
		return FALSE;
	}
	m_rsBookDataSet.m_strFilter="BOOK_ID='"+m_Book_ID+"'";
	m_rsBookDataSet.Requery();
	m_rsBookDataSet.Edit();
	m_rsBookDataSet.m_SURPLUS_NUM++;
	m_rsBookDataSet.Update();
	m_rsBookDataSet.Requery();
	m_rsBookDataSet.Close();

	return TRUE;
}

BOOL CReturnBookDlg::Inset_Borrow_History()
{
	UpdateData(TRUE);
	if (!m_rsBorrowHDataSet.Open())
	{
		AfxMessageBox("���ݴ�ʧ�ܣ�");
		return FALSE;
	}
	int   a,b,c   ;   
	sscanf(m_BorrowDate.GetBuffer(m_BorrowDate.GetLength()),"%d��%d��%d��",&a,&b,&c);   
	CTime   time(a,b,c,0,0,0); 

	m_rsBorrowHDataSet.AddNew();
	m_rsBorrowHDataSet.m_BOOK_ID=m_Book_ID;
	m_rsBorrowHDataSet.m_DAYS=m_Days;
	m_rsBorrowHDataSet.m_BORROW_DATE=time;
    m_rsBorrowHDataSet.m_RETURN_DATE=CTime::GetCurrentTime();
	m_rsBorrowHDataSet.m_READER_ID=m_Reader_ID;

	m_rsBorrowHDataSet.Update();
	m_rsBorrowHDataSet.Requery();
	m_rsBorrowHDataSet.Close();
	m_rsBorrowDataSet.m_strFilter ="BOOK_ID='"+m_Book_ID+"' and READER_ID='"+m_Reader_ID+"'";
	if (!m_rsBorrowDataSet.Open())
	{
		AfxMessageBox("���ݴ�ʧ�ܣ�");
	}
	if(m_rsBorrowDataSet.GetRecordCount()!=0)
	{
		m_rsBorrowDataSet.Delete();
		if (!m_rsBorrowDataSet.IsEOF())
			m_rsBorrowDataSet.MoveNext();
		else
			m_rsBorrowDataSet.MoveFirst();
	}

	m_rsBorrowDataSet.Requery();
	m_rsBorrowDataSet.Close();
	return TRUE;
}



void CReturnBookDlg::OnAppExit() 
{
	// TODO: Add your command handler code here
	
}
