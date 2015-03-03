// mybutton.h : main header file for the MYBUTTON application
//

#if !defined(AFX_MYBUTTON_H__C3DE0C7F_430F_41AC_8603_2F9C6151B817__INCLUDED_)
#define AFX_MYBUTTON_H__C3DE0C7F_430F_41AC_8603_2F9C6151B817__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMybuttonApp:
// See mybutton.cpp for the implementation of this class
//

class CMybuttonApp : public CWinApp
{
public:
	CMybuttonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMybuttonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMybuttonApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYBUTTON_H__C3DE0C7F_430F_41AC_8603_2F9C6151B817__INCLUDED_)
