// Registered.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "Registered.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegistered dialog


CRegistered::CRegistered(CWnd* pParent /*=NULL*/)
	: CDialog(CRegistered::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegistered)
	m_IDCARD = _T("");
	m_PASSWORD = _T("");
	m_USERID = _T("");
	m_USERNAME = _T("");
	//}}AFX_DATA_INIT
}


void CRegistered::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegistered)
	DDX_Control(pDX, IDC_POSITION, m_POSITION);
	DDX_Text(pDX, IDC_IDCARD, m_IDCARD);
	DDV_MaxChars(pDX, m_IDCARD, 18);
	DDX_Text(pDX, IDC_PASSWORD, m_PASSWORD);
	DDX_Text(pDX, IDC_USERID, m_USERID);
	DDV_MaxChars(pDX, m_USERID, 8);
	DDX_Text(pDX, IDC_USERNAME, m_USERNAME);
	DDV_MaxChars(pDX, m_USERNAME, 30);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegistered, CDialog)
	//{{AFX_MSG_MAP(CRegistered)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegistered message handlers

BOOL CRegistered::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_POSITION.AddString("学生");
	m_POSITION.AddString("教师");
	m_POSITION.SetCurSel(1);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CRegistered::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	m_USERNAME.TrimLeft();
	m_PASSWORD.TrimLeft();
	m_USERID.TrimLeft();
	m_IDCARD.TrimLeft();
	if (m_USERNAME.IsEmpty()&&m_PASSWORD.IsEmpty()&&m_USERID.IsEmpty()&&m_IDCARD.IsEmpty())
	{
		MessageBox("输入的内容不能为空！");
		return;
	}
	CReaderDataSet m_RD;
	if(!m_RD.Open())
	{
		MessageBox(_T("数据库打开失败！"));
	}
		m_RD.AddNew();
		m_RD.m_NAME=m_USERNAME;
		m_RD.m_PASSWORD=m_PASSWORD;
		m_RD.m_READER_ID=m_USERID;
		m_RD.m_IDCARD=m_IDCARD;
		m_POSITION.SelectString(1,m_RD.m_READER_OCC);
		m_RD.Update();
		m_RD.Requery();
		m_RD.Close();
		MessageBox("注册成功！");
		CDialog::OnOK();
}

void CRegistered::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
