// mylistDlg.h : header file
//

#if !defined(AFX_MYLISTDLG_H__D22874B3_44D0_4CF8_BB29_491523838D56__INCLUDED_)
#define AFX_MYLISTDLG_H__D22874B3_44D0_4CF8_BB29_491523838D56__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMylistDlg dialog

class CMylistDlg : public CDialog
{
// Construction
public:
	CMylistDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMylistDlg)
	enum { IDD = IDD_MYLIST_DIALOG };
	CListBox	m_SchoolList;
	CString	m_strSchool;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMylistDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMylistDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYLISTDLG_H__D22874B3_44D0_4CF8_BB29_491523838D56__INCLUDED_)
