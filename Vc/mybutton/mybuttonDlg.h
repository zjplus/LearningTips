// mybuttonDlg.h : header file
//

#if !defined(AFX_MYBUTTONDLG_H__4B12C428_D23C_43D4_8B1A_258A23610075__INCLUDED_)
#define AFX_MYBUTTONDLG_H__4B12C428_D23C_43D4_8B1A_258A23610075__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMybuttonDlg dialog

class CMybuttonDlg : public CDialog
{
// Construction
public:
	int rect;
	CMybuttonDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMybuttonDlg)
	enum { IDD = IDD_MYBUTTON_DIALOG };
	CButton	m_rectradio;
	CString	m_output;
	BOOL	m_editcheck;
	BOOL	m_clientcheck;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMybuttonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMybuttonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClientcheck();
	afx_msg void OnEditcheck();
	afx_msg void OnRectradio();
	afx_msg void OnCircleradio();
	afx_msg void OnExitbutton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYBUTTONDLG_H__4B12C428_D23C_43D4_8B1A_258A23610075__INCLUDED_)
