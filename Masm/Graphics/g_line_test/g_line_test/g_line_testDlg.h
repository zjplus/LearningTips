
// g_line_testDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// Cg_line_testDlg 对话框
class Cg_line_testDlg : public CDialogEx
{
// 构造
public:
	Cg_line_testDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_G_LINE_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
//	afx_msg void OnStatic();
	CEdit idc_text;
	CStatic idc_Label;
};
