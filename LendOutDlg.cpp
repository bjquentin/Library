// LendOutDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "LendOutDlg.h"

#include "BorrowDataSet.h"
#include "ReaderDataSet.h"
#include "BookDataSet.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLendOutDlg dialog


CLendOutDlg::CLendOutDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLendOutDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLendOutDlg)
	m_strBookID = _T("");
	m_strReaderID = _T("");
	m_strBookNAME = _T("");
	m_strAuthor = _T("");
	m_strBookId = _T("");
	m_strFlag = _T("");
	m_strPress = _T("");
	m_strPressDate = _T("");
	m_nSurplusNum = 0;
	m_nBookNum = 0;
	//}}AFX_DATA_INIT
}


void CLendOutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLendOutDlg)
	DDX_Text(pDX, IDC_BOOK_ID, m_strBookID);
	DDV_MaxChars(pDX, m_strBookID, 8);
	DDX_Text(pDX, IDC_READER_ID, m_strReaderID);
	DDV_MaxChars(pDX, m_strReaderID, 8);
	DDX_Text(pDX, IDC_BOOKNAME, m_strBookNAME);
	DDX_Text(pDX, IDC_AUTHOR, m_strAuthor);
	DDX_Text(pDX, IDC_BOOKID, m_strBookId);
	DDX_Text(pDX, IDC_FLAG_BORROW, m_strFlag);
	DDX_Text(pDX, IDC_PRESS, m_strPress);
	DDX_Text(pDX, IDC_PRESSDATE, m_strPressDate);
	DDX_Text(pDX, IDC_SURPLUS_NUM, m_nSurplusNum);
	DDX_Text(pDX, IDC_BOOK_NUM, m_nBookNum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLendOutDlg, CDialog)
	//{{AFX_MSG_MAP(CLendOutDlg)
	ON_BN_CLICKED(IDC_CONFIRM, OnConfirm)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	ON_BN_CLICKED(IDC_ENQUERY, OnEnquery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLendOutDlg message handlers

void CLendOutDlg::OnCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

void CLendOutDlg::OnConfirm() 
{
	// TODO: Add your control notification handler code here
	BOOL m_bCanBorrow;
	BOOL m_bCanLendOut;
	m_bCanBorrow = FALSE;
	m_bCanLendOut = FALSE;

	UpdateData(TRUE);

	if (!m_rsReaderDataSet.Open())
	{
		AfxMessageBox("数据表打开错误!");
		return;
	}
	m_rsReaderDataSet.m_strFilter="READER_ID='"+m_strReaderID+"'";
	m_rsReaderDataSet.Requery();

	if (!m_rsReaderDataSet.IsEOF())
	{
		if (m_rsReaderDataSet.m_FLAG_BORROW == _T("Y"))
		{
			m_bCanBorrow = TRUE;
		}
		else 
		{
			m_bCanBorrow = FALSE;
		}
		if(m_rsReaderDataSet.m_MAXNUM_CAN_BORROW>m_rsReaderDataSet.m_BORROW_NUM)
		{
			m_bCanBorrow = TRUE;
		}
		else
		{
			m_rsReaderDataSet.Edit();
			m_rsReaderDataSet.m_FLAG_BORROW=_T("F");
			m_bCanBorrow = FALSE;
		}
	}

	m_rsReaderDataSet.Close();
	if (!m_bCanBorrow)
	{
		AfxMessageBox("读者不能借书！请及时还书或立即清空违约金");
		m_rsReaderDataSet.Close();
		return;
	}
	
	if(!m_rsBookDataSet.Open())
	{
		AfxMessageBox("数据表打开错误！");
		return ;
	}
	m_rsBookDataSet.m_strFilter.Format("BOOK_ID='%s'",m_strBookID);	
	m_rsBookDataSet.Requery();
	if (!m_rsBookDataSet.IsEOF())
	{
		CString Judge;
		long Surplus_num;
		Judge=m_rsBookDataSet.m_FLAG_BORROW;
		Surplus_num=m_rsBookDataSet.m_SURPLUS_NUM;
		if (Judge == _T("Y"))
		{
			m_bCanLendOut = TRUE;
		}
		else
		{
			m_bCanLendOut = FALSE;
			AfxMessageBox("此书不外借！ ");
		}
		if (Surplus_num > 0)
		{
			m_bCanLendOut = TRUE;
		}
		else
		{
			m_bCanLendOut = FALSE;
			AfxMessageBox("该书已经借完！ ");
		}
		m_rsBookDataSet.Close();
	}
 	else
	{
		AfxMessageBox("无此书！");
		m_rsBookDataSet.Close();
	}
    if(m_bCanLendOut)
	{
		if(Inster_Borrow())
		{
			AfxMessageBox("借书成功！");

			if (!m_rsReaderDataSet.Open())
			{
				AfxMessageBox("数据表打开错误!");
				return;
			}
			m_rsReaderDataSet.m_strFilter="READER_ID='"+m_strReaderID+"'";
			m_rsReaderDataSet.Requery();
			m_rsReaderDataSet.Edit();
			m_rsReaderDataSet.m_BORROW_NUM++;
			m_rsReaderDataSet.Update();
			m_rsReaderDataSet.Requery();
			m_rsReaderDataSet.Close();

			if(!m_rsBookDataSet.Open())
			{
				AfxMessageBox("数据表打开错误！");
				return ;
			}
			m_rsBookDataSet.m_strFilter="BOOK_ID='"+m_strBookID+"'";
			m_rsBookDataSet.Requery();
			m_rsBookDataSet.Edit();
			m_rsBookDataSet.m_SURPLUS_NUM--;
			m_rsBookDataSet.Update();
			m_rsBookDataSet.Requery();
			m_rsBookDataSet.Close();
			SetTxtNull();
		}

	}
	return ;
}

BOOL CLendOutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	setTxtDisable();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLendOutDlg::OnEnquery() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	GetDlgItem(IDC_CONFIRM)->EnableWindow(true);
	if (!m_strReaderID.IsEmpty() && !m_strBookID.IsEmpty())
	{
		m_rsBookSet.m_strFilter = "BOOK_ID='"+m_strBookID+"'";
		if (!m_rsBookSet.Open())
		{
			AfxMessageBox("数据打开失败！");
		}
	
		m_rsBookSet.Requery();
	}
	else
	{
		AfxMessageBox("读者ID，图书ID不能为空！！");
		return;
	}
	
	if (m_rsBookSet.GetRecordCount()!=0) 
	{
		m_strBookId = m_rsBookSet.m_BOOK_ID;
		m_strBookNAME = m_rsBookSet.m_BOOK_NAME;
		m_strPress = m_rsBookSet.m_PRESS;
		m_strPressDate = m_rsBookSet.m_PRESS_DATE.Format("%Y年%m月%d日");
		m_strAuthor = m_rsBookSet.m_AUTHOR ;
		m_strFlag = m_rsBookSet.m_FLAG_BORROW ;
		m_nBookNum=m_rsBookSet.m_BOOK_NUM;
		m_nSurplusNum=m_rsBookSet.m_SURPLUS_NUM;
	}
	else
	{
		AfxMessageBox("无此书！");
		m_rsBookSet.Close();
		return;
	}
	m_rsBookSet.Close();
	UpdateData(FALSE);
}

