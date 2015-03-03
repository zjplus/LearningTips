// document.h : main header file for the DOCUMENT application
//

#if !defined(AFX_DOCUMENT_H__4A4F9C29_8BEC_4157_89EB_4930E573E5A5__INCLUDED_)
#define AFX_DOCUMENT_H__4A4F9C29_8BEC_4157_89EB_4930E573E5A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDocumentApp:
// See document.cpp for the implementation of this class
//

class CDocumentApp : public CWinApp
{
public:
	CDocumentApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDocumentApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDocumentApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOCUMENT_H__4A4F9C29_8BEC_4157_89EB_4930E573E5A5__INCLUDED_)
