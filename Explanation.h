#if !defined(AFX_EXPLANATION_H__A8433F32_BD30_4335_B906_EC414B93C704__INCLUDED_)
#define AFX_EXPLANATION_H__A8433F32_BD30_4335_B906_EC414B93C704__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Explanation.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExplanation dialog

class CExplanation : public CDialog
{
// Construction
public:
	CExplanation(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CExplanation)
	enum { IDD = IDD_EXPLANATION };
	CString	m_edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExplanation)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExplanation)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPLANATION_H__A8433F32_BD30_4335_B906_EC414B93C704__INCLUDED_)
