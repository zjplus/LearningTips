
// g_line_test.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cg_line_testApp:
// �йش����ʵ�֣������ g_line_test.cpp
//

class Cg_line_testApp : public CWinApp
{
public:
	Cg_line_testApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cg_line_testApp theApp;