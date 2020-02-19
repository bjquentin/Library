#if !defined(AFX_READERMDLG_H__4F3ADED8_FBD5_4BD5_9D36_DAF90450E752__INCLUDED_)
#define AFX_READERMDLG_H__4F3ADED8_FBD5_4BD5_9D36_DAF90450E752__INCLUDED_

#include "ReaderDataSet.h"	// Added by ClassView

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReaderMDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReaderMDlg dialog

class CReaderMDlg : public CDialog
{
// Construction
public:
	int type;
	CString OCC;
	CString ID;
	BOOL SetTextState();
	BOOL m_bEdit;
	BOOL m_bAdd;
	BOOL SetButtonState();
	BOOL DisplayRecord();
	CReaderDataSet m_rsDataSet;
	CReaderMDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReaderMDlg)
	enum { IDD = IDD_READER };
	CComboBox	m_Occ;
	CString	m_strIDCard;
	CString	m_strReaderID;
	CString	m_strReaderIDQ;
	CString	m_strReaderName;
	CString	m_strReaderNameQ;
	int		m_nBorrowNum;
	CString	m_strPassword;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReaderMDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReaderMDlg)
	afx_msg void OnCancelRec();
	afx_msg void OnDelete();
	afx_msg void OnEdit();
	afx_msg void OnEnquery();
	afx_msg void OnExit();
	afx_msg void OnNext();
	afx_msg void OnPrior();
	afx_msg void OnSave();
	virtual BOOL OnInitDialog();
	afx_msg void OnNew();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READERMDLG_H__4F3ADED8_FBD5_4BD5_9D36_DAF90450E752__INCLUDED_)
