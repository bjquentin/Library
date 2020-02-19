// LibrarySet.cpp : implementation of the CLibrarySet class
//

#include "stdafx.h"
#include "Library.h"
#include "LibrarySet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLibrarySet implementation

IMPLEMENT_DYNAMIC(CLibrarySet, CRecordset)

CLibrarySet::CLibrarySet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CLibrarySet)
	m_AUTHOR = _T("");
	m_BOOK_ID = _T("");
	m_FLAG_BORROW = _T("");
	m_BOOK_NAME = _T("");
	m_BOOK_NUM = 0;
	m_BOOK_ID2 = _T("");
	m_ID = 0;
	m_READER_ID = _T("");
	m_BOOK_ID3 = _T("");
	m_DAYS = 0;
	m_ID2 = 0;
	m_READER_ID2 = _T("");
	m_BORROW_NUM = 0;
	m_NAME = _T("");
	m_CLERK_ID = _T("");
	m_AMOUNT = 0.0f;
	m_BOOK_ID4 = _T("");
	m_DAYS2 = 0;
	m_ID3 = 0;
	m_READER_ID3 = _T("");
	m_AMOUNT2 = 0.0f;
	m_BOOK_ID5 = _T("");
	m_DAYS3 = 0;
	m_ID4 = 0;
	m_READER_ID4 = _T("");
	m_BOOK_ID6 = _T("");
	m_ID5 = 0;
	m_READER_ID5 = _T("");
	m_ID_CARD = _T("");
	m_IDCARD = _T("");
	m_MAXNUM_CAN_BORROW = 0;
	m_OFFICIER = _T("");
	m_PASSWORD = _T("");
	m_PRESS = _T("");
	m_FLAG_BORROW2 = _T("");
	m_NAME2 = _T("");
	m_READER_ID6 = _T("");
	m_READER_OCC = _T("");
	m_READER_PASSWORD = _T("");
	m_SURPLUS_NUM = 0;
	m_nFields = 51;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}

CString CLibrarySet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Library");
}

CString CLibrarySet::GetDefaultSQL()
{
	return _T("[BOOK],[BORROW],[CLERK],[FINE],[FINE_HISTORY],[HISTORY],[READER],[BORROW_HISTORY]");
}

void CLibrarySet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CLibrarySet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[AUTHOR]"), m_AUTHOR);
	RFX_Text(pFX, _T("[BOOK].[BOOK_ID]"), m_BOOK_ID);
	RFX_Text(pFX, _T("[BOOK].[FLAG_BORROW]"), m_FLAG_BORROW);
	RFX_Text(pFX, _T("[BOOK_NAME]"), m_BOOK_NAME);
	RFX_Long(pFX, _T("[BOOK_NUM]"), m_BOOK_NUM);
	RFX_Text(pFX, _T("[BORROW].[BOOK_ID]"), m_BOOK_ID2);
	RFX_Date(pFX, _T("[BORROW].[BORROW_DATE]"), m_BORROW_DATE);
	RFX_Long(pFX, _T("[BORROW].[ID]"), m_ID);
	RFX_Text(pFX, _T("[BORROW].[READER_ID]"), m_READER_ID);
	RFX_Text(pFX, _T("[BORROW_HISTORY].[BOOK_ID]"), m_BOOK_ID3);
	RFX_Date(pFX, _T("[BORROW_HISTORY].[BORROW_DATE]"), m_BORROW_DATE2);
	RFX_Long(pFX, _T("[BORROW_HISTORY].[DAYS]"), m_DAYS);
	RFX_Long(pFX, _T("[BORROW_HISTORY].[ID]"), m_ID2);
	RFX_Text(pFX, _T("[BORROW_HISTORY].[READER_ID]"), m_READER_ID2);
	RFX_Date(pFX, _T("[BORROW_HISTORY].[RETURN_DATE]"), m_RETURN_DATE);
	RFX_Long(pFX, _T("[BORROW_NUM]"), m_BORROW_NUM);
	RFX_Text(pFX, _T("[CLERK].[NAME]"), m_NAME);
	RFX_Text(pFX, _T("[CLERK_ID]"), m_CLERK_ID);
	RFX_Single(pFX, _T("[FINE].[AMOUNT]"), m_AMOUNT);
	RFX_Text(pFX, _T("[FINE].[BOOK_ID]"), m_BOOK_ID4);
	RFX_Date(pFX, _T("[FINE].[BORROW_DATE]"), m_BORROW_DATE3);
	RFX_Int(pFX, _T("[FINE].[DAYS]"), m_DAYS2);
	RFX_Date(pFX, _T("[FINE].[FINE_DATE]"), m_FINE_DATE);
	RFX_Long(pFX, _T("[FINE].[ID]"), m_ID3);
	RFX_Text(pFX, _T("[FINE].[READER_ID]"), m_READER_ID3);
	RFX_Single(pFX, _T("[FINE_HISTORY].[AMOUNT]"), m_AMOUNT2);
	RFX_Text(pFX, _T("[FINE_HISTORY].[BOOK_ID]"), m_BOOK_ID5);
	RFX_Date(pFX, _T("[FINE_HISTORY].[BORROW_DATE]"), m_BORROW_DATE4);
	RFX_Int(pFX, _T("[FINE_HISTORY].[DAYS]"), m_DAYS3);
	RFX_Date(pFX, _T("[FINE_HISTORY].[FINE_DATE]"), m_FINE_DATE2);
	RFX_Long(pFX, _T("[FINE_HISTORY].[ID]"), m_ID4);
	RFX_Text(pFX, _T("[FINE_HISTORY].[READER_ID]"), m_READER_ID4);
	RFX_Text(pFX, _T("[HISTORY].[BOOK_ID]"), m_BOOK_ID6);
	RFX_Date(pFX, _T("[HISTORY].[BORROW_DATE]"), m_BORROW_DATE5);
	RFX_Long(pFX, _T("[HISTORY].[ID]"), m_ID5);
	RFX_Text(pFX, _T("[HISTORY].[READER_ID]"), m_READER_ID5);
	RFX_Date(pFX, _T("[HISTORY].[RETURN_DATE]"), m_RETURN_DATE2);
	RFX_Text(pFX, _T("[ID_CARD]"), m_ID_CARD);
	RFX_Text(pFX, _T("[IDCARD]"), m_IDCARD);
	RFX_Int(pFX, _T("[MAXNUM_CAN_BORROW]"), m_MAXNUM_CAN_BORROW);
	RFX_Text(pFX, _T("[OFFICIER]"), m_OFFICIER);
	RFX_Date(pFX, _T("[OK_DATE]"), m_OK_DATE);
	RFX_Text(pFX, _T("[PASSWORD]"), m_PASSWORD);
	RFX_Text(pFX, _T("[PRESS]"), m_PRESS);
	RFX_Date(pFX, _T("[PRESS_DATE]"), m_PRESS_DATE);
	RFX_Text(pFX, _T("[READER].[FLAG_BORROW]"), m_FLAG_BORROW2);
	RFX_Text(pFX, _T("[READER].[NAME]"), m_NAME2);
	RFX_Text(pFX, _T("[READER].[READER_ID]"), m_READER_ID6);
	RFX_Text(pFX, _T("[READER_OCC]"), m_READER_OCC);
	RFX_Text(pFX, _T("[READER_PASSWORD]"), m_READER_PASSWORD);
	RFX_Long(pFX, _T("[SURPLUS_NUM]"), m_SURPLUS_NUM);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CLibrarySet diagnostics

#ifdef _DEBUG
void CLibrarySet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CLibrarySet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
