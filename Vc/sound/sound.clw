; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSoundDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "sound.h"

ClassCount=3
Class1=CSoundApp
Class2=CSoundDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SOUND_DIALOG

[CLS:CSoundApp]
Type=0
HeaderFile=sound.h
ImplementationFile=sound.cpp
Filter=N

[CLS:CSoundDlg]
Type=0
HeaderFile=soundDlg.h
ImplementationFile=soundDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_exit

[CLS:CAboutDlg]
Type=0
HeaderFile=soundDlg.h
ImplementationFile=soundDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SOUND_DIALOG]
Type=1
Class=CSoundDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_play,button,1342242816
Control4=IDC_exit,button,1342242816

