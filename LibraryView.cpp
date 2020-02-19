// LibraryView.cpp : implementation of the CLibraryView class
//

#include "stdafx.h"
#include "Library.h"

#include "LibrarySet.h"
#include "LibraryDoc.h"
#include "LibraryView.h"
#include "MainFrm.h"
#include "Choose.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BOOL IS=FALSE;
/////////////////////////////////////////////////////////////////////////////
// CLibraryView

IMPLEMENT_DYNCREATE(CLibraryView, CRecordView)

BEGIN_MESSAGE_MAP(CLibraryView, CRecordView)
	//{{AFX_MSG_MAP(CLibraryView)
	ON_BN_CLICKED(IDC_ENQUERY, OnEnquery)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, OnDblclkList)
	ON_BN_CLICKED(IDC_LIST1, OnList1)
	ON_BN_CLICKED(IDC_LIST2, OnList2)
	ON_BN_CLICKED(IDC_LIST3, OnList3)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLibraryView construction/destruction

CLibraryView::CLibraryView()
	: CRecordView(CLibraryView::IDD)
{
	//{{AFX_DATA_INIT(CLibraryView)
	m_pSet = NULL;
	m_Info_ID = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CLibraryView::~CLibraryView()
{
}

void CLibraryView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLibraryView)
	DDX_Control(pDX, IDC_ENQUERY, m_enquery);
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Text(pDX, IDC_INFO_ID, m_Info_ID);
	DDV_MaxChars(pDX, m_Info_ID, 8);
	//}}AFX_DATA_MAP
}

BOOL CLibraryView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CLibraryView::OnInitialUpdate()
{	
	m_pSet = &GetDocument()->m_librarySet;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
}

/////////////////////////////////////////////////////////////////////////////
// CLibraryView printing

BOOL CLibraryView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLibraryView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLibraryView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLibraryView diagnostics

