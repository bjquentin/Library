// ReaderMDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "ReaderMDlg.h"

#include "ReaderDataSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReaderMDlg dialog


CReaderMDlg::CReaderMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReaderMDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReaderMDlg)
	m_strIDCard = _T("");
	m_strReaderID = _T("");
	m_strReaderIDQ = _T("");
	m_strReaderName = _T("");
	m_strReaderNameQ = _T("");
	m_nBorrowNum = 0;
	m_strPassword = _T("");
	//}}AFX_DATA_INIT
}


void CReaderMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReaderMDlg)
	DDX_Control(pDX, IDC_COMBO1, m_Occ);
	DDX_Text(pDX, IDC_IDCARD, m_strIDCard);
	DDV_MaxChars(pDX, m_strIDCard, 18);
	DDX_Text(pDX, IDC_READER_ID, m_strReaderID);
	DDV_MaxChars(pDX, m_strReaderID, 8);
	DDX_Text(pDX, IDC_READER_ID_FOR_Q, m_strReaderIDQ);
	DDV_MaxChars(pDX, m_strReaderIDQ, 8);
	DDX_Text(pDX, IDC_READER_NAME, m_strReaderName);
	DDV_MaxChars(pDX, m_strReaderName, 8);
	DDX_Text(pDX, IDC_READER_NAME_FOR_Q, m_strReaderNameQ);
	DDV_MaxChars(pDX, m_strReaderNameQ, 8);
	DDX_Text(pDX, IDC_BORROW_NUM, m_nBorrowNum);
	DDX_Text(pDX, IDC_PASSWORD, m_strPassword);
	DDV_MaxChars(pDX, m_strPassword, 8);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReaderMDlg, CDialog)
	//{{AFX_MSG_MAP(CReaderMDlg)
	ON_BN_CLICKED(IDC_CANCEL_REC, OnCancelRec)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_EDIT, OnEdit)
	ON_BN_CLICKED(IDC_ENQUERY, OnEnquery)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_PRIOR, OnPrior)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_BN_CLICKED(IDC_NEW, OnNew)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReaderMDlg message handlers


void CReaderMDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}

void CReaderMDlg::OnNew() 
{
	// TODO: Add your control notification handler code here
	m_strReaderID = "";
	m_strReaderName = "";
	m_strIDCard = "";
	m_strPassword = "";
	UpdateData(FALSE);
	m_bEdit = TRUE;
	m_bAdd = TRUE;
	SetButtonState();
	SetTextState();
	GetDlgItem(IDC_READER_NAME_FOR_Q)->EnableWindow(FALSE);
	GetDlgItem(IDC_READER_ID_FOR_Q)->EnableWindow(FALSE);
	GetDlgItem(IDC_READER_NAME)->SetFocus();

}

void CReaderMDlg::OnNext() 
{
	// TODO: Add your control notification handler code here
	if(!m_rsDataSet.IsEOF())
	{
		m_rsDataSet.MoveNext();
		DisplayRecord();
		SetButtonState();
	}
	
}

void CReaderMDlg::OnPrior() 
{
	// TODO: Add your control notification handler code here
	if(!m_rsDataSet.IsBOF())
	{
		m_rsDataSet.MovePrev();
		DisplayRecord();
		SetButtonState();
	}
	
}
void CReaderMDlg::OnSave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_strIDCard.IsEmpty() || m_strReaderName.IsEmpty() || m_strReaderID.IsEmpty())
	{
		AfxMessageBox("请输入相应数据！");
		return;
	}
	if (m_bAdd)
	{
		m_rsDataSet.AddNew();

	}
	else
	{
		m_rsDataSet.Edit();
	}
	m_rsDataSet.m_IDCARD = m_strIDCard;
	m_rsDataSet.m_NAME = m_strReaderName;
	m_rsDataSet.m_READER_ID = m_strReaderID;
	m_rsDataSet.m_FLAG_BORROW  = "Y";
	m_rsDataSet.m_PASSWORD = m_strPassword;
	int nIndex=m_Occ.GetCurSel();
	CString strPosition;
	m_Occ.GetLBText(nIndex,strPosition);
	m_rsDataSet.m_READER_OCC=strPosition;
	if(strPosition==_T("教师"))
	{
		m_rsDataSet.m_MAXNUM_CAN_BORROW=5;
	}
	m_rsDataSet.Update();
	m_rsDataSet.Requery();
	m_bAdd = FALSE;
	m_bEdit = FALSE;
	DisplayRecord();
	SetButtonState();
	SetTextState();
}

