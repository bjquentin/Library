// BookMDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "BookMDlg.h"

#include "BookDataSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBookMDlg dialog


CBookMDlg::CBookMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBookMDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBookMDlg)
	m_strAuthor = _T("");
	m_strBookID = _T("");
	m_strBookIDQ = _T("");
	m_strBookName = _T("");
	m_strBookNameQ = _T("");
	m_strFlag = _T("");
	m_strPress = _T("");
	m_strPressDate = _T("");
	m_nBookNum = 0;
	m_nSurplusNum = 0;
	//}}AFX_DATA_INIT
}


void CBookMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBookMDlg)
	DDX_Text(pDX, IDC_AUTHOR, m_strAuthor);
	DDV_MaxChars(pDX, m_strAuthor, 8);
	DDX_Text(pDX, IDC_BOOKID, m_strBookID);
	DDV_MaxChars(pDX, m_strBookID, 8);
	DDX_Text(pDX, IDC_BOOKID_Q, m_strBookIDQ);
	DDV_MaxChars(pDX, m_strBookIDQ, 8);
	DDX_Text(pDX, IDC_BOOKNAME, m_strBookName);
	DDV_MaxChars(pDX, m_strBookName, 8);
	DDX_Text(pDX, IDC_BOOKNAME_Q, m_strBookNameQ);
	DDV_MaxChars(pDX, m_strBookNameQ, 8);
	DDX_Text(pDX, IDC_FLAG_BORROW, m_strFlag);
	DDV_MaxChars(pDX, m_strFlag, 1);
	DDX_Text(pDX, IDC_PRESS, m_strPress);
	DDV_MaxChars(pDX, m_strPress, 20);
	DDX_Text(pDX, IDC_PRESSDATE, m_strPressDate);
	DDV_MaxChars(pDX, m_strPressDate, 14);
	DDX_Text(pDX, IDC_BOOK_NUM, m_nBookNum);
	DDX_Text(pDX, IDC_SURPLUS_NUM, m_nSurplusNum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBookMDlg, CDialog)
	//{{AFX_MSG_MAP(CBookMDlg)
	ON_BN_CLICKED(IDC_CANCEL_REC, OnCancelRec)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_EDIT, OnEdit)
	ON_BN_CLICKED(IDC_ENQUERY, OnEnquery)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_NEW, OnNew)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_PRIOR, OnPrior)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBookMDlg message handlers

void CBookMDlg::OnCancelRec() 
{
	// TODO: Add your control notification handler code here
	m_bAdd = FALSE;
	m_bEdit = FALSE;
	DisplayRecord();
	SetButtonState();
	SetTextState();
	
}

void CBookMDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	m_rsDataSet.Delete();
	m_rsDataSet.MoveFirst();
	m_rsDataSet.Requery();
	DisplayRecord();
	SetButtonState();
	
}

void CBookMDlg::OnEdit() 
{
	// TODO: Add your control notification handler code here
	m_bEdit = TRUE;
	SetButtonState();
	SetTextState();
	GetDlgItem(IDC_BOOKID_Q)->EnableWindow(FALSE);
	GetDlgItem(IDC_BOOKNAME_Q)->EnableWindow(FALSE);
	GetDlgItem(IDC_BOOKNAME)->SetFocus();
	
}

void CBookMDlg::OnEnquery() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_strBookIDQ.IsEmpty() && m_strBookNameQ.IsEmpty())
	{
		m_rsDataSet.m_strFilter = "";
		m_rsDataSet.Requery();
		DisplayRecord();
		SetButtonState();
		return;
	}
	BOOL mAll = FALSE;
	if (!m_strBookIDQ.IsEmpty())
	{
		m_rsDataSet.m_strFilter = "BOOK_ID='" + m_strBookIDQ ;
		m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + "'";
		mAll = TRUE;
	}
	if (!m_strBookNameQ.IsEmpty())
	{
		if (mAll)
		{
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + " AND BOOK_NAME='";
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + m_strBookNameQ;
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + "'";
		}
		else
		{
			m_rsDataSet.m_strFilter = "BOOK_NAME='"  + m_strBookNameQ;
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + "'";
		}
			
	}
	m_rsDataSet.Requery();
	DisplayRecord();
	SetButtonState();

	
}

void CBookMDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
	m_rsDataSet.Close();
	
}


void CBookMDlg::OnNew() 
{
	// TODO: Add your control notification handler code here
	m_strBookID = "";
	m_strBookName = "";
	m_strAuthor = "";
	m_strPress = "";
	m_strFlag = "Y";
	m_strPressDate=CTime::GetCurrentTime().Format("%Y年%m月%d日");
	m_nBookNum=0;
	m_nSurplusNum=0;

	UpdateData(FALSE);
	m_bEdit = TRUE;
	m_bAdd = TRUE;
	SetButtonState();
	SetTextState();
	GetDlgItem(IDC_BOOKID_Q)->EnableWindow(FALSE);
	GetDlgItem(IDC_BOOKNAME_Q)->EnableWindow(FALSE);
	GetDlgItem(IDC_BOOKID)->SetFocus();
	
}

void CBookMDlg::OnNext() 
{
	// TODO: Add your control notification handler code here
	if(!m_rsDataSet.IsEOF())
	{
		m_rsDataSet.MoveNext();
		DisplayRecord();
		SetButtonState();
	}
	
}

void CBookMDlg::OnPrior() 
{
	// TODO: Add your control notification handler code here
	if(!m_rsDataSet.IsBOF())
	{
		m_rsDataSet.MovePrev();
		DisplayRecord();
		SetButtonState();
	}
	
}

void CBookMDlg::OnSave() 
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE);
	int   a,b,c   ;   
	sscanf(m_strPressDate.GetBuffer(m_strPressDate.GetLength()),"%d年%d月%d日",&a,&b,&c);   
	CTime   time(a,b,c,0,0,0); 
	if (m_strBookID.IsEmpty() || m_strBookName.IsEmpty())
	{
		AfxMessageBox("请输入相应数据！");
		return;
	}
	if (m_bAdd)
	{
		m_rsDataSet.AddNew();

	}
	else
	{
		m_rsDataSet.Edit();
	}
	m_rsDataSet.m_AUTHOR = m_strAuthor;
	m_rsDataSet.m_BOOK_NAME = m_strBookName;
	m_rsDataSet.m_BOOK_ID = m_strBookID;
	m_rsDataSet.m_PRESS = m_strPress;
	m_rsDataSet.m_PRESS_DATE=time;
	m_rsDataSet.m_FLAG_BORROW = m_strFlag;
	m_rsDataSet.m_BOOK_NUM=m_nBookNum;
	m_rsDataSet.m_SURPLUS_NUM=m_nSurplusNum;

	m_rsDataSet.Update();
	m_rsDataSet.Requery();
	m_bAdd = FALSE;
	m_bEdit = FALSE;
	DisplayRecord();
	SetButtonState();
	SetTextState();
	
}

BOOL CBookMDlg::DisplayRecord()
{
	if (m_rsDataSet.IsEOF() && m_rsDataSet.IsBOF())	
	{
		m_strBookID = "";
		m_strBookName = "";
		m_strPress = "";
		m_strAuthor = "";
		m_strFlag = "";
	}
	else
	{
		if (m_rsDataSet.IsBOF())
		{
			m_rsDataSet.MoveNext();
		}
		else
		{	
			if (m_rsDataSet.IsEOF())
			{		
				m_rsDataSet.MovePrev();
			}
		}
		m_strBookID = m_rsDataSet.m_BOOK_ID;
		m_strBookName = m_rsDataSet.m_BOOK_NAME;
		m_strPress = m_rsDataSet.m_PRESS;
		m_strPressDate=(m_rsDataSet.m_PRESS_DATE).Format("%Y年%m月%d日");
		m_nBookNum=m_rsDataSet.m_BOOK_NUM;
		m_nSurplusNum=m_rsDataSet.m_SURPLUS_NUM;
		m_strAuthor = m_rsDataSet.m_AUTHOR ;
		m_strFlag = m_rsDataSet.m_FLAG_BORROW ;
	}
	UpdateData(FALSE);
	return TRUE;

}

