// spinDlg.cpp : implementation file
//

#include "stdafx.h"
#include "spin.h"
#include "spinDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpinDlg dialog

CSpinDlg::CSpinDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSpinDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSpinDlg)
	m_length = 0;
	m_width = 0;
	m_LineWidth = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSpinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpinDlg)
	DDX_Control(pDX, IDC_PROGRESS, m_progress);
	DDX_Control(pDX, IDC_LINEWIDTHSLIDER, m_lineWidthSlider);
	DDX_Control(pDX, IDC_SPIN2, m_WidthSpin);
	DDX_Control(pDX, IDC_SPIN1, m_LengthSpin);
	DDX_Text(pDX, IDC_LENGTH, m_length);
	DDX_Text(pDX, IDC_WIDTH, m_width);
	DDX_Slider(pDX, IDC_LINEWIDTHSLIDER, m_LineWidth);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSpinDlg, CDialog)
	//{{AFX_MSG_MAP(CSpinDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_APPLY, OnApply)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpinDlg message handlers

BOOL CSpinDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	m_WidthSpin.SetRange(10,100);
	m_WidthSpin.SetPos(0);
	m_LengthSpin.SetRange(10,100);
	m_LengthSpin.SetPos(0);

	m_lineWidthSlider.SetRange(1,10);
	m_lineWidthSlider.SetPos(0);
	m_lineWidthSlider.SetTicFreq(1);
	SetDlgItemText(IDC_LINEWIDTH,"�߿�:1");

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSpinDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSpinDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSpinDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSpinDlg::OnApply() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	Invalidate();
	UpdateWindow();
	CClientDC dc(this);
	dc.Rectangle(120,10,120+m_length,10+m_width);

	CPen mypen;
	mypen.CreatePen(PS_SOLID,m_LineWidth,RGB(255,0,0));
	CPen* pOldpen=dc.SelectObject(&mypen);
	dc.Rectangle(120,10,120+m_length,10+m_width);
	dc.SelectObject(pOldpen);
}

void CSpinDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	UpdateData();
	CString LineWidth;
	LineWidth.Format("�߿�:%d",m_LineWidth);
	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