void CReaderMDlg::OnCancelRec() 
{
	// TODO: Add your control notification handler code here
	m_bAdd = FALSE;
	m_bEdit = FALSE;
	DisplayRecord();
	SetButtonState();

	SetTextState();
	
}

void CReaderMDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	m_rsDataSet.Delete();
	m_rsDataSet.MoveFirst();
	m_rsDataSet.Requery();
	DisplayRecord();
	SetButtonState();
}

void CReaderMDlg::OnEdit() 
{
	// TODO: Add your control notification handler code here
	m_bEdit = TRUE;
	SetButtonState();
	SetTextState();
	GetDlgItem(IDC_READER_NAME_FOR_Q)->EnableWindow(FALSE);
	GetDlgItem(IDC_READER_ID_FOR_Q)->EnableWindow(FALSE);
	GetDlgItem(IDC_READER_NAME)->SetFocus();
}

void CReaderMDlg::OnEnquery() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_strReaderIDQ.IsEmpty() && m_strReaderNameQ.IsEmpty())
	{
		m_rsDataSet.m_strFilter = "";
		m_rsDataSet.Requery();
		DisplayRecord();
		SetButtonState();
		return;
	}
	BOOL mAll = FALSE;
	if (!m_strReaderIDQ.IsEmpty())
	{
		m_rsDataSet.m_strFilter = "READER_ID='" + m_strReaderIDQ ;
		m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + "'";
		mAll = TRUE;
	}
	if (!m_strReaderNameQ.IsEmpty())
	{
		if (mAll)
		{
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + " AND NAME='";
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + m_strReaderNameQ;
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + "'";
		}
		else
		{
			m_rsDataSet.m_strFilter = "NAME='"  + m_strReaderNameQ;
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + "'";
		}
			
	}
	m_rsDataSet.Requery();
	DisplayRecord();
	SetButtonState();

}

BOOL CReaderMDlg::DisplayRecord()
{	
	if (m_rsDataSet.IsEOF() && m_rsDataSet.IsBOF())	
	{
		m_strReaderID = "";
		m_strReaderName = "";
		m_strIDCard = "";
		m_strPassword = "";
		m_Occ.SelectString(1,"");
	}
	else
	{
		if (m_rsDataSet.IsBOF())
		{
			m_rsDataSet.MoveNext();
		}
		else
		{	
			if (m_rsDataSet.IsEOF())
			{		
				m_rsDataSet.MovePrev();
			}
		}
		m_strReaderID = m_rsDataSet.m_READER_ID;
		m_strReaderName = m_rsDataSet.m_NAME;
		m_strIDCard = m_rsDataSet.m_IDCARD;
		m_strPassword = m_rsDataSet.m_PASSWORD ;
		m_Occ.SelectString(1,m_rsDataSet.m_READER_OCC);
	}
	UpdateData(FALSE);
	return TRUE;

}

