#if !defined(AFX_LENDOUTDLG_H__A4141A34_E1D5_435D_AB33_4623C9EA1689__INCLUDED_)
#define AFX_LENDOUTDLG_H__A4141A34_E1D5_435D_AB33_4623C9EA1689__INCLUDED_

#include "BorrowDataSet.h"	// Added by ClassView
#include "ReaderDataSet.h"	// Added by ClassView
#include "BookDataSet.h"	// Added by ClassView

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LendOutDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLendOutDlg dialog

class CLendOutDlg : public CDialog
{
// Construction
public:
	BOOL Inster_Borrow();
	CBookDataSet m_rsBookDataSet;
	CBookDataSet m_rsBookSet;
	CReaderDataSet m_rsReaderDataSet;
	CBorrowDataSet m_rsBorrowDataSet;
	CLendOutDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLendOutDlg)
	enum { IDD = IDD_LENDOUT };
	CString	m_strBookID;
	CString	m_strReaderID;
	CString	m_strBookNAME;
	CString	m_strAuthor;
	CString	m_strBookId;
	CString	m_strFlag;
	CString	m_strPress;
	CString	m_strPressDate;
	long	m_nSurplusNum;
	long	m_nBookNum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLendOutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLendOutDlg)
	afx_msg void OnCancel();
	afx_msg void OnConfirm();
	virtual BOOL OnInitDialog();
	afx_msg void OnEnquery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL SetTxtNull();
	BOOL setTxtDisable();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LENDOUTDLG_H__A4141A34_E1D5_435D_AB33_4623C9EA1689__INCLUDED_)
