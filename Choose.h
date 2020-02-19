#if !defined(AFX_CHOOSE_H__3BA3AD7A_7618_472F_B9AE_D26E777ACC15__INCLUDED_)
#define AFX_CHOOSE_H__3BA3AD7A_7618_472F_B9AE_D26E777ACC15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Choose.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChoose dialog

class CChoose : public CDialog
{
// Construction
public:
	CChoose(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChoose)
	enum { IDD = IDD_CHOOSE };
	CButton	m_registered;
	CButton	m_login;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChoose)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChoose)
	afx_msg void OnRegistered();
	afx_msg void OnLogin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHOOSE_H__3BA3AD7A_7618_472F_B9AE_D26E777ACC15__INCLUDED_)
