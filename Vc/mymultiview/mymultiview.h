// mymultiview.h : main header file for the MYMULTIVIEW application
//

#if !defined(AFX_MYMULTIVIEW_H__B2082795_3D95_418C_A407_29B7C422F63A__INCLUDED_)
#define AFX_MYMULTIVIEW_H__B2082795_3D95_418C_A407_29B7C422F63A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMymultiviewApp:
// See mymultiview.cpp for the implementation of this class
//

class CMymultiviewApp : public CWinApp
{
public:
	CMymultiviewApp();

	public:
	CMultiDocTemplate* m_PositionTemplate;

	int CMymultiviewApp::ExitInstance()
	{
		delete m_PositionTemplate;
		return CWinApp::ExitInstance();
	};

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMymultiviewApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMymultiviewApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMULTIVIEW_H__B2082795_3D95_418C_A407_29B7C422F63A__INCLUDED_)
