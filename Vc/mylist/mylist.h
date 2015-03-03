// mylist.h : main header file for the MYLIST application
//

#if !defined(AFX_MYLIST_H__F671398A_4B77_46CD_A306_751A405B2005__INCLUDED_)
#define AFX_MYLIST_H__F671398A_4B77_46CD_A306_751A405B2005__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMylistApp:
// See mylist.cpp for the implementation of this class
//

class CMylistApp : public CWinApp
{
public:
	CMylistApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMylistApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMylistApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYLIST_H__F671398A_4B77_46CD_A306_751A405B2005__INCLUDED_)
