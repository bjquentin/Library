#if !defined(AFX_FINEDETAIL_H__567B0A64_3ED4_40DC_967E_4984ECC17B97__INCLUDED_)
#define AFX_FINEDETAIL_H__567B0A64_3ED4_40DC_967E_4984ECC17B97__INCLUDED_

#include "BookDataSet.h"
#include "FineDataSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FineDetail.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFineDetail dialog

class CFineDetail : public CDialog
{
// Construction
public:
	CFineDetail(CWnd* pParent = NULL);   // standard constructor
	CFineDataSet m_rsFineDataSet;
	CBookDataSet m_rsDataSet;
	CString m_ReaderID;
	CString	m_AMOUNT;
	CString		m_DAYS;
	CTime	m_FINE_DATE;
	CString	m_BOOK_ID;
	CTime	m_BORROW_DATE;
	CString BOOK_NAME;
	CString DAYS;
	CString MONEY;
	int i;
// Dialog Data
	//{{AFX_DATA(CFineDetail)
	enum { IDD = IDD_Finedetail };
	CListCtrl	m_book;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFineDetail)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFineDetail)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINEDETAIL_H__567B0A64_3ED4_40DC_967E_4984ECC17B97__INCLUDED_)
