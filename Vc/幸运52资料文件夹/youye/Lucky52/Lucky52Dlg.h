// Lucky52Dlg.h : header file
//

#if !defined(AFX_LUCKY52DLG_H__F7075B7C_07B7_4428_920E_3B02AB190448__INCLUDED_)
#define AFX_LUCKY52DLG_H__F7075B7C_07B7_4428_920E_3B02AB190448__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "mmsystem.h"
/////////////////////////////////////////////////////////////////////////////
	struct Goods{
		CString goodsname;
		int goodsprice;
	};

// CLucky52Dlg dialog

class CLucky52Dlg : public CDialog
{
// Construction
public:
	CLucky52Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLucky52Dlg)
	enum { IDD = IDD_LUCKY52_DIALOG };
	CButton	m_state;
	CButton	m_start;
	CButton	m_ok;
	CButton	m_exit;
	CString	m_goodname;
	CString	m_picture;
	int		m_price;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLucky52Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation

public:
	Goods goods[33];
	int	goodsorder;				
	CBitmap Bitmap[33];	
	void setbit();
protected:

	HICON m_hIcon;
	MCIDEVICEID m_MCIDeviceID;
	// Generated message map functions
	//{{AFX_MSG(CLucky52Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onexit();
	afx_msg void Onok();
	afx_msg void Onstart();
	afx_msg void Onstate();
	afx_msg void OnPlay();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LUCKY52DLG_H__F7075B7C_07B7_4428_920E_3B02AB190448__INCLUDED_)
