#if !defined(AFX_CLERKDATASET_H__0374F4B5_4B1A_42AB_A0CA_145DA9A6762A__INCLUDED_)
#define AFX_CLERKDATASET_H__0374F4B5_4B1A_42AB_A0CA_145DA9A6762A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClerkDataSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CClerkDataSet recordset

class CClerkDataSet : public CRecordset
{
public:
	CClerkDataSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CClerkDataSet)

// Field/Param Data
	//{{AFX_FIELD(CClerkDataSet, CRecordset)
	CString	m_CLERK_ID;
	CString	m_NAME;
	CString	m_ID_CARD;
	CString	m_PASSWORD;
	CString	m_OFFICIER;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClerkDataSet)
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

#endif // !defined(AFX_CLERKDATASET_H__0374F4B5_4B1A_42AB_A0CA_145DA9A6762A__INCLUDED_)
