// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__50539930_716F_476D_903F_4D8B11F8893C__INCLUDED_)
#define AFX_MAINFRM_H__50539930_716F_476D_903F_4D8B11F8893C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	int type;
	CString m_strOfficier;
	CString m_strUserID;
	CString m_strUserName;
	BOOL m_bLogin;
	BOOL m_sLogin;
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;
	HICON m_myhIcon;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLoginIn();
	afx_msg void OnLoginOut();
	afx_msg void OnUserMaintain();
	afx_msg void OnBookMaintain();
	afx_msg void OnReaderMaintain();
	afx_msg void OnFine();
	afx_msg void OnLendOut();
	afx_msg void OnReturnBack();
	afx_msg void OnUpdateFine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBookMaintain(CCmdUI* pCmdUI);
	afx_msg void OnUpdateLendOut(CCmdUI* pCmdUI);
	afx_msg void OnUpdateReturnBack(CCmdUI* pCmdUI);
	afx_msg void OnUpdateUserMaintain(CCmdUI* pCmdUI);
	afx_msg void OnUpdateLoginOut(CCmdUI* pCmdUI);
	afx_msg void OnUpdateReaderMaintain(CCmdUI* pCmdUI);
	afx_msg void OnExplanation();
	afx_msg void OnRegisitered();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__50539930_716F_476D_903F_4D8B11F8893C__INCLUDED_)
