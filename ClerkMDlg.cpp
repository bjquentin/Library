// ClerkMDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "ClerkMDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClerkMDlg dialog


CClerkMDlg::CClerkMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClerkMDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClerkMDlg)
	m_strIDCard = _T("");
	m_strPassword = _T("");
	m_strUserID = _T("");
	m_strUserIDQ = _T("");
	m_strUserName = _T("");
	m_strUserNameQ = _T("");
	//}}AFX_DATA_INIT
}


void CClerkMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClerkMDlg)
	DDX_Control(pDX, IDC_POSITION, m_cntrPosition);
	DDX_Text(pDX, IDC_IDCARD, m_strIDCard);
	DDV_MaxChars(pDX, m_strIDCard, 18);
	DDX_Text(pDX, IDC_PASSWORD, m_strPassword);
	DDV_MaxChars(pDX, m_strPassword, 8);
	DDX_Text(pDX, IDC_USERID, m_strUserID);
	DDV_MaxChars(pDX, m_strUserID, 8);
	DDX_Text(pDX, IDC_USERID_Q, m_strUserIDQ);
	DDV_MaxChars(pDX, m_strUserIDQ, 8);
	DDX_Text(pDX, IDC_USERNAME, m_strUserName);
	DDV_MaxChars(pDX, m_strUserName, 8);
	DDX_Text(pDX, IDC_USERNAME_Q, m_strUserNameQ);
	DDV_MaxChars(pDX, m_strUserNameQ, 8);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CClerkMDlg, CDialog)
	//{{AFX_MSG_MAP(CClerkMDlg)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_CANCEL_REC, OnCancelRec)
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
// CClerkMDlg message handlers

void CClerkMDlg::OnCancelRec() 
{
	// TODO: Add your control notification handler code here
	m_bAdd = FALSE;
	m_bEdit = FALSE;
	DisplayRecord();
	SetButtonState();

	SetTextState();
	
}

void CClerkMDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	m_rsDataSet.Delete();
	m_rsDataSet.MoveFirst();
	m_rsDataSet.Requery();
	DisplayRecord();
	SetButtonState();
	
}

void CClerkMDlg::OnEdit() 
{
	// TODO: Add your control notification handler code here
	m_bEdit = TRUE;
	SetButtonState();
	SetTextState();
	GetDlgItem(IDC_USERID_Q)->EnableWindow(FALSE);
	GetDlgItem(IDC_USERNAME_Q)->EnableWindow(FALSE);
	GetDlgItem(IDC_USERNAME)->SetFocus();

	
}

void CClerkMDlg::OnEnquery() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_strUserIDQ.IsEmpty() && m_strUserNameQ.IsEmpty())
	{
		m_rsDataSet.m_strFilter = "";
		m_rsDataSet.Requery();
		DisplayRecord();
		SetButtonState();
		return;
	}
	BOOL mAll = FALSE;
	if (!m_strUserIDQ.IsEmpty())
	{
		m_rsDataSet.m_strFilter = "CLERK_ID='" + m_strUserIDQ ;
		m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + "'";
		mAll = TRUE;
	}
	if (!m_strUserNameQ.IsEmpty())
	{
		if (mAll)
		{
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + " AND NAME='";
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + m_strUserNameQ;
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + "'";
		}
		else
		{
			m_rsDataSet.m_strFilter = "NAME='"  + m_strUserNameQ;
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + "'";
		}
			
	}
	m_rsDataSet.Requery();
	DisplayRecord();
	SetButtonState();

	
}

void CClerkMDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
	
}

void CClerkMDlg::OnFirst() 
{
	// TODO: Add your control notification handler code here
	if(!m_rsDataSet.IsBOF())
	{
		m_rsDataSet.MoveFirst();
		DisplayRecord();
		SetButtonState();
	}
	
}

void CClerkMDlg::OnLast() 
{
	// TODO: Add your control notification handler code here
	if(!m_rsDataSet.IsEOF())
	{
		m_rsDataSet.MoveLast();
		DisplayRecord();
		SetButtonState();
	}
	
}

void CClerkMDlg::OnNew() 
{
	// TODO: Add your control notification handler code here
	m_strUserID = "";
	m_strUserName = "";
	m_strIDCard = "";
	m_strPassword = "";
	m_cntrPosition.SetCurSel(0);
	UpdateData(FALSE);
	m_bEdit = TRUE;
	m_bAdd = TRUE;
	SetButtonState();
	SetTextState();
	GetDlgItem(IDC_USERID_Q)->EnableWindow(FALSE);
	GetDlgItem(IDC_USERNAME_Q)->EnableWindow(FALSE);
	GetDlgItem(IDC_USERNAME)->SetFocus();

	
}

void CClerkMDlg::OnNext() 
{
	// TODO: Add your control notification handler code here
	if(!m_rsDataSet.IsEOF())
	{
		m_rsDataSet.MoveNext();
		DisplayRecord();
		SetButtonState();
	}
}

void CClerkMDlg::OnPrior() 
{
	// TODO: Add your control notification handler code here
	if(!m_rsDataSet.IsBOF())
	{
		m_rsDataSet.MovePrev();
		DisplayRecord();
		SetButtonState();
	}
}

