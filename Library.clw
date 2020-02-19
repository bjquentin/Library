; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLibraryView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "library.h"
LastPage=0

ClassCount=25
Class1=CBookDataSet
Class2=CBookMDlg
Class3=CBorrowDataSet
Class4=CBorrowHistorySet
Class5=CBorrowSet
Class6=CChoose
Class7=CClerkDataSet
Class8=CClerkMDlg
Class9=CExplanation
Class10=CFineDataSet
Class11=CFineDetail
Class12=CFineDlg
Class13=CFineHistoryDataSet
Class14=CLendOutDlg
Class15=CLibraryApp
Class16=CAboutDlg
Class17=CLibraryDoc
Class18=CLibrarySet
Class19=CLibraryView
Class20=CLoginDlg
Class21=CMainFrame
Class22=CReaderDataSet
Class23=CReaderMDlg
Class24=CRegistered
Class25=CReturnBookDlg

ResourceCount=13
Resource1=IDD_LENDOUT
Resource2=IDD_LOGIN
Resource3=IDD_ReturnBook
Resource4=IDD_READER
Resource5=IDD_FINE
Resource6=IDR_MAINFRAME
Resource7=IDD_REGISTERED
Resource8=IDD_CHOOSE
Resource9=IDD_ABOUTBOX
Resource10=IDD_CLERK
Resource11=IDD_LIBRARY_FORM
Resource12=IDD_BOOK
Resource13=IDD_EXPLANATION

[CLS:CBookDataSet]
Type=0
HeaderFile=BookDataSet.h
ImplementationFile=BookDataSet.cpp

[CLS:CBookMDlg]
Type=0
BaseClass=CDialog
HeaderFile=BookMDlg.h
ImplementationFile=BookMDlg.cpp

[CLS:CBorrowDataSet]
Type=0
HeaderFile=BorrowDataSet.h
ImplementationFile=BorrowDataSet.cpp

[CLS:CBorrowHistorySet]
Type=0
HeaderFile=BorrowHistorySet.h
ImplementationFile=BorrowHistorySet.cpp

[CLS:CBorrowSet]
Type=0
HeaderFile=BorrowSet.h
ImplementationFile=BorrowSet.cpp

[CLS:CChoose]
Type=0
BaseClass=CDialog
HeaderFile=Choose.h
ImplementationFile=Choose.cpp

[CLS:CClerkDataSet]
Type=0
HeaderFile=ClerkDataSet.h
ImplementationFile=ClerkDataSet.cpp

[CLS:CClerkMDlg]
Type=0
BaseClass=CDialog
HeaderFile=ClerkMDlg.h
ImplementationFile=ClerkMDlg.cpp

[CLS:CExplanation]
Type=0
BaseClass=CDialog
HeaderFile=Explanation.h
ImplementationFile=Explanation.cpp

[CLS:CFineDataSet]
Type=0
HeaderFile=FineDataSet.h
ImplementationFile=FineDataSet.cpp
Filter=N
BaseClass=CRecordset
VirtualFilter=r
LastObject=CFineDataSet

[CLS:CFineDetail]
Type=0
BaseClass=CDialog
HeaderFile=FineDetail.h
ImplementationFile=FineDetail.cpp

[CLS:CFineDlg]
Type=0
BaseClass=CDialog
HeaderFile=FineDlg.h
ImplementationFile=FineDlg.cpp
LastObject=CFineDlg

[CLS:CFineHistoryDataSet]
Type=0
HeaderFile=FineHistoryDataSet.h
ImplementationFile=FineHistoryDataSet.cpp
Filter=N
BaseClass=CRecordset
VirtualFilter=r

[CLS:CLendOutDlg]
Type=0
BaseClass=CDialog
HeaderFile=LendOutDlg.h
ImplementationFile=LendOutDlg.cpp

[CLS:CLibraryApp]
Type=0
BaseClass=CWinApp
HeaderFile=Library.h
ImplementationFile=Library.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=Library.cpp
ImplementationFile=Library.cpp
LastObject=CAboutDlg

[CLS:CLibraryDoc]
Type=0
BaseClass=CDocument
HeaderFile=LibraryDoc.h
ImplementationFile=LibraryDoc.cpp

[CLS:CLibrarySet]
Type=0
HeaderFile=LibrarySet.h
ImplementationFile=LibrarySet.cpp
Filter=N
BaseClass=CRecordset
VirtualFilter=r

[CLS:CLibraryView]
Type=0
BaseClass=CRecordView
HeaderFile=LibraryView.h
ImplementationFile=LibraryView.cpp
Filter=D
VirtualFilter=RVWC
LastObject=CLibraryView