BOOL CLendOutDlg::setTxtDisable()
{
	GetDlgItem(IDC_AUTHOR)->EnableWindow(false);
	GetDlgItem(IDC_BOOKID)->EnableWindow(false);
	GetDlgItem(IDC_BOOKNAME)->EnableWindow(false);
	GetDlgItem(IDC_FLAG_BORROW)->EnableWindow(false);
	GetDlgItem(IDC_PRESS)->EnableWindow(false);
	GetDlgItem(IDC_PRESSDATE)->EnableWindow(false);
	GetDlgItem(IDC_CONFIRM)->EnableWindow(false);
	GetDlgItem(IDC_BOOK_NUM)->EnableWindow(false);
	GetDlgItem(IDC_SURPLUS_NUM)->EnableWindow(false);
	return TRUE;
}

BOOL CLendOutDlg::SetTxtNull()
{
	m_strAuthor="";
	m_strBookId="";
	m_strBookNAME="";
	m_strFlag="";
	m_strPress="";
	m_strPressDate="";
	m_nBookNum=0;
	m_nSurplusNum=0;
	UpdateData(false);
	GetDlgItem(IDC_READER_ID)->SetFocus();
	return TRUE;
}

BOOL CLendOutDlg::Inster_Borrow()
{
	UpdateData();
	if(!m_rsBorrowDataSet.Open())
	{
		AfxMessageBox("数据表打开错误！");
		return FALSE;
	}
	m_rsBorrowDataSet.AddNew();
	m_rsBorrowDataSet.m_BOOK_ID=m_strBookId;
	//m_rsBorrowDataSet.m_BOOK_NAME=m_strBookNAME;
	m_rsBorrowDataSet.m_BORROW_DATE=CTime::GetCurrentTime();
	m_rsBorrowDataSet.m_READER_ID=m_strReaderID;
	m_rsBorrowDataSet.Update();
	m_rsBorrowDataSet.Requery();
	m_rsBorrowDataSet.Close();
	return TRUE;
}
