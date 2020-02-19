#if !defined(AFX_FINEDLG_H__EC636ABF_7392_4E33_B2C0_148404E155E2__INCLUDED_)
#define AFX_FINEDLG_H__EC636ABF_7392_4E33_B2C0_148404E155E2__INCLUDED_

#include "BookDataSet.h"
#include "FineDataSet.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FineDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFineDlg dialog

class CFineDlg : public CDialog
{
// Construction
public:
	CFineDlg(CWnd* pParent = NULL);   // standard constructor
	CString MONEY;
	CString DAY;
	float	m_AMOUNT;
	int		m_DAYS;
	CFineDataSet m_rsFineDataSet;
	CBookDataSet m_rsDataSet;
	CString m_ReaderID;
	CString	m_AMOUNT_;
	CString		m_DAYS_;
	CTime	m_FINE_DATE;
	CString	m_BOOK_ID;
	CTime	m_BORROW_DATE;
	CString BOOK_NAME;
	int Day;
	float Money;
	int i;
// Dialog Data
	//{{AFX_DATA(CFineDlg)
	enum { IDD = IDD_FINE };
	CListCtrl	m_book;
	CString	m_strReaderID;
	CString	m_info;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFineDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFineDlg)
	afx_msg void OnExit();
	afx_msg void OnConfirm();
	afx_msg void OnEnquery();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL Inster_Fine_History();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINEDLG_H__EC636ABF_7392_4E33_B2C0_148404E155E2__INCLUDED_)
