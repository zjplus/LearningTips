# Microsoft Developer Studio Project File - Name="Lucky52" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Lucky52 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Lucky52.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Lucky52.mak" CFG="Lucky52 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Lucky52 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Lucky52 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Lucky52 - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Lucky52 - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 winmm.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Lucky52 - Win32 Release"
# Name "Lucky52 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Lucky52.cpp
# End Source File
# Begin Source File

SOURCE=.\Lucky52.rc
# End Source File
# Begin Source File

SOURCE=.\Lucky52Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Lucky52.h
# End Source File
# Begin Source File

SOURCE=.\Lucky52Dlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\1192_2008755926140586868.bmp
# End Source File
# Begin Source File

SOURCE=.\res\201210136396180.bmp
# End Source File
# Begin Source File

SOURCE=.\res\201282974311175.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Lucky52.ico
# End Source File
# Begin Source File

SOURCE=.\res\Lucky52.rc2
# End Source File
# Begin Source File

SOURCE=".\res\�׳��_1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\���ܳ��ܵ�����֮��.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\���ﹷ.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\��ײ�.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\��������.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\���������ɫ��.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\���ȳ�����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\��ޱ�·�.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\��׺���.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\��Ӱ����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\���� 700D.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�������Ĳ�����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�۹��·�.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\����ŷ��ʿ�ֱ�.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\��ף����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\��è����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\����ţ���.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\õ�廨��.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�Ϳ˻��������Ʒ.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\Ȯҹ��ʮ����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\��ëȫ��.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\ɱ���豧��.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\����PS2����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�¹�.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�¼�����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�����ĵ�.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\���ӻ�����.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
