; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTestsoundDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "testsound.h"

ClassCount=4
Class1=CTestsoundApp
Class2=CTestsoundDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TESTSOUND_DIALOG

[CLS:CTestsoundApp]
Type=0
HeaderFile=testsound.h
ImplementationFile=testsound.cpp
Filter=N

[CLS:CTestsoundDlg]
Type=0
HeaderFile=testsoundDlg.h
ImplementationFile=testsoundDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=testsoundDlg.h
ImplementationFile=testsoundDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TESTSOUND_DIALOG]
Type=1
Class=CTestsoundDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_PLAY,button,1342242816
Control3=IDC_EXIT,button,1342242816

