#if !defined(AFX_BOOKDATASET_H__43ACA975_D2F1_4CEB_B7CC_B8A23D53739F__INCLUDED_)
#define AFX_BOOKDATASET_H__43ACA975_D2F1_4CEB_B7CC_B8A23D53739F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BookDataSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBookDataSet recordset

class CBookDataSet : public CRecordset
{
public:
	CBookDataSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CBookDataSet)

// Field/Param Data
	//{{AFX_FIELD(CBookDataSet, CRecordset)
	CString	m_BOOK_ID;
	CString	m_BOOK_NAME;
	CString	m_AUTHOR;
	CString	m_PRESS;
	CTime	m_PRESS_DATE;
	CString	m_FLAG_BORROW;
	long	m_BOOK_NUM;
	long	m_SURPLUS_NUM;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookDataSet)
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

#endif // !defined(AFX_BOOKDATASET_H__43ACA975_D2F1_4CEB_B7CC_B8A23D53739F__INCLUDED_)
