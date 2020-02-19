#if !defined(AFX_REGISTERED_H__C5016503_9C9B_4177_8B26_6E10F6BD457A__INCLUDED_)
#define AFX_REGISTERED_H__C5016503_9C9B_4177_8B26_6E10F6BD457A__INCLUDED_

#include "ReaderDataSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Registered.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRegistered dialog

class CRegistered : public CDialog
{
// Construction
public:
	CRegistered(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRegistered)
	enum { IDD = IDD_REGISTERED };
	CComboBox	m_POSITION;
	CString	m_IDCARD;
	CString	m_PASSWORD;
	CString	m_USERID;
	CString	m_USERNAME;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegistered)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRegistered)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTERED_H__C5016503_9C9B_4177_8B26_6E10F6BD457A__INCLUDED_)
