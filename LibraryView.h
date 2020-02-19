// LibraryView.h : interface of the CLibraryView class
//
/////////////////////////////////////////////////////////////////////////////
#include "BorrowDataSet.h"
#include "BookDataSet.h"	// Added by ClassView
#include "BorrowHistorySet.h" 
#include "ReturnBookDlg.h"
#include "LendOutDlg.h"
#if !defined(AFX_LIBRARYVIEW_H__089C7583_9CC3_4C5E_8F01_CFA22CCB5A5A__INCLUDED_)
#define AFX_LIBRARYVIEW_H__089C7583_9CC3_4C5E_8F01_CFA22CCB5A5A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLibrarySet;

class CLibraryView : public CRecordView
{
protected: // create from serialization only
	CString BOOK_ID;
	CString BOOK_NAME;
	CString BORROW_DATE;
	CString RETURN_DATE;
	CString RETURN_TIME;
	CString Day;
	CString Money;
	CString	AUTHOR;
	CString	PRESS;
	CString	PRESS_DATE;
	CString	FLAG_BORROW;
	CString	BOOK_NUM;
	CString	SURPLUS_NUM;
	CString FLAG;

	CBookDataSet m_BD;
	CBorrowDataSet m_BWD;
	CBorrowHistorySet m_BH;

	CLibraryView();
	DECLARE_DYNCREATE(CLibraryView)

public:
	//{{AFX_DATA(CLibraryView)
	enum { IDD = IDD_LIBRARY_FORM };
	CButton	m_enquery;
	CListCtrl	m_list;
	CLibrarySet* m_pSet;
	CString	m_Info_ID;
	//}}AFX_DATA

// Attributes
public:
	CLibraryDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLibraryView)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	CString User_ID;
	int type;
	virtual ~CLibraryView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLibraryView)
	afx_msg void OnEnquery();
	afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnList1();
	afx_msg void OnList2();
	afx_msg void OnList3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in LibraryView.cpp
inline CLibraryDoc* CLibraryView::GetDocument()
   { return (CLibraryDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIBRARYVIEW_H__089C7583_9CC3_4C5E_8F01_CFA22CCB5A5A__INCLUDED_)
