// BorrowHistorySet.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "BorrowHistorySet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBorrowHistorySet

IMPLEMENT_DYNAMIC(CBorrowHistorySet, CRecordset)

CBorrowHistorySet::CBorrowHistorySet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CBorrowHistorySet)
	m_BOOK_ID = _T("");
	m_DAYS = 0;
	m_READER_ID = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CBorrowHistorySet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Library");
}

CString CBorrowHistorySet::GetDefaultSQL()
{
	return _T("[BORROW_HISTORY]");
}

void CBorrowHistorySet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CBorrowHistorySet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[BOOK_ID]"), m_BOOK_ID);
	RFX_Date(pFX, _T("[BORROW_DATE]"), m_BORROW_DATE);
	RFX_Long(pFX, _T("[DAYS]"), m_DAYS);
	RFX_Text(pFX, _T("[READER_ID]"), m_READER_ID);
	RFX_Date(pFX, _T("[RETURN_DATE]"), m_RETURN_DATE);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CBorrowHistorySet diagnostics

#ifdef _DEBUG
void CBorrowHistorySet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CBorrowHistorySet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
