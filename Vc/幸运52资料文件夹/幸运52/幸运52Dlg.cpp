// 幸运52Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "幸运52.h"
#include "幸运52Dlg.h"

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
// CMy52Dlg dialog

CMy52Dlg::CMy52Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy52Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy52Dlg)
	m_BEGIN = 0;
	m_STATIC1 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	cmmdty[0]="康佳29寸纯平彩电";
	cmmdty[1]="松下掌上电脑";
	cmmdty[2]="JNC MP3播放器891";
	cmmdty[3]="捷视可视电话机200T";
	cmmdty[4]="索尼随身听EX2000";
	cmmdty[5]="索尼数码相机DSC-P1";
	cmmdty[6]="松下剃须刀ES365A";
	cmmdty[7]="日本ESP电吉他";
	cmmdty[8]="Nokiya 8210手机";
	cmmdty[9]="奔驰500";

	CurrentCommodityIndex=-1;

	price[0]=4390;
	price[1]=5230;
	price[2]=2079;
	price[3]=5380;
	price[4]=1224;
	price[5]=7140;
	price[6]=273;
	price[7]=5230;
	price[8]=2810;
	price[9]=120000;
 
    Bitmap[0].LoadBitmap(IDB_BITMAP1);
	Bitmap[1].LoadBitmap(IDB_BITMAP2);
	Bitmap[2].LoadBitmap(IDB_BITMAP3);
	Bitmap[3].LoadBitmap(IDB_BITMAP4);
	Bitmap[4].LoadBitmap(IDB_BITMAP5);
	Bitmap[5].LoadBitmap(IDB_BITMAP6);
	Bitmap[6].LoadBitmap(IDB_BITMAP7);
	Bitmap[7].LoadBitmap(IDB_BITMAP8);
	Bitmap[8].LoadBitmap(IDB_BITMAP9);
	Bitmap[9].LoadBitmap(IDB_BITMAP10);


	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy52Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy52Dlg)
	DDX_Text(pDX, IDC_SHURU, m_BEGIN);
	DDX_Text(pDX, IDC_STATIC1, m_STATIC1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy52Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy52Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_BEGIN, OnBegin)
	ON_BN_CLICKED(ID_OVER, OnOver)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy52Dlg message handlers

BOOL CMy52Dlg::OnInitDialog()
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

void CMy52Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy52Dlg::OnPaint() 
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
HCURSOR CMy52Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy52Dlg::OnBegin() 
{
	// TODO: Add your control notification handler code here
	m_BEGIN=0;//清空输入框
// 	stand(time (NULL));
	CurrentCommodityIndex=rand()%10;//产生1个0-9的随机数
	m_STATIC1.Format("%s",cmmdty[CurrentCommodityIndex]);
	UpdateData(FALSE);

	if(CurrentCommodityIndex==0)
		((CStatic*)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(Bitmap[0]));
	else if(CurrentCommodityIndex==1)
		((CStatic*)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(Bitmap[1]));
	else if(CurrentCommodityIndex==2)
		((CStatic*)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(Bitmap[2]));
	else if(CurrentCommodityIndex==3)
		((CStatic*)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(Bitmap[3]));
	else if(CurrentCommodityIndex==4)
		((CStatic*)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(Bitmap[4]));
	else if(CurrentCommodityIndex==5)
		((CStatic*)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(Bitmap[5]));
	else if(CurrentCommodityIndex==6)
		((CStatic*)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(Bitmap[6]));
	else if(CurrentCommodityIndex==7)
		((CStatic*)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(Bitmap[7]));
	else if(CurrentCommodityIndex==8)
		((CStatic*)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(Bitmap[8]));
	else if(CurrentCommodityIndex==9)
		((CStatic*)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(Bitmap[9]));

    GetDlgItem(IDC_SHURU)->SetFocus();
}

void CMy52Dlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	//保证用户先选择一商品
	if(CurrentCommodityIndex==-1)
	{
		MessageBox("您必须先选择一种商品!请点击“开始”按钮!","错误",MB_OK);
        GetDlgItem(ID_BEGIN)->SetFocus();
		return;
	}
	
	int priceTemp=m_BEGIN;
	if(priceTemp==0)
	{
		MessageBox("您必须为商品输入价格!!!","错误",MB_OK);
		return;
	}
	if(priceTemp>price[CurrentCommodityIndex])
	{
		MessageBox("你想用这么多的钱买这个破东西?高了高了!!!","猜错了",MB_OK);
		GetDlgItem(IDC_SHURU)->SetFocus();
	}
    else if(priceTemp<price[CurrentCommodityIndex])
	{
		MessageBox("你想用这么少的钱买这个好东西?低了低了!!!","猜错了",MB_OK);
		GetDlgItem(IDC_SHURU)->SetFocus();
	}
	else
	{
		MessageBox("恭喜恭喜!!!!!!","猜对了",MB_OK);
		GetDlgItem(ID_BEGIN)->SetFocus();
	}

}

void CMy52Dlg::OnOver() 
{
	// TODO: Add your control notification handler code here
	exit(0);
}
