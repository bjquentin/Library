// Explanation.cpp : implementation file
//

#include "stdafx.h"
#include "library.h"
#include "Explanation.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExplanation dialog


CExplanation::CExplanation(CWnd* pParent /*=NULL*/)
	: CDialog(CExplanation::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExplanation)
	m_edit = _T("");
	//}}AFX_DATA_INIT
}


void CExplanation::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExplanation)
	DDX_Text(pDX, IDC_EDIT1, m_edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExplanation, CDialog)
	//{{AFX_MSG_MAP(CExplanation)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExplanation message handlers

BOOL CExplanation::OnInitDialog() 
{
	CDialog::OnInitDialog();
	TCHAR exeFullPath[MAX_PATH];
	GetModuleFileName(NULL,exeFullPath, MAX_PATH);
	CString szfolder = exeFullPath;
	int pos = szfolder.ReverseFind('\\');
	szfolder = szfolder.Left(pos+1)+_T("\About.txt");
	// TODO: Add extra initialization here

	CString str =" ";
	CStdioFile file;
	file.Open(szfolder,CFile::modeRead);//打开文件
	//逐行读取字符串
	while( file.ReadString(str))
	{
	//设置到编辑框
		//str+="\n";
		m_edit =m_edit + str+"\r\n"; //test
	}
	file.Close();//关闭文件
	UpdateData( FALSE );
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