BOOL CBookMDlg::SetTextState()
{
	CWnd *pWnd;

	if (m_bEdit)
	{
		GetDlgItem(IDC_BOOKNAME)->EnableWindow(TRUE);
		pWnd = GetDlgItem(IDC_BOOKID);
		if (m_bAdd)
			pWnd->EnableWindow(TRUE);
		else
			pWnd->EnableWindow(FALSE);
		GetDlgItem(IDC_AUTHOR)->EnableWindow(TRUE);
		GetDlgItem(IDC_PRESS)->EnableWindow(TRUE);
		GetDlgItem(IDC_PRESSDATE)->EnableWindow(TRUE);
		GetDlgItem(IDC_FLAG_BORROW)->EnableWindow(TRUE);
		GetDlgItem(IDC_BOOK_NUM)->EnableWindow(TRUE);
		GetDlgItem(IDC_SURPLUS_NUM)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_BOOKNAME)->EnableWindow(FALSE);
		GetDlgItem(IDC_BOOKID)->EnableWindow(FALSE);
		GetDlgItem(IDC_AUTHOR)->EnableWindow(FALSE);
		GetDlgItem(IDC_PRESS)->EnableWindow(FALSE);
		GetDlgItem(IDC_PRESSDATE)->EnableWindow(FALSE);
		GetDlgItem(IDC_FLAG_BORROW)->EnableWindow(FALSE);
		GetDlgItem(IDC_BOOK_NUM)->EnableWindow(FALSE);
		GetDlgItem(IDC_SURPLUS_NUM)->EnableWindow(FALSE);

	}
	GetDlgItem(IDC_BOOKNAME_Q)->EnableWindow(TRUE);
	GetDlgItem(IDC_BOOKID_Q)->EnableWindow(TRUE);
	return TRUE;

}

BOOL CBookMDlg::SetButtonState()
{
	if(!m_rsDataSet.IsOpen())
	{
		GetDlgItem(IDC_NEXT)->EnableWindow(FALSE);
		GetDlgItem(IDC_PRIOR)->EnableWindow(FALSE);
		
		GetDlgItem(IDC_NEW)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_ENQUERY)->EnableWindow(FALSE);
		GetDlgItem(IDC_DELETE)->EnableWindow(FALSE);
		GetDlgItem(IDC_SAVE)->EnableWindow(FALSE);
		GetDlgItem(IDC_CANCEL_REC)->EnableWindow(FALSE);
		

		return TRUE;
	}


	if (m_bEdit)
	{
		GetDlgItem(IDC_NEXT)->EnableWindow(FALSE);
		GetDlgItem(IDC_PRIOR)->EnableWindow(FALSE);


		GetDlgItem(IDC_NEW)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_ENQUERY)->EnableWindow(FALSE);
		GetDlgItem(IDC_DELETE)->EnableWindow(FALSE);
		GetDlgItem(IDC_SAVE)->EnableWindow(TRUE);
		GetDlgItem(IDC_CANCEL_REC)->EnableWindow(TRUE);

		return TRUE;

	}


	if (m_rsDataSet.IsBOF())
	{
		GetDlgItem(IDC_PRIOR)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_PRIOR)->EnableWindow(TRUE);
	}

	if (m_rsDataSet.IsEOF())
	{
		GetDlgItem(IDC_NEXT)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_NEXT)->EnableWindow(TRUE);

	}
	if (m_rsDataSet.IsBOF() && m_rsDataSet.IsEOF())
	{
		GetDlgItem(IDC_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_DELETE)->EnableWindow(FALSE);

	}
	else
	{
		GetDlgItem(IDC_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_DELETE)->EnableWindow(TRUE);

	}

	GetDlgItem(IDC_NEW)->EnableWindow(TRUE);
	GetDlgItem(IDC_ENQUERY)->EnableWindow(TRUE);
	GetDlgItem(IDC_SAVE)->EnableWindow(FALSE);
	GetDlgItem(IDC_CANCEL_REC)->EnableWindow(FALSE);

	return TRUE;

}

BOOL CBookMDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_bAdd = FALSE;
	m_bEdit = FALSE;

	if (!m_rsDataSet.Open(AFX_DB_USE_DEFAULT_TYPE))
		AfxMessageBox("数据打开失败！");

	DisplayRecord();
	SetButtonState();
	SetTextState();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
