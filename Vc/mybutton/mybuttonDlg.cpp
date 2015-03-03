// mybuttonDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mybutton.h"
#include "mybuttonDlg.h"

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
// CMybuttonDlg dialog

CMybuttonDlg::CMybuttonDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMybuttonDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMybuttonDlg)
	m_output = _T("");
	m_editcheck = FALSE;
	m_clientcheck = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMybuttonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMybuttonDlg)
	DDX_Control(pDX, IDC_EXITBUTTON, m_rectradio);
	DDX_Text(pDX, IDC_OUTPUT, m_output);
	DDX_Check(pDX, IDC_EDITCHECK, m_editcheck);
	DDX_Check(pDX, IDC_CLIENTCHECK, m_clientcheck);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMybuttonDlg, CDialog)
	//{{AFX_MSG_MAP(CMybuttonDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CLIENTCHECK, OnClientcheck)
	ON_BN_CLICKED(IDC_EDITCHECK, OnEditcheck)
	ON_BN_CLICKED(IDC_RECTRADIO, OnRectradio)
	ON_BN_CLICKED(IDC_CIRCLERADIO, OnCircleradio)
	ON_BN_CLICKED(IDC_EXITBUTTON, OnExitbutton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMybuttonDlg message handlers

BOOL CMybuttonDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMybuttonDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMybuttonDlg::OnPaint() 
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
		CPaintDC dc(this);
		CBrush mybrush;
		CBrush* oldbrush;
		UpdateData();
		switch(rect)
		{
		case 1:
		if (m_clientcheck)    //选中客户区
		{
		dc.SetBkMode(TRANSPARENT);      //设置透明格式
		mybrush.CreateSolidBrush(RGB(255,255,0));//创建画刷
		oldbrush=dc.SelectObject(&mybrush);
		dc.Rectangle(170,30,300,180);//绘制矩形
		dc.SelectObject(oldbrush);//恢复原先的画刷
		}
		if(m_editcheck)
		{
		m_output="这是一个矩形";
		UpdateData(false);
		}
		else
		{
		m_output="";
		UpdateData(false);
		}
		break;


		case 2:
		if (m_clientcheck)    //选中客户区
		{
		dc.SetBkMode(TRANSPARENT);//设置透明格式
		mybrush.CreateSolidBrush(RGB(255,0,0));//创建画刷
		oldbrush=dc.SelectObject(&mybrush);
		dc.Ellipse(170,30,300,180);//绘制椭圆
		dc.SelectObject(oldbrush);//恢复原先的画刷
		}

		if(m_editcheck)
		{
		m_output="这是一个椭圆";
		UpdateData(false);
		}
		else
		{
		m_output="";
		UpdateData(false);
		}
		break;
		}

		CDialog::OnPaint();


	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMybuttonDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMybuttonDlg::OnClientcheck() 
{
	// TODO: Add your control notification handler code here
	m_clientcheck=1;
	Invalidate();
	
}

void CMybuttonDlg::OnEditcheck() 
{
	// TODO: Add your control notification handler code here
	m_editcheck=1;
	Invalidate();
	
}

void CMybuttonDlg::OnRectradio() 
{
	// TODO: Add your control notification handler code here
	rect=1;
	Invalidate();
	
}

void CMybuttonDlg::OnCircleradio() 
{
	// TODO: Add your control notification handler code here
	rect=2;
	Invalidate();
	
}

void CMybuttonDlg::OnExitbutton() 
{
	OnOK();
}
