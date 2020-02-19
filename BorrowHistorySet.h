#if !defined(AFX_BORROWHISTORYSET_H__9469ED55_7903_42F3_A6C1_6BEB79765214__INCLUDED_)
#define AFX_BORROWHISTORYSET_H__9469ED55_7903_42F3_A6C1_6BEB79765214__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BorrowHistorySet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBorrowHistorySet recordset

class CBorrowHistorySet : public CRecordset
{
public:
	CBorrowHistorySet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CBorrowHistorySet)

// Field/Param Data
	//{{AFX_FIELD(CBorrowHistorySet, CRecordset)
	CString	m_BOOK_ID;
	CTime	m_BORROW_DATE;
	long	m_DAYS;
	CString	m_READER_ID;
	CTime	m_RETURN_DATE;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBorrowHistorySet)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BORROWHISTORYSET_H__9469ED55_7903_42F3_A6C1_6BEB79765214__INCLUDED_)