[CLS:CLoginDlg]
Type=0
BaseClass=CDialog
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[CLS:CReaderDataSet]
Type=0
HeaderFile=ReaderDataSet.h
ImplementationFile=ReaderDataSet.cpp

[CLS:CReaderMDlg]
Type=0
BaseClass=CDialog
HeaderFile=ReaderMDlg.h
ImplementationFile=ReaderMDlg.cpp

[CLS:CRegistered]
Type=0
BaseClass=CDialog
HeaderFile=Registered.h
ImplementationFile=Registered.cpp

[CLS:CReturnBookDlg]
Type=0
BaseClass=CDialog
HeaderFile=ReturnBookDlg.h
ImplementationFile=ReturnBookDlg.cpp

[DB:CBookDataSet]
DB=1

[DB:CBorrowDataSet]
DB=1

[DB:CBorrowHistorySet]
DB=1

[DB:CBorrowSet]
DB=1

[DB:CClerkDataSet]
DB=1

[DB:CFineDataSet]
DB=1
DBType=ODBC
ColumnCount=7
Column1=[READER_ID], 12, 60
Column2=[BOOK_ID], 12, 60
Column3=[AMOUNT], 7, 4
Column4=[DAYS], 5, 2
Column5=[BORROW_DATE], 11, 16
Column6=[FINE_DATE], 11, 16
Column7=[ID], 4, 4

[DB:CFineHistoryDataSet]
DB=1
DBType=ODBC
ColumnCount=8
Column1=[READER_ID], 12, 60
Column2=[BOOK_ID], 12, 60
Column3=[AMOUNT], 7, 4
Column4=[DAYS], 5, 2
Column5=[BORROW_DATE], 11, 16
Column6=[FINE_DATE], 11, 16
Column7=[OK_DATE], 11, 16
Column8=[ID], 4, 4

[DB:CLibrarySet]
DB=1
DBType=ODBC
ColumnCount=51
Column1=[BOOK].[BOOK_ID], 12, 60
Column2=[BOOK_NAME], 12, 100
Column3=[AUTHOR], 12, 60
Column4=[PRESS], 12, 100
Column5=[PRESS_DATE], 11, 16
Column6=[BOOK_NUM], 4, 4
Column7=[SURPLUS_NUM], 4, 4
Column8=[BOOK].[FLAG_BORROW], 12, 20
Column9=[BORROW].[READER_ID], 12, 60
Column10=[BORROW].[BOOK_ID], 12, 60
Column11=[BORROW].[BORROW_DATE], 11, 16
Column12=[BORROW].[ID], 4, 4
Column13=[BORROW_HISTORY].[BOOK_ID], 12, 60
Column14=[BORROW_HISTORY].[READER_ID], 12, 60
Column15=[BORROW_HISTORY].[BORROW_DATE], 11, 16
Column16=[BORROW_HISTORY].[RETURN_DATE], 11, 16
Column17=[BORROW_HISTORY].[DAYS], 4, 4
Column18=[BORROW_HISTORY].[ID], 4, 4
Column19=[CLERK_ID], 12, 60
Column20=[CLERK].[NAME], 12, 16
Column21=[ID_CARD], 12, 36
Column22=[PASSWORD], 12, 60
Column23=[OFFICIER], 12, 60
Column24=[FINE].[READER_ID], 12, 60
Column25=[FINE].[BOOK_ID], 12, 60
Column26=[FINE].[AMOUNT], 7, 4
Column27=[FINE].[DAYS], 5, 2
Column28=[FINE].[BORROW_DATE], 11, 16
Column29=[FINE].[FINE_DATE], 11, 16
Column30=[FINE].[ID], 4, 4
Column31=[FINE_HISTORY].[READER_ID], 12, 60
Column32=[FINE_HISTORY].[BOOK_ID], 12, 60
Column33=[FINE_HISTORY].[AMOUNT], 7, 4
Column34=[FINE_HISTORY].[DAYS], 5, 2
Column35=[FINE_HISTORY].[BORROW_DATE], 11, 16
Column36=[FINE_HISTORY].[FINE_DATE], 11, 16
Column37=[OK_DATE], 11, 16
Column38=[FINE_HISTORY].[ID], 4, 4
Column39=[HISTORY].[READER_ID], 12, 60
Column40=[HISTORY].[BOOK_ID], 12, 60
Column41=[HISTORY].[BORROW_DATE], 11, 16
Column42=[HISTORY].[RETURN_DATE], 11, 16
Column43=[HISTORY].[ID], 4, 4
Column44=[READER].[READER_ID], 12, 16
Column45=[READER].[NAME], 12, 16
Column46=[READER_PASSWORD], 12, 60
Column47=[IDCARD], 12, 36
Column48=[READER_OCC], 12, 16
Column49=[MAXNUM_CAN_BORROW], 5, 2
Column50=[BORROW_NUM], 4, 4
Column51=[READER].[FLAG_BORROW], 12, 2

