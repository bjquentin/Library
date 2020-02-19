#if !defined(AFX_FINEDATASET_H__A8A6230A_9860_4CE2_8DC8_B83E2B8744D7__INCLUDED_)
#define AFX_FINEDATASET_H__A8A6230A_9860_4CE2_8DC8_B83E2B8744D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FineDataSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFineDataSet recordset

class CFineDataSet : public CRecordset
{
public:
	CFineDataSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CFineDataSet)

// Field/Param Data
	//{{AFX_FIELD(CFineDataSet, CRecordset)
	float	m_AMOUNT;
	CString	m_BOOK_ID;
	CTime	m_BORROW_DATE;
	int		m_DAYS;
	CTime	m_FINE_DATE;
	long	m_ID;
	CString	m_READER_ID;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFineDataSet)
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

#endif // !defined(AFX_FINEDATASET_H__A8A6230A_9860_4CE2_8DC8_B83E2B8744D7__INCLUDED_)
