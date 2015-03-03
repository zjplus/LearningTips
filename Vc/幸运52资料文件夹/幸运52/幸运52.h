// пртк52.h : main header file for the пртк52 application
//

#if !defined(AFX_52_H__57FEF7E1_ED73_4B48_B695_D30447F8DA56__INCLUDED_)
#define AFX_52_H__57FEF7E1_ED73_4B48_B695_D30447F8DA56__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy52App:
// See пртк52.cpp for the implementation of this class
//

class CMy52App : public CWinApp
{
public:
	CMy52App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy52App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy52App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_52_H__57FEF7E1_ED73_4B48_B695_D30447F8DA56__INCLUDED_)
