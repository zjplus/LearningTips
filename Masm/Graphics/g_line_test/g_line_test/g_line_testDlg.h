
// g_line_testDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// Cg_line_testDlg �Ի���
class Cg_line_testDlg : public CDialogEx
{
// ����
public:
	Cg_line_testDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_G_LINE_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