#ifdef _DEBUG
void CLibraryView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CLibraryView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CLibraryDoc* CLibraryView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLibraryDoc)));
	return (CLibraryDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLibraryView database support
CRecordset* CLibraryView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CLibraryView message handlers
void CLibraryView::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString Officier;
	CMainFrame* pMainFrame = (CMainFrame* )AfxGetMainWnd();
	type=pMainFrame->type;
	Officier=pMainFrame->m_strOfficier;
	User_ID=pMainFrame->m_strUserID;
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	int nItem = m_list.GetNextSelectedItem(pos);
		
	switch(GetCheckedRadioButton(IDC_LIST1,IDC_LIST3))
	{
	case IDC_LIST2:
		{
			if(Officier!="管理员"&&Officier!="最高管理员")
			{
				AfxMessageBox(_T("无权限！还书仅供管理员操作!"));
				return ;
			}
		CString Book_id=m_list.GetItemText(nItem, 0);
		if(AfxMessageBox(_T("是否立即还书？"),MB_YESNO|MB_ICONQUESTION)==IDYES)
		{
				CReturnBookDlg  mDlg;
				mDlg.m_Book_ID=Book_id;
				mDlg.m_Reader_ID=m_Info_ID;
				mDlg.DoModal();
		}

		}break;
	case IDC_LIST1:
	{
		CString Book_id=m_list.GetItemText(nItem, 0);
		int surplus=_ttoi(m_list.GetItemText(nItem, 6));
		if(surplus>0)
		{
			if(AfxMessageBox(_T("是否立即借书？"),MB_YESNO|MB_ICONQUESTION)==IDYES)
			{
				switch(type)
				{
					case 0:
						{
							CLendOutDlg mDlg;
							mDlg.m_strBookID=Book_id;
							mDlg.m_strReaderID=User_ID;
							mDlg.DoModal();
						}
					break;
					case 1:
						{
							CLendOutDlg mDlg;
							mDlg.m_strBookID=Book_id;
							mDlg.DoModal();
						}
						break;
					case 3:
						{
							CChoose mDlg;
							mDlg.DoModal();
						}
						break;
				}
			}
		}
		else
		{
			MessageBox(_T("该书已借完"));
			return ;
		}
	}
	}
	*pResult = 0;
}
void CLibraryView::OnEnquery() 
{
	if(!IS)
	{
		MessageBox("先选择类型!");
		return ;
	}
	CMainFrame* pMainFrame = (CMainFrame* )AfxGetMainWnd();
	type=pMainFrame->type;
	if(type==3)
	{
		GetDlgItem(IDC_LIST2)->EnableWindow(FALSE);
		GetDlgItem(IDC_LIST3)->EnableWindow(FALSE);
		GetDlgItem(IDC_INFO_ID)->EnableWindow(FALSE);
		GetDlgItem(IDC_INFO_ID)->EnableWindow(FALSE);
		MessageBox("无权限！");
		return;
	}
	UpdateData();
	m_Info_ID.TrimLeft();
	if (m_Info_ID.IsEmpty())
	{
		MessageBox("要查询的内容不能为空！");
		return;
	}
	m_list.DeleteAllItems();
	CTime  m_ReturnDate_tmp;
	CTime  m_Current_Time=CTime::GetCurrentTime();
	CTimeSpan m_TimeSpan_tmp(30,24,59,59);
	int i=0;
	switch(GetCheckedRadioButton(IDC_LIST1,IDC_LIST3))
	{
	case IDC_LIST2: 
		{
			m_BWD.m_strFilter.Format("READER_ID='%s'",m_Info_ID);
			if(!m_BWD.Open())
			{
				MessageBox("数据库打开失败！");
			}
			if(m_BWD.IsBOF())
			{
				MessageBox("没有找到该读者ID的相关内容！");
			}
			while(!m_BWD.IsEOF())
			{
				BOOK_ID=m_BWD.m_BOOK_ID;
				BORROW_DATE=m_BWD.m_BORROW_DATE.Format("%Y年%m月%d日");
				m_ReturnDate_tmp=m_BWD.m_BORROW_DATE+m_TimeSpan_tmp;
				RETURN_TIME=m_ReturnDate_tmp.Format("%Y年%m月%d日");
				m_BD.m_strFilter.Format("BOOK_ID='%s'",BOOK_ID);
				if(!m_BD.Open())
				{
					MessageBox("数据库打开失败！");
				}
				if (m_BD.IsBOF())
				{
					AfxMessageBox("没有该书数据！");
					m_BD.Close();
					return ;
				}
				BOOK_NAME=m_BD.m_BOOK_NAME;
				m_BD.Close();
				m_list.InsertItem(i, _T(""));
				m_list.SetItemText(i, 0, BOOK_ID);									//添加到list Control 中的第i行的第一列下
				m_list.SetItemText(i, 1, BOOK_NAME);		 							//添加到list Control 中的第i行的第二列下
				m_list.SetItemText(i, 2, BORROW_DATE);			//添加到list Control 中的第i行的第三列下
				m_list.SetItemText(i, 3, RETURN_TIME);			//添加到list Control 中的第i行的第四列下
				i += 1;																//下次循环指向第2行
				m_BWD.MoveNext();												//移动到下一个记录
			}
			m_BWD.Close();
		} break;
	case IDC_LIST3:
		{
			m_BH.m_strFilter.Format("READER_ID='%s'",m_Info_ID);
			if(!m_BH.Open())
			{
				MessageBox("数据库打开失败！");
			}
				if(m_BH.IsBOF())
			{
				MessageBox("没有找到该读者ID的相关内容！");
			}
			while(!m_BH.IsEOF())
			{
				BOOK_ID=m_BH.m_BOOK_ID;
				Money.Format("%0.1f",m_BH.m_DAYS*0.2);
				BORROW_DATE=m_BH.m_BORROW_DATE.Format("%Y年%m月%d日");
				Day.Format("%d",m_BH.m_DAYS);
				RETURN_DATE=m_BH.m_RETURN_DATE.Format("%Y年%m月%d日");

				m_BD.m_strFilter.Format("BOOK_ID='%s'",BOOK_ID);
				if(!m_BD.Open())
				{
					MessageBox("数据库打开失败！");
				}
				if (m_BD.IsBOF())
				{
					AfxMessageBox("没有该书数据！");
					m_BD.Close();
					return ;
				}
				BOOK_NAME=m_BD.m_BOOK_NAME;
				m_BD.Close();
				m_list.InsertItem(i, _T(""));
				m_list.SetItemText(i, 0, BOOK_ID);									//添加到list Control 中的第i行的第一列下
				m_list.SetItemText(i, 1, BOOK_NAME);		 							//添加到list Control 中的第i行的第二列下
				m_list.SetItemText(i, 2, BORROW_DATE);			//添加到list Control 中的第i行的第三列下
				m_list.SetItemText(i, 3, RETURN_DATE);			//添加到list Control 中的第i行的第四列下
				m_list.SetItemText(i, 4, Day);										//添加到list Control 中的第i行的第五列下
				m_list.SetItemText(i, 5, Money);										//添加到list Control 中的第i行的第六列下
				i += 1;																//下次循环指向第2行
				m_BH.MoveNext();												//移动到下一个记录
			}
			m_BH.Close();
		} break;
	case IDC_LIST1:
		{
			m_BD.m_strFilter.Format("BOOK_ID='%s'",m_Info_ID);
			if(!m_BD.Open())
			{
				MessageBox("数据库打开失败！");
			}
				if(m_BD.IsBOF())
			{
				MessageBox("没有找到该读者ID的相关内容！");
			}
			while(!m_BD.IsEOF())
			{
				BOOK_ID=m_BD.m_BOOK_ID;
				BOOK_NAME=m_BD.m_BOOK_NAME;
				AUTHOR=m_BD.m_AUTHOR;
				PRESS=m_BD.m_PRESS;
				PRESS_DATE=(m_BD.m_PRESS_DATE).Format("%Y年%m月%d日");
				BOOK_NUM.Format("%d",m_BD.m_BOOK_NUM);
				SURPLUS_NUM.Format("%d",m_BD.m_SURPLUS_NUM);
				if(m_BD.m_FLAG_BORROW=="Y")
				{
					FLAG=_T("可借");
				}
				else
				{
					FLAG=_T("不可借");
				}
				m_list.InsertItem(i, _T(""));
				m_list.SetItemText(i, 0, BOOK_ID);									//添加到list Control 中的第i行的第一列下
				m_list.SetItemText(i, 1, BOOK_NAME);		 							//添加到list Control 中的第i行的第二列下
				m_list.SetItemText(i, 2, AUTHOR);			//添加到list Control 中的第i行的第三列下
				m_list.SetItemText(i, 3, PRESS);			//添加到list Control 中的第i行的第四列下
				m_list.SetItemText(i, 4, PRESS_DATE);										//添加到list Control 中的第i行的第五列下
				m_list.SetItemText(i, 5, BOOK_NUM);										//添加到list Control 中的第i行的第六列下
				m_list.SetItemText(i,6,SURPLUS_NUM);										//添加到list Control 中的第i行的第七列下
				m_list.SetItemText(i,7,FLAG);										//添加到list Control 中的第i行的第八列下
				i += 1;																//下次循环指向第2行
				m_BD.MoveNext();												//移动到下一个记录
			}
			m_BD.Close();
		}break;
	}
    return;
}

