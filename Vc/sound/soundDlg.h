// soundDlg.h : header file
//

#if !defined(AFX_SOUNDDLG_H__088DFA20_57C7_474B_A448_68833B1A0F05__INCLUDED_)
#define AFX_SOUNDDLG_H__088DFA20_57C7_474B_A448_68833B1A0F05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSoundDlg dialog

class CSoundDlg : public CDialog
{
// Construction
public:
	CSoundDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSoundDlg)
	enum { IDD = IDD_SOUND_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSoundDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	MCIDEVICEID  m_MCIDeviceID;
	// Generated message map functions
	//{{AFX_MSG(CSoundDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onplay();
	afx_msg void Onexit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOUNDDLG_H__088DFA20_57C7_474B_A448_68833B1A0F05__INCLUDED_)
