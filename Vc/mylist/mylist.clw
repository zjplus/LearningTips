; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMylistDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "mylist.h"

ClassCount=3
Class1=CMylistApp
Class2=CMylistDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MYLIST_DIALOG

[CLS:CMylistApp]
Type=0
HeaderFile=mylist.h
ImplementationFile=mylist.cpp
Filter=N

[CLS:CMylistDlg]
Type=0
HeaderFile=mylistDlg.h
ImplementationFile=mylistDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_SCHOOL

[CLS:CAboutDlg]
Type=0
HeaderFile=mylistDlg.h
ImplementationFile=mylistDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MYLIST_DIALOG]
Type=1
Class=CMylistDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_SCHOOL,edit,1350631552
Control4=IDC_ADD,button,1342242816
Control5=IDC_DELETE,button,1342242816
Control6=IDC_SCHOOLLIST,listbox,1352728835