void CLibraryView::OnList3() 
{
	// TODO: Add your control notification handler code here
	CMainFrame* pMainFrame = (CMainFrame* )AfxGetMainWnd();
	type=pMainFrame->type;
	if(type==0)
	{
		m_Info_ID=pMainFrame->m_strUserID;
		GetDlgItem(IDC_INFO_ID)->EnableWindow(FALSE);
		UpdateData(FALSE);
	}
	GetDlgItem(IDC_INFO)->SetWindowText("读者ID：");
	while ( m_list.DeleteColumn (0))
	{
	}
	m_list.DeleteAllItems();
	CRect rect;
	m_list.GetClientRect(&rect);
	m_list.SetExtendedStyle( LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//表头
	m_list.InsertColumn(0,_T("图书ID"), LVCFMT_LEFT,rect.Width()/5,0);
	m_list.InsertColumn(1,_T("图书名称"), LVCFMT_LEFT,rect.Width()/5,1);
	m_list.InsertColumn(2,_T("借阅日期"), LVCFMT_LEFT,rect.Width()/5,2);
	m_list.InsertColumn(3,_T("还书日期"), LVCFMT_LEFT,rect.Width()/5,3);
	m_list.InsertColumn(4,_T("违约天数"), LVCFMT_LEFT,rect.Width()/5,4);
	m_list.InsertColumn(5,_T("金额"), LVCFMT_LEFT,rect.Width()/5,5);
	IS=TRUE;
}

void CLibraryView::OnList2() 
{
	// TODO: Add your control notification handler code here
	CMainFrame* pMainFrame = (CMainFrame* )AfxGetMainWnd();
	type=pMainFrame->type;
	if(type==0)
	{
		m_Info_ID=pMainFrame->m_strUserID;
		GetDlgItem(IDC_INFO_ID)->EnableWindow(FALSE);
		UpdateData(FALSE);
	}
	GetDlgItem(IDC_INFO)->SetWindowText("读者ID：");
	while (m_list.DeleteColumn (0))
	{
	}
	m_list.DeleteAllItems();
	CRect rect;
	m_list.GetClientRect(&rect);
	m_list.SetExtendedStyle( LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//表头
	m_list.InsertColumn(0,_T("图书ID"), LVCFMT_LEFT,rect.Width()/4,0);
	m_list.InsertColumn(1,_T("图书名称"), LVCFMT_LEFT,rect.Width()/4,1);
	m_list.InsertColumn(2,_T("借阅日期"), LVCFMT_LEFT,rect.Width()/4,2);
	m_list.InsertColumn(3,_T("应还日期"), LVCFMT_LEFT,rect.Width()/4,3);
//	InvalidateRect(&rect);
	IS=TRUE;
}

void CLibraryView::OnList1() 
{
	// TODO: Add your control notification handler code here
		m_Info_ID="";
		UpdateData(FALSE);
		GetDlgItem(IDC_INFO)->SetWindowText("图书ID：");
		GetDlgItem(IDC_INFO_ID)->EnableWindow(TRUE);
		while (m_list.DeleteColumn (0))
	{
	}
	m_list.DeleteAllItems();
	CRect rect;
	m_list.GetClientRect(&rect);
	m_list.SetExtendedStyle( LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//表头
	m_list.InsertColumn(0,_T("图书ID"), LVCFMT_LEFT,rect.Width()/8,0);
	m_list.InsertColumn(1,_T("图书名称"), LVCFMT_LEFT,rect.Width()/8,1);
	m_list.InsertColumn(2,_T("作者"), LVCFMT_LEFT,rect.Width()/8,2);
	m_list.InsertColumn(3,_T("出版社"), LVCFMT_LEFT,rect.Width()/8,3);
	m_list.InsertColumn(4,_T("出版时间"), LVCFMT_LEFT,rect.Width()/8,4);
	m_list.InsertColumn(5,_T("该书总量"), LVCFMT_LEFT,rect.Width()/8,5);
	m_list.InsertColumn(6,_T("可借数量"), LVCFMT_LEFT,rect.Width()/8,6);
	m_list.InsertColumn(7,_T("是否可借"), LVCFMT_LEFT,rect.Width()/8,6);
	IS=TRUE;
}
