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

SOURCE=".\res\白炽灯_1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\不能承受的生命之轻.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\宠物狗.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\大白菜.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\刀剑神域.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\刀剑神域变色杯.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\笛子.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\电热宠物窝.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\发簪.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\戈薇衣服.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\宫绦.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\红白汉服.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\火影武器.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\吉他.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\佳能 700D.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\江西空心菜种子.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\桔梗衣服.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\卡西欧男士手表.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\梁祝服饰.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\龙猫公仔.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\麻辣牛肉干.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\玫瑰花茶.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\耐克花瓣接球正品.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\七弦琴.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\犬夜叉十字绣.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\三毛全集.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\杀生丸抱枕.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\手链.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\索尼PS2主机.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\衣柜.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\月季花苗.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\佐助的刀.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\栀子花盆栽.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
