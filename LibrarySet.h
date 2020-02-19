// LibrarySet.h : interface of the CLibrarySet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIBRARYSET_H__F7C11546_6310_4FE3_80B3_F31D0AB5E7D2__INCLUDED_)
#define AFX_LIBRARYSET_H__F7C11546_6310_4FE3_80B3_F31D0AB5E7D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLibrarySet : public CRecordset
{
public:
	CLibrarySet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CLibrarySet)

// Field/Param Data
	//{{AFX_FIELD(CLibrarySet, CRecordset)
	CString	m_AUTHOR;
	CString	m_BOOK_ID;
	CString	m_FLAG_BORROW;
	CString	m_BOOK_NAME;
	long	m_BOOK_NUM;
	CString	m_BOOK_ID2;
	CTime	m_BORROW_DATE;
	long	m_ID;
	CString	m_READER_ID;
	CString	m_BOOK_ID3;
	CTime	m_BORROW_DATE2;
	long	m_DAYS;
	long	m_ID2;
	CString	m_READER_ID2;
	CTime	m_RETURN_DATE;
	long	m_BORROW_NUM;
	CString	m_NAME;
	CString	m_CLERK_ID;
	float	m_AMOUNT;
	CString	m_BOOK_ID4;
	CTime	m_BORROW_DATE3;
	int		m_DAYS2;
	CTime	m_FINE_DATE;
	long	m_ID3;
	CString	m_READER_ID3;
	float	m_AMOUNT2;
	CString	m_BOOK_ID5;
	CTime	m_BORROW_DATE4;
	int		m_DAYS3;
	CTime	m_FINE_DATE2;
	long	m_ID4;
	CString	m_READER_ID4;
	CString	m_BOOK_ID6;
	CTime	m_BORROW_DATE5;
	long	m_ID5;
	CString	m_READER_ID5;
	CTime	m_RETURN_DATE2;
	CString	m_ID_CARD;
	CString	m_IDCARD;
	int		m_MAXNUM_CAN_BORROW;
	CString	m_OFFICIER;
	CTime	m_OK_DATE;
	CString	m_PASSWORD;
	CString	m_PRESS;
	CTime	m_PRESS_DATE;
	CString	m_FLAG_BORROW2;
	CString	m_NAME2;
	CString	m_READER_ID6;
	CString	m_READER_OCC;
	CString	m_READER_PASSWORD;
	long	m_SURPLUS_NUM;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLibrarySet)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIBRARYSET_H__F7C11546_6310_4FE3_80B3_F31D0AB5E7D2__INCLUDED_)

