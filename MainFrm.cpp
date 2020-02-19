// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Library.h"

#include "MainFrm.h"

#include "LoginDlg.h"
#include "ClerkMDlg.h"
#include "BookMDlg.h"
#include "ReaderMDlg.h"

#include "LendOutDlg.h"
#include "ReturnBookDlg.h"
#include "FineDlg.h"

#include "Explanation.h"
#include "Registered.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_LOGIN_IN, OnLoginIn)
	ON_COMMAND(ID_LOGIN_OUT, OnLoginOut)
	ON_COMMAND(ID_USER_MAINTAIN, OnUserMaintain)
	ON_COMMAND(ID_BOOK_MAINTAIN, OnBookMaintain)
	ON_COMMAND(ID_READER_MAINTAIN, OnReaderMaintain)
	ON_COMMAND(ID_FINE, OnFine)
	ON_COMMAND(ID_LEND_OUT, OnLendOut)
	ON_COMMAND(ID_RETURN_BACK, OnReturnBack)
	ON_UPDATE_COMMAND_UI(ID_FINE, OnUpdateFine)
	ON_UPDATE_COMMAND_UI(ID_BOOK_MAINTAIN, OnUpdateBookMaintain)
	ON_UPDATE_COMMAND_UI(ID_LEND_OUT, OnUpdateLendOut)
	ON_UPDATE_COMMAND_UI(ID_RETURN_BACK, OnUpdateReturnBack)
	ON_UPDATE_COMMAND_UI(ID_USER_MAINTAIN, OnUpdateUserMaintain)
	ON_UPDATE_COMMAND_UI(ID_LOGIN_OUT, OnUpdateLoginOut)
	ON_UPDATE_COMMAND_UI(ID_READER_MAINTAIN, OnUpdateReaderMaintain)
	ON_COMMAND(ID_EXPLANATION, OnExplanation)
	ON_COMMAND(ID_REGISITERED, OnRegisitered)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	m_bLogin = FALSE;
	m_sLogin = FALSE;
	type=3;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	m_myhIcon = AfxGetApp()->LoadIcon(IDI_ICON1);

    SetIcon(m_myhIcon, true);

    SetIcon(m_myhIcon, false);
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnLoginIn() 
{
	// TODO: Add your command handler code here
	CLoginDlg mDlg;
	if (mDlg.DoModal() == IDOK)
	{
		m_bLogin = TRUE;
		m_strUserName = mDlg.m_strName ;
		m_strUserID = mDlg.m_strUSERID;
		m_strOfficier=mDlg.m_strOfficier;
		type=mDlg.type;
		if(type)
		m_sLogin=TRUE;
	}
	else
	{
		m_bLogin = FALSE;
		m_strUserName = _T("");
		m_strUserID = _T("");
		m_strOfficier=_T("游客");
	}
	
	CString Name;
	Name.Format("%s : %s 欢迎您！",m_strOfficier,m_strUserName);
	m_wndStatusBar.SetPaneText(0,Name);
}
void CMainFrame::OnLoginOut() 
{
	// TODO: Add your command handler code here
	m_bLogin = FALSE;
	m_strUserName = _T("");	
	m_strUserID = _T("");
	m_strOfficier=_T("游客");
	type=0;

	CString Name;
	Name = "当前用户：" +m_strOfficier+  m_strUserName;
	m_wndStatusBar.SetPaneText(0,Name);
}

void CMainFrame::OnUserMaintain() 
{
	// TODO: Add your command handler code here
	CClerkMDlg mDlg;
	mDlg.ID=m_strUserID;
	mDlg.OFFICIER=m_strOfficier;
	mDlg.type=type;
	mDlg.DoModal();
}

void CMainFrame::OnBookMaintain() 
{
	// TODO: Add your command handler code here
	CBookMDlg mDlg;
	mDlg.DoModal();
}

void CMainFrame::OnReaderMaintain() 
{
	// TODO: Add your command handler code here
	CReaderMDlg mDlg;
	mDlg.ID=m_strUserID;
	mDlg.OCC=m_strOfficier;
	mDlg.type=type;
	mDlg.DoModal();
}

void CMainFrame::OnFine() 
{
	// TODO: Add your command handler code here
	CFineDlg mDlg;
	mDlg.DoModal();
}

void CMainFrame::OnLendOut() 
{
	// TODO: Add your command handler code here
	CLendOutDlg mDlg;
	mDlg.DoModal();
}

void CMainFrame::OnReturnBack() 
{
	// TODO: Add your command handler code here
	CReturnBookDlg  mDlg;
	mDlg.DoModal();
}



void CMainFrame::OnUpdateFine(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_sLogin);
}

void CMainFrame::OnUpdateBookMaintain(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_sLogin);
}

void CMainFrame::OnUpdateLendOut(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bLogin);
}

void CMainFrame::OnUpdateReturnBack(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_sLogin);
}

void CMainFrame::OnUpdateUserMaintain(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_sLogin);

}

void CMainFrame::OnUpdateLoginOut(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bLogin);
}

void CMainFrame::OnUpdateReaderMaintain(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bLogin);
}

void CMainFrame::OnExplanation() 
{
	// TODO: Add your command handler code here
	CExplanation dlg;
	dlg.DoModal();
}



void CMainFrame::OnRegisitered() 
{
	// TODO: Add your command handler code here
	CRegistered Dlg;
	Dlg.DoModal();
}
