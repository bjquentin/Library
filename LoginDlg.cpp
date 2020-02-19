// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "LoginDlg.h"

#include "ClerkDataSet.h"
#include "ReaderDataSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
	m_strPassword = _T("");
	m_strID = _T("");
	//}}AFX_DATA_INIT
	m_bSuccess = FALSE;
	m_strName = _T("");
	m_strOfficier=_T("");

}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
	DDX_Control(pDX, IDC_COMBO1, m_type);
	DDX_Text(pDX, IDC_LOGIN_PASSWORD, m_strPassword);
	DDV_MaxChars(pDX, m_strPassword, 8);
	DDX_Text(pDX, IDC_LOGIN_ID, m_strID);
	DDV_MaxChars(pDX, m_strID, 8);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	ON_BN_CLICKED(IDC_CONFIRM, OnConfirm)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers
void CLoginDlg::OnConfirm() 
{
	// TODO: Add your control notification handler code here
	CClerkDataSet mrsDataSet;  /*声明记录集*/
	CReaderDataSet mrsRDataSet;
	UpdateData(TRUE);

	if (m_strID.IsEmpty())    /*判断用户名信息是否为空*/
	{
		AfxMessageBox("请输入用户ID！");
		return;
	}
    type=m_type.GetCurSel();
	if (type)
	{
		mrsDataSet.m_strFilter ="CLERK_ID='"+m_strID+"' and PASSWORD='"+m_strPassword+"'";


		if (!mrsDataSet.Open( ))
		{
			AfxMessageBox("表打开失败！");
			return;
		}
		if (!mrsDataSet.IsEOF())
		{
			// Open all function for user
			m_bSuccess = TRUE;
			m_strUSERID = mrsDataSet.m_CLERK_ID ;
			m_strName=mrsDataSet.m_NAME ;
			m_strOfficier=mrsDataSet.m_OFFICIER;
			CDialog::OnOK();
		}
		else
		{
			AfxMessageBox("登录失败！");
			m_strName = _T("");
			m_strOfficier=_T("");
			return;
		}
	}
	else
	{
		mrsRDataSet.m_strFilter ="READER_ID='"+m_strID+"' and READER_PASSWORD='"+m_strPassword+"'";
		if (!mrsRDataSet.Open())
		{
			AfxMessageBox("表打开失败！");
			return;
		}
		if (!mrsRDataSet.IsEOF())
		{
			m_bSuccess = TRUE;
			m_strUSERID = mrsRDataSet.m_READER_ID ;
			m_strName=mrsRDataSet.m_NAME ;
			m_strOfficier=mrsRDataSet.m_READER_OCC;
			CDialog::OnOK();
		}
		else
		{
			AfxMessageBox("登录失败！");
			m_strName = _T("");
			m_strOfficier=_T("");
			return;
		}
	
	}
	
}

void CLoginDlg::OnCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();	
}


BOOL CLoginDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_type.AddString("读者");
	m_type.AddString("管理员");
	m_type.SetCurSel(0);
	GetDlgItem(IDC_LOGIN_ID)->SetFocus();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
