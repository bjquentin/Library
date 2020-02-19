// Choose.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "Choose.h"
#include "Registered.h"
#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChoose dialog


CChoose::CChoose(CWnd* pParent /*=NULL*/)
	: CDialog(CChoose::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChoose)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CChoose::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChoose)
	DDX_Control(pDX, ID_REGISTERED, m_registered);
	DDX_Control(pDX, ID_LOGIN, m_login);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChoose, CDialog)
	//{{AFX_MSG_MAP(CChoose)
	ON_BN_CLICKED(ID_REGISTERED, OnRegistered)
	ON_BN_CLICKED(ID_LOGIN, OnLogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChoose message handlers

void CChoose::OnRegistered() 
{
	// TODO: Add your control notification handler code here
	CRegistered Dlg;
	Dlg.DoModal();
}

void CChoose::OnLogin() 
{
	// TODO: Add your control notification handler code here
	CLoginDlg Dlg;
	Dlg.DoModal();
}


