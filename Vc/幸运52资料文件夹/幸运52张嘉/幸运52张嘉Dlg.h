// 幸运52张嘉Dlg.h : header file
//

#if !defined(AFX_52DLG_H__66BF14CD_79C4_4868_AF32_17A94E3BA53C__INCLUDED_)
#define AFX_52DLG_H__66BF14CD_79C4_4868_AF32_17A94E3BA53C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy52Dlg dialog

class CMy52Dlg : public CDialog
{
// Construction
public:
	CMy52Dlg(CWnd* pParent = NULL);	// standard constructor
	CBitmap Bitmap[10];
	CString time1;
// Dialog Data
	//{{AFX_DATA(CMy52Dlg)
	enum { IDD = IDD_MY52_DIALOG };
	CButton	m_NEXT;
	CButton	m_GO;
	CButton	m_CONFIRM;
	int		m_INPUT;
	CString	m_NAME;
	int		m_TIMES;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy52Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int count;
	MCIDEVICEID m_MCIDeviceID;
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy52Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnHelp();
	afx_msg void OnGo();
	afx_msg void OnConfirm();
	afx_msg void OnNext();
	afx_msg void OnPlay();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString name[10];//用于保存商品名称
	int num;//用于表示当前的商品序号
	int price[10];//用于保存各种商品的价格
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_52DLG_H__66BF14CD_79C4_4868_AF32_17A94E3BA53C__INCLUDED_)
