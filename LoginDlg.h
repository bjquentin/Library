#if !defined(AFX_LOGINDLG_H__E21CCC85_6DA6_452C_AEE8_2A2A2B3A44B3__INCLUDED_)
#define AFX_LOGINDLG_H__E21CCC85_6DA6_452C_AEE8_2A2A2B3A44B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog

class CLoginDlg : public CDialog
{
// Construction
public:
	int type;
	CString m_strOfficier;
	CString m_strName;
	void OnCancel();
	void OnConfirm();
	CString m_strUSERID;
	BOOL m_bSuccess;
	CLoginDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLoginDlg)
	enum { IDD = IDD_LOGIN };
	CComboBox	m_type;
	CString	m_strPassword;
	CString	m_strID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLoginDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINDLG_H__E21CCC85_6DA6_452C_AEE8_2A2A2B3A44B3__INCLUDED_)
