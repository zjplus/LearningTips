// Lucky52.h : main header file for the LUCKY52 application
//

#if !defined(AFX_LUCKY52_H__4E105E6B_DEAE_4C0E_B1A3_A62F13DDF3A1__INCLUDED_)
#define AFX_LUCKY52_H__4E105E6B_DEAE_4C0E_B1A3_A62F13DDF3A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLucky52App:
// See Lucky52.cpp for the implementation of this class
//

class CLucky52App : public CWinApp
{
public:
	CLucky52App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLucky52App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLucky52App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LUCKY52_H__4E105E6B_DEAE_4C0E_B1A3_A62F13DDF3A1__INCLUDED_)