[DB:CReaderDataSet]
DB=1

[DLG:IDD_BOOK]
Type=1
Class=CBookMDlg
ControlCount=30
Control1=IDC_BOOKNAME_Q,edit,1350631552
Control2=IDC_BOOKID_Q,edit,1350631552
Control3=IDC_NEW,button,1342242816
Control4=IDC_EDIT,button,1342242816
Control5=IDC_ENQUERY,button,1342242816
Control6=IDC_DELETE,button,1342242816
Control7=IDC_BOOKNAME,edit,1350631552
Control8=IDC_BOOKID,edit,1350631552
Control9=IDC_AUTHOR,edit,1350631552
Control10=IDC_PRESSDATE,edit,1350631552
Control11=IDC_PRESS,edit,1350631552
Control12=IDC_BOOK_NUM,edit,1350631552
Control13=IDC_SURPLUS_NUM,edit,1350631552
Control14=IDC_FLAG_BORROW,edit,1350631552
Control15=IDC_PRIOR,button,1342242816
Control16=IDC_NEXT,button,1342242816
Control17=IDC_SAVE,button,1342242816
Control18=IDC_CANCEL_REC,button,1342242816
Control19=IDC_EXIT,button,1342242816
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,button,1342177287
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_STATIC,static,1342308352
Control26=IDC_STATIC,static,1342308352
Control27=IDC_STATIC,static,1342308352
Control28=IDC_STATIC,static,1342308352
Control29=IDC_STATIC,static,1342308352
Control30=IDC_STATIC,static,1342308352

[DLG:IDD_CHOOSE]
Type=1
Class=CChoose
ControlCount=3
Control1=ID_LOGIN,button,1342242817
Control2=ID_REGISTERED,button,1342242816
Control3=IDC_STATIC,static,1342308352

[DLG:IDD_CLERK]
Type=1
Class=CClerkMDlg
ControlCount=24
Control1=IDC_USERNAME_Q,edit,1350631552
Control2=IDC_USERID_Q,edit,1350631552
Control3=IDC_NEW,button,1342242816
Control4=IDC_EDIT,button,1342242816
Control5=IDC_ENQUERY,button,1342242816
Control6=IDC_DELETE,button,1342242816
Control7=IDC_USERNAME,edit,1350631552
Control8=IDC_USERID,edit,1350631552
Control9=IDC_IDCARD,edit,1350631552
Control10=IDC_POSITION,combobox,1344340226
Control11=IDC_PASSWORD,edit,1350631584
Control12=IDC_PRIOR,button,1342242816
Control13=IDC_NEXT,button,1342242816
Control14=IDC_SAVE,button,1342242816
Control15=IDC_CANCEL_REC,button,1342242816
Control16=IDC_EXIT,button,1342242816
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,button,1342177287
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352

[DLG:IDD_EXPLANATION]
Type=1
Class=CExplanation
ControlCount=1
Control1=IDC_EDIT1,edit,1352731652

[DLG:IDD_Finedetail]
Type=1
Class=CFineDetail

[DLG:IDD_FINE]
Type=1
Class=CFineDlg
ControlCount=8
Control1=IDC_READER_ID,edit,1350631552
Control2=IDC_ENQUERY,button,1342242816
Control3=IDC_CONFIRM,button,1342242817
Control4=IDC_EXIT,button,1342242816
Control5=IDC_EDIT1,edit,1350633600
Control6=IDC_LIST1,SysListView32,1350631425
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[DLG:IDD_LENDOUT]
Type=1
Class=CLendOutDlg
ControlCount=24
Control1=IDC_CONFIRM,button,1342242817
Control2=IDC_CANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_READER_ID,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_BOOK_ID,edit,1350631552
Control7=IDC_ENQUERY,button,1342242816
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,static,1342308352
Control10=IDC_BOOKNAME,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_BOOKID,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_AUTHOR,edit,1350631552
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_PRESS,edit,1350631552
Control18=IDC_PRESSDATE,edit,1350631552
Control19=IDC_STATIC,static,1342308352
Control20=IDC_FLAG_BORROW,edit,1350631552
Control21=IDC_STATIC,static,1342308352
Control22=IDC_SURPLUS_NUM,edit,1350631552
Control23=IDC_STATIC,static,1342308352
Control24=IDC_BOOK_NUM,edit,1350631552

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=2
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308353

