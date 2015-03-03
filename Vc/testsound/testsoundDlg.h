// testsoundDlg.h : header file
//

#if !defined(AFX_TESTSOUNDDLG_H__930B35B9_06A8_4399_B271_914A1DF7EA28__INCLUDED_)
#define AFX_TESTSOUNDDLG_H__930B35B9_06A8_4399_B271_914A1DF7EA28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/////////////////////////////////////////////////////////////////////////////
// CTestsoundDlg dialog

class CTestsoundDlg : public CDialog
{
// Construction
public:
	CTestsoundDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTestsoundDlg)
	enum { IDD = IDD_TESTSOUND_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestsoundDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	
	HICON m_hIcon;

	MCIDEVICEID m_MCIDeviceID;
	// Generated message map functions
	//{{AFX_MSG(CTestsoundDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPlay();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTSOUNDDLG_H__930B35B9_06A8_4399_B271_914A1DF7EA28__INCLUDED_)
