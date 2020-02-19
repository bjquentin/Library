#if !defined(AFX_RETURNBOOKDLG_H__57DF57CA_238C_4A87_8DB4_984E4C87CDB6__INCLUDED_)
#define AFX_RETURNBOOKDLG_H__57DF57CA_238C_4A87_8DB4_984E4C87CDB6__INCLUDED_

#include "BorrowSet.h"	// Added by ClassView
#include "BookDataSet.h"	// Added by ClassView
#include "BorrowDataSet.h"	// Added by ClassView
#include "ReaderDataSet.h"	// Added by ClassView
#include "BorrowHistorySet.h"
#include "BorrowDataSet.h"	// Added by ClassView

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReturnBookDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReturnBookDlg dialog

class CReturnBookDlg : public CDialog
{
// Construction
public:
	BOOL Inset_Borrow_History();
	BOOL Process();
	BOOL Insert_Fine();
	CBorrowSet m_rsDataSet;
	CBorrowDataSet m_rsBorrowDataSet;
	CBookDataSet m_rsBOOKNAMESet;
	CBorrowHistorySet m_rsBorrowHDataSet;
	CReturnBookDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReturnBookDlg)
	enum { IDD = IDD_ReturnBook };
	CString	m_Book_ID;
	CString	m_BorrowDate;
	int		m_Days;
	CString	m_ReaderName;
	CString	m_ReturnDate;
	CString	m_Reader_ID;
	CString	m_BOOK_NAME;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReturnBookDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReturnBookDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnEnquery();
	afx_msg void OnConfirm();
	afx_msg void OnAppExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL Insert_History();
	BOOL SetTxtNull();
	BOOL setTxtDisable();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RETURNBOOKDLG_H__57DF57CA_238C_4A87_8DB4_984E4C87CDB6__INCLUDED_)