BOOL CReaderMDlg::SetButtonState()
{

	if(!m_rsDataSet.IsOpen())
	{
		GetDlgItem(IDC_NEXT)->EnableWindow(FALSE);
		GetDlgItem(IDC_PRIOR)->EnableWindow(FALSE);
		GetDlgItem(IDC_NEW)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_ENQUERY)->EnableWindow(FALSE);
		GetDlgItem(IDC_DELETE)->EnableWindow(FALSE);
		GetDlgItem(IDC_SAVE)->EnableWindow(FALSE);
		GetDlgItem(IDC_CANCEL_REC)->EnableWindow(FALSE);
		return TRUE;
	}


	if (m_bEdit)
	{
		GetDlgItem(IDC_NEXT)->EnableWindow(FALSE);
		GetDlgItem(IDC_PRIOR)->EnableWindow(FALSE);
		GetDlgItem(IDC_NEW)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_ENQUERY)->EnableWindow(FALSE);
		GetDlgItem(IDC_DELETE)->EnableWindow(FALSE);
		GetDlgItem(IDC_SAVE)->EnableWindow(TRUE);
		GetDlgItem(IDC_CANCEL_REC)->EnableWindow(TRUE);
		GetDlgItem(IDC_BORROW_NUM)->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBO1)->EnableWindow(TRUE);
		return TRUE;

	}


	if (m_rsDataSet.IsBOF())
	{
		GetDlgItem(IDC_PRIOR)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_PRIOR)->EnableWindow(TRUE);
	}

	if (m_rsDataSet.IsEOF())
	{
		GetDlgItem(IDC_NEXT)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_NEXT)->EnableWindow(TRUE);

	}
	if (m_rsDataSet.IsBOF() && m_rsDataSet.IsEOF())
	{
		GetDlgItem(IDC_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_DELETE)->EnableWindow(FALSE);

	}
	else
	{
		GetDlgItem(IDC_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_DELETE)->EnableWindow(TRUE);

	}
	if(OCC=="最高管理员"||OCC=="管理员")
	{
	GetDlgItem(IDC_NEW)->EnableWindow(TRUE);
	GetDlgItem(IDC_ENQUERY)->EnableWindow(TRUE);
	GetDlgItem(IDC_SAVE)->EnableWindow(FALSE);
	GetDlgItem(IDC_CANCEL_REC)->EnableWindow(FALSE);
	GetDlgItem(IDC_NEXT)->EnableWindow(TRUE);
	GetDlgItem(IDC_DELETE)->EnableWindow(TRUE);
	GetDlgItem(IDC_PRIOR)->EnableWindow(TRUE);
	}
	else
	{
	GetDlgItem(IDC_NEW)->EnableWindow(FALSE);
	GetDlgItem(IDC_ENQUERY)->EnableWindow(FALSE);
	GetDlgItem(IDC_SAVE)->EnableWindow(FALSE);
	GetDlgItem(IDC_CANCEL_REC)->EnableWindow(FALSE);
	GetDlgItem(IDC_NEXT)->EnableWindow(FALSE);
	GetDlgItem(IDC_DELETE)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRIOR)->EnableWindow(FALSE);
	}
	return TRUE;

}

BOOL CReaderMDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_bAdd = FALSE;
	m_bEdit = FALSE;
	m_Occ.AddString("学生");
	m_Occ.AddString("教师");
	m_Occ.SetCurSel(0);

	if(OCC!="最高管理员"&&OCC!="管理员")
	{
		m_rsDataSet.m_strFilter.Format("READER_ID='%s'",ID);
		if (!m_rsDataSet.Open(AFX_DB_USE_DEFAULT_TYPE))
			AfxMessageBox("数据打开失败！");
	}
	else
	{
		if (!m_rsDataSet.Open(AFX_DB_USE_DEFAULT_TYPE))
			AfxMessageBox("数据打开失败！");
	}
	DisplayRecord();
	SetButtonState();
	SetTextState();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CReaderMDlg::SetTextState()
{
	CWnd *pWnd;

	if (m_bEdit)
	{
		GetDlgItem(IDC_READER_NAME)->EnableWindow(TRUE);
		pWnd = GetDlgItem(IDC_READER_ID);
		if (m_bAdd)
			pWnd->EnableWindow(TRUE);
		else
			pWnd->EnableWindow(FALSE);
		GetDlgItem(IDC_IDCARD)->EnableWindow(TRUE);
		GetDlgItem(IDC_PASSWORD)->EnableWindow(TRUE);

	}
	else
	{
		GetDlgItem(IDC_READER_NAME)->EnableWindow(FALSE);
		GetDlgItem(IDC_READER_ID)->EnableWindow(FALSE);
		GetDlgItem(IDC_IDCARD)->EnableWindow(FALSE);
		GetDlgItem(IDC_PASSWORD)->EnableWindow(FALSE);
		GetDlgItem(IDC_BORROW_NUM)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO1)->EnableWindow(FALSE);

	}
	if(OCC=="最高管理员"||OCC=="管理员")
	{
	GetDlgItem(IDC_READER_NAME_FOR_Q)->EnableWindow(TRUE);
	GetDlgItem(IDC_READER_ID_FOR_Q)->EnableWindow(TRUE);
	}
	else
	{
	GetDlgItem(IDC_READER_NAME_FOR_Q)->EnableWindow(FALSE);
	GetDlgItem(IDC_READER_ID_FOR_Q)->EnableWindow(FALSE);
	}

	return TRUE;

}