[DLG:IDD_LIBRARY_FORM]
Type=1
Class=CLibraryView
ControlCount=7
Control1=IDC_LIST1,button,1342308361
Control2=IDC_LIST2,button,1342177289
Control3=IDC_LIST3,button,1342177289
Control4=IDC_INFO,static,1342308352
Control5=IDC_INFO_ID,edit,1350631552
Control6=IDC_ENQUERY,button,1342242816
Control7=IDC_LIST,SysListView32,1350631425

[DLG:IDD_LOGIN]
Type=1
Class=CLoginDlg
ControlCount=10
Control1=IDC_COMBO1,combobox,1344340226
Control2=IDC_LOGIN_ID,edit,1350631552
Control3=IDC_LOGIN_PASSWORD,edit,1350631584
Control4=IDC_CONFIRM,button,1342242817
Control5=IDC_CANCEL,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342177294

[DLG:IDD_READER]
Type=1
Class=CReaderMDlg
ControlCount=26
Control1=IDC_EXIT,button,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDC_READER_NAME_FOR_Q,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_READER_ID_FOR_Q,edit,1350631552
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,static,1342308352
Control8=IDC_READER_NAME,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_READER_ID,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_IDCARD,edit,1350631552
Control13=IDC_PRIOR,button,1342242816
Control14=IDC_NEXT,button,1342242816
Control15=IDC_NEW,button,1342242816
Control16=IDC_EDIT,button,1342242816
Control17=IDC_SAVE,button,1342242816
Control18=IDC_CANCEL_REC,button,1342242816
Control19=IDC_ENQUERY,button,1342242816
Control20=IDC_DELETE,button,1342242816
Control21=IDC_STATIC,static,1342308352
Control22=IDC_COMBO1,combobox,1344340226
Control23=IDC_STATIC,static,1342308352
Control24=IDC_BORROW_NUM,edit,1350631552
Control25=IDC_STATIC,static,1342308352
Control26=IDC_PASSWORD,edit,1350631584

[DLG:IDD_REGISTERED]
Type=1
Class=CRegistered
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_USERNAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_IDCARD,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_PASSWORD,edit,1350631584
Control9=IDC_STATIC,static,1342308352
Control10=IDC_USERID,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_POSITION,combobox,1344340226

[DLG:IDD_ReturnBook]
Type=1
Class=CReturnBookDlg
ControlCount=19
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDITBook_ID,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDITReader_ID,edit,1350631552
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,static,1342308352
Control8=IDC_READER_NAME,edit,1350633600
Control9=IDC_STATIC,static,1342308352
Control10=IDC_BOOK_NAME,edit,1350633600
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDITBorrowDate,edit,1350633600
Control13=IDC_STATIC,static,1342308352
Control14=IDC_EDITReturnDate,edit,1350633600
Control15=IDC_STATIC,static,1342308352
Control16=IDC_EDITDays,edit,1350633600
Control17=IDC_ENQUERY,button,1342242816
Control18=IDC_CONFIRM,button,1342242816
Control19=IDC_NOW_TIME,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_LOGIN_IN
Command15=ID_REGISITERED
Command16=ID_LOGIN_OUT
Command17=ID_USER_MAINTAIN
Command18=ID_BOOK_MAINTAIN
Command19=ID_READER_MAINTAIN
Command20=ID_LEND_OUT
Command21=ID_RETURN_BACK
Command22=ID_FINE
Command23=ID_EXPLANATION
Command24=ID_APP_ABOUT
CommandCount=24

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
CommandCount=7

[ACL:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_EDIT_COPY
Command2=ID_FINE
Command3=ID_LOGIN_IN
Command4=ID_LEND_OUT
Command5=ID_BOOK_MAINTAIN
Command6=ID_FILE_NEW
Command7=ID_FILE_OPEN
Command8=ID_LOGIN_OUT
Command9=ID_FILE_PRINT
Command10=ID_READER_MAINTAIN
Command11=ID_RETURN_BACK
Command12=ID_FILE_SAVE
Command13=ID_USER_MAINTAIN
Command14=ID_EDIT_PASTE
Command15=ID_EDIT_UNDO
Command16=ID_EDIT_CUT
Command17=ID_NEXT_PANE
Command18=ID_PREV_PANE
Command19=ID_EDIT_COPY
Command20=ID_EDIT_PASTE
Command21=ID_EDIT_CUT
Command22=ID_EDIT_UNDO
CommandCount=22