void CClerkMDlg::OnSave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_strIDCard.IsEmpty() || m_strUserName.IsEmpty() || m_strUserID.IsEmpty())
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
	m_rsDataSet.m_ID_CARD = m_strIDCard;
	m_rsDataSet.m_NAME = m_strUserName;
	m_rsDataSet.m_CLERK_ID = m_strUserID;
	m_rsDataSet.m_PASSWORD = m_strPassword;
	int nIndex=m_cntrPosition.GetCurSel();
	CString strPosition;
	m_cntrPosition.GetLBText(nIndex,strPosition);
	m_rsDataSet.m_OFFICIER=strPosition;
	m_rsDataSet.Update();
	m_rsDataSet.Requery();
	m_bAdd = FALSE;
	m_bEdit = FALSE;
	DisplayRecord();
	SetButtonState();
	SetTextState();
	
}

BOOL CClerkMDlg::DisplayRecord()
{
	if (m_rsDataSet.IsEOF() && m_rsDataSet.IsBOF())	
	{
		m_strUserID = "";
		m_strUserName = "";
		m_strIDCard = "";
		m_strPassword = "";
		m_cntrPosition.SelectString(1,"");
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
		m_strUserID = m_rsDataSet.m_CLERK_ID;
		m_strUserName = m_rsDataSet.m_NAME;
		m_strIDCard = m_rsDataSet.m_ID_CARD;
		m_strPassword = m_rsDataSet.m_PASSWORD ;
		m_cntrPosition.SelectString(1,m_rsDataSet.m_OFFICIER);
	}
	UpdateData(FALSE);
	return TRUE;

}

BOOL CClerkMDlg::SetTextState()
{
	CWnd *pWnd;

	if (m_bEdit)
	{
		GetDlgItem(IDC_USERNAME)->EnableWindow(TRUE);
		pWnd = GetDlgItem(IDC_USERID);
		if (m_bAdd)
			pWnd->EnableWindow(TRUE);
		else
			pWnd->EnableWindow(FALSE);
		GetDlgItem(IDC_IDCARD)->EnableWindow(TRUE);
		GetDlgItem(IDC_PASSWORD)->EnableWindow(TRUE);
		GetDlgItem(IDC_POSITION)->EnableWindow(TRUE);

	}
	else
	{
		GetDlgItem(IDC_USERNAME)->EnableWindow(FALSE);
		GetDlgItem(IDC_USERID)->EnableWindow(FALSE);
		GetDlgItem(IDC_IDCARD)->EnableWindow(FALSE);
		GetDlgItem(IDC_PASSWORD)->EnableWindow(FALSE);
		GetDlgItem(IDC_POSITION)->EnableWindow(FALSE);
	}
	if(OFFICIER=="最高管理员")
	{
	GetDlgItem(IDC_USERNAME_Q)->EnableWindow(TRUE);
	GetDlgItem(IDC_USERID_Q)->EnableWindow(TRUE);
	}
	if(OFFICIER=="管理员")
	{
	GetDlgItem(IDC_USERNAME_Q)->EnableWindow(FALSE);
	GetDlgItem(IDC_USERID_Q)->EnableWindow(FALSE);
	}

	return TRUE;

}

BOOL CClerkMDlg::SetButtonState()
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

	if(OFFICIER=="最高管理员")
	{
		GetDlgItem(IDC_NEW)->EnableWindow(TRUE);
		GetDlgItem(IDC_ENQUERY)->EnableWindow(TRUE);
	}
	if(OFFICIER=="管理员")
	{
		GetDlgItem(IDC_NEW)->EnableWindow(FALSE);
		GetDlgItem(IDC_PRIOR)->EnableWindow(FALSE);
		GetDlgItem(IDC_NEXT)->EnableWindow(FALSE);
		GetDlgItem(IDC_ENQUERY)->EnableWindow(FALSE);
		GetDlgItem(IDC_DELETE)->EnableWindow(FALSE);
	}

	GetDlgItem(IDC_SAVE)->EnableWindow(FALSE);
	GetDlgItem(IDC_CANCEL_REC)->EnableWindow(FALSE);


	return TRUE;

}

BOOL CClerkMDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_bAdd = FALSE;
	m_bEdit = FALSE;
	m_cntrPosition.AddString("管理员");
	m_cntrPosition.AddString("最高管理员");
	m_cntrPosition.SetCurSel(0);
	if(type)
	{
		CClerkDataSet m_rsCDataSet;
		m_rsCDataSet.m_strFilter.Format("CLERK_ID='%s'",ID);
		if (!m_rsCDataSet.Open(AFX_DB_USE_DEFAULT_TYPE))
			AfxMessageBox("数据打开失败！");
		m_strUserID = m_rsCDataSet.m_CLERK_ID;
		m_strUserName = m_rsCDataSet.m_NAME;
		m_strIDCard = m_rsCDataSet.m_ID_CARD;
		m_strPassword = m_rsCDataSet.m_PASSWORD ;
		m_cntrPosition.SelectString(1,m_rsCDataSet.m_OFFICIER);
		UpdateData(FALSE);
		m_rsCDataSet.Close();
		if (!m_rsDataSet.Open(AFX_DB_USE_DEFAULT_TYPE))
			AfxMessageBox("数据打开失败！");
	}
	else
	{
		if (!m_rsDataSet.Open(AFX_DB_USE_DEFAULT_TYPE))
			AfxMessageBox("数据打开失败！");
		DisplayRecord();
	}
	SetButtonState();
	SetTextState();
	
		return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

