// ����52Dlg.h : header file
//

#if !defined(AFX_52DLG_H__AF082D3A_C589_445A_815C_6ACC08533EC4__INCLUDED_)
#define AFX_52DLG_H__AF082D3A_C589_445A_815C_6ACC08533EC4__INCLUDED_

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
    CBitmap Bitmap[10];//���ڴ��Bitmapͼ
// Dialog Data
	//{{AFX_DATA(CMy52Dlg)
	enum { IDD = IDD_MY52_DIALOG };
	int		m_BEGIN;
	CString	m_STATIC1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy52Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
    
	// Generated message map functions
	//{{AFX_MSG(CMy52Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBegin();
	virtual void OnOK();
	afx_msg void OnOver();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString cmmdty[10];//���ڱ�����Ʒ����
	int CurrentCommodityIndex;//���ڱ�ʾ��ǰ����Ʒ���
	int price[10];//���ڱ��������Ʒ�ļ۸�
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_52DLG_H__AF082D3A_C589_445A_815C_6ACC08533EC4__INCLUDED_)
