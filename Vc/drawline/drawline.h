// drawline.h : main header file for the DRAWLINE application
//

#if !defined(AFX_DRAWLINE_H__1F1510CF_56D1_4BF7_AFD2_1DF10AAB638D__INCLUDED_)
#define AFX_DRAWLINE_H__1F1510CF_56D1_4BF7_AFD2_1DF10AAB638D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDrawlineApp:
// See drawline.cpp for the implementation of this class
//

class CDrawlineApp : public CWinApp
{
public:
	CDrawlineApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawlineApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDrawlineApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWLINE_H__1F1510CF_56D1_4BF7_AFD2_1DF10AAB638D__INCLUDED_)
