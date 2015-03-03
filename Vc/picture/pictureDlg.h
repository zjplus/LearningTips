// pictureDlg.h : header file
//

#if !defined(AFX_PICTUREDLG_H__2E56EBDD_705E_450A_BE78_F17D9DF664B5__INCLUDED_)
#define AFX_PICTUREDLG_H__2E56EBDD_705E_450A_BE78_F17D9DF664B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPictureDlg dialog

class CPictureDlg : public CDialog
{
// Construction
public:
	int m_change;
	CPictureDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPictureDlg)
	enum { IDD = IDD_PICTURE_DIALOG };
	int		m_blue;
	int		m_green;
	int		m_red;
	int		m_shape;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPictureDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPictureDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onapply();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICTUREDLG_H__2E56EBDD_705E_450A_BE78_F17D9DF664B5__INCLUDED_)
