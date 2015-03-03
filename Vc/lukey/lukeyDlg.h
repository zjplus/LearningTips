// lukeyDlg.h : header file
//

#if !defined(AFX_LUKEYDLG_H__7B59EF03_B733_4776_8F69_20F4F30665DB__INCLUDED_)
#define AFX_LUKEYDLG_H__7B59EF03_B733_4776_8F69_20F4F30665DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLukeyDlg dialog

class CLukeyDlg : public CDialog
{
// Construction
public:
	//CLukeyDlg(CWnd* pParent = NULL);	// standard constructor
	//Bitmap Bitmap[5];
	//{{AFX_DATA(CLukeyDlg)
	enum { IDD = IDD_LUKEY_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLukeyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLukeyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnChangeShow();
	afx_msg void OnGo();
	afx_msg void OnRule();
	virtual void OnOK();
	afx_msg void OnNextone();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	//CString goods[5];//用于保存商品名称
    //int num;//用于表示当前商品的序号
    //int price[5];       //用于保存各种商品的价格
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LUKEYDLG_H__7B59EF03_B733_4776_8F69_20F4F30665DB__INCLUDED_)
