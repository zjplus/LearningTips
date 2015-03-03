// Lucky52Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Lucky52.h"
#include "Lucky52Dlg.h"

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
// CLucky52Dlg dialog

CLucky52Dlg::CLucky52Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLucky52Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLucky52Dlg)
	m_goodname = _T("");
	m_picture = _T("");
	m_price = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	goods[0].goodsname="白炽灯泡";
	goods[1].goodsname="书籍 不能承受的生命之轻";
	goods[2].goodsname="宠物狗";
	goods[3].goodsname="新鲜大白菜";
	goods[4].goodsname="刀剑神域手工剑";
	goods[5].goodsname="变色杯";
	goods[6].goodsname="长笛";
	goods[7].goodsname="电热宠物窝";
	goods[8].goodsname="黑檀木发簪";
	goods[9].goodsname="戈薇校服";
	goods[10].goodsname="宫绦";
	goods[11].goodsname="汉服";
	goods[12].goodsname="火影小武器";
	goods[13].goodsname="吉他";
	goods[14].goodsname="佳能700D";
	goods[15].goodsname="江西空心菜种子 ";
	goods[16].goodsname="桔梗巫女服";
	goods[17].goodsname="卡西欧男士手表";
	goods[18].goodsname="梁祝校服";
	goods[19].goodsname="龙猫超大公仔";
	goods[20].goodsname="麻辣牛肉干";
	goods[21].goodsname="玫瑰花茶";
	goods[22].goodsname="七弦琴";
	goods[23].goodsname="耐克花瓣街球";
	goods[24].goodsname="犬夜叉十字绣";
	goods[25].goodsname="三毛全集";
	goods[26].goodsname="杀生丸抱枕";
	goods[27].goodsname="手链 ";
	goods[28].goodsname="索尼PS2主机 ";
	goods[29].goodsname="衣柜 ";
	goods[30].goodsname="月季花苗";
	goods[31].goodsname="栀子花盆栽 ";
	goods[32].goodsname="佐助之剑";

	goods[0].goodsprice=3;
	goods[1].goodsprice=15;
	goods[2].goodsprice=2560;
	goods[3].goodsprice=4;
	goods[4].goodsprice=50;
	goods[5].goodsprice=19;
	goods[6].goodsprice=87;
	goods[7].goodsprice=109;
	goods[8].goodsprice=97;
	goods[9].goodsprice=121;
	goods[10].goodsprice=22;
	goods[11].goodsprice=276;
	goods[12].goodsprice=61;
	goods[13].goodsprice=371;
	goods[14].goodsprice=4150;
	goods[15].goodsprice=3;
	goods[16].goodsprice=188;
	goods[17].goodsprice=4548;
	goods[18].goodsprice=135;
	goods[19].goodsprice=109;
	goods[20].goodsprice=12;
	goods[21].goodsprice=4;
	goods[22].goodsprice=90;
	goods[23].goodsprice=516;
	goods[24].goodsprice=30;
	goods[25].goodsprice=76;
	goods[26].goodsprice=21;
	goods[27].goodsprice=19;
	goods[28].goodsprice=2108;
	goods[29].goodsprice=530;
	goods[30].goodsprice=23;
	goods[31].goodsprice=20;
	goods[32].goodsprice=41;
	
	goodsorder=-1;	

}

void CLucky52Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLucky52Dlg)
	DDX_Control(pDX, IDC_state, m_state);
	DDX_Control(pDX, IDC_start, m_start);
	DDX_Control(pDX, IDC_ok, m_ok);
	DDX_Control(pDX, IDC_exit, m_exit);
	DDX_Text(pDX, IDC_goodname, m_goodname);
	DDX_Text(pDX, IDC_picture, m_picture);
	DDX_Text(pDX, IDC_price, m_price);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLucky52Dlg, CDialog)
	//{{AFX_MSG_MAP(CLucky52Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_exit, Onexit)
	ON_BN_CLICKED(IDC_ok, Onok)
	ON_BN_CLICKED(IDC_start, Onstart)
	ON_BN_CLICKED(IDC_state, Onstate)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLucky52Dlg message handlers

BOOL CLucky52Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	setbit();//初始化所有图片
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


	// TODO: Add your control notification handler code here
	CDialog::OnInitDialog();
    MCI_OPEN_PARMS mciOpenParms; // 打开MCI设备
    mciOpenParms.lpstrDeviceType="waveaudio";  //MCI设备名
	mciOpenParms.lpstrElementName="ding.wav"; //声音文件,此处写你考到文件夹下的声音文件名
	mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE|MCI_OPEN_ELEMENT,(DWORD)(LPVOID)&mciOpenParms);
    m_MCIDeviceID=mciOpenParms.wDeviceID;
	MCI_PLAY_PARMS mciPlayParms;
	mciPlayParms.dwFrom=0;  //从文件开始处开始播放
	mciSendCommand(m_MCIDeviceID,MCI_PLAY,MCI_FROM,
	(DWORD)(LPVOID)&mciPlayParms);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLucky52Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLucky52Dlg::OnPaint() 
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
HCURSOR CLucky52Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLucky52Dlg::Onexit() 
{
	// TODO: Add your control notification handler code here
	exit(1);
}

void CLucky52Dlg::Onok() 
{
	// TODO: Add your control notification handler code here
	UpdateData();

	if(goodsorder==-1)
	{
		MessageBox("先选择一个商品！","错误！");
		GetDlgItem(IDC_start)->SetFocus();
		return ;
	}
	int Temp_Price=m_price;
	if(Temp_Price==0)
	{
		MessageBox("输入一个整数价格。","错误！");
		return ;
	}
	if(Temp_Price>goods[goodsorder].goodsprice)
	{
		MessageBox("土豪！！！！挥金如土","钱多了！");
		m_price=0;
		GetDlgItem(IDC_price)->SetFocus();
		UpdateData(false);
	}

	else if(Temp_Price<goods[goodsorder].goodsprice)
	{
		MessageBox("再不多出点我就被抢走啦！","太低啦！");
		m_price=0;
		GetDlgItem(IDC_price)->SetFocus();
		UpdateData(false);
	}

	else if(Temp_Price==goods[goodsorder].goodsprice)
	{
		MessageBox("万岁，竟然猜对了耶","Congraduation！");
		GetDlgItem(IDC_start)->SetFocus();
	}		
}

void CLucky52Dlg::Onstart() 
{
	// TODO: Add your control notification handler code here
	int TempNum[33]={0};		//用来保存已经出现过的物品
	m_price=0;
	srand(time(NULL));	//时间为种子
	goodsorder=rand()%33;
	m_goodname.Format("%s",goods[goodsorder].goodsname);

	UpdateData(false);		//更新控件显示

	if(goodsorder==0)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[0]);
	else if(goodsorder==1)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[1]);
	else if(goodsorder==2)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[2]);
	else if(goodsorder==3)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[3]);
	else if(goodsorder==4)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[4]);
	else if(goodsorder==5)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[5]);
	else if(goodsorder==6)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[6]);
	else if(goodsorder==7)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[7]);
	else if(goodsorder==8)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[8]);
	else if(goodsorder==9)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[9]);
	else if(goodsorder==10)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[10]);
	else if(goodsorder==11)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[11]);
	else if(goodsorder==12)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[12]);
	else if(goodsorder==13)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[13]);
	else if(goodsorder==14)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[14]);
	else if(goodsorder==15)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[15]);
	else if(goodsorder==16)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[16]);
	else if(goodsorder==17)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[17]);
	else if(goodsorder==18)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[18]);
	else if(goodsorder==19)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[19]);
	else if(goodsorder==20)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[20]);
	else if(goodsorder==21)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[21]);
	else if(goodsorder==22)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[22]);
	else if(goodsorder==23)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[23]);
	else if(goodsorder==24)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[24]);
	else if(goodsorder==25)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[25]);
	else if(goodsorder==26)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[26]);
	else if(goodsorder==27)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[27]);
	else if(goodsorder==28)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[28]);
	else if(goodsorder==29)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[29]);
	else if(goodsorder==30)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[30]);
	else if(goodsorder==31)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[31]);	
	else if(goodsorder==32)
		((CStatic*)GetDlgItem(IDC_picture))->SetBitmap((HBITMAP)Bitmap[32]);	
	
	GetDlgItem(IDC_price)->SetFocus();
	GetDlgItem(IDC_start)->SetWindowText("切换");		
}

void CLucky52Dlg::Onstate() 
{
	// TODO: Add your control notification handler code here
	MessageBox("     单击'开始'按钮开始游戏，输入您对商品的估价并按'确定'键，系统会给出相应提示，根据系统提示进行游戏。退出游戏请单击'退出'键。本程序主要参考杨晶同学的程序，再次表示感谢！","确定");
	return;
}
void CLucky52Dlg::setbit()
{
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
		Bitmap[10].LoadBitmap(IDB_BITMAP11);
		Bitmap[11].LoadBitmap(IDB_BITMAP12);
		Bitmap[12].LoadBitmap(IDB_BITMAP13);
		Bitmap[13].LoadBitmap(IDB_BITMAP14);
		Bitmap[14].LoadBitmap(IDB_BITMAP15);
		Bitmap[15].LoadBitmap(IDB_BITMAP16);
		Bitmap[16].LoadBitmap(IDB_BITMAP17);
		Bitmap[17].LoadBitmap(IDB_BITMAP18);
		Bitmap[18].LoadBitmap(IDB_BITMAP19);
		Bitmap[19].LoadBitmap(IDB_BITMAP20);
		Bitmap[20].LoadBitmap(IDB_BITMAP21);
		Bitmap[21].LoadBitmap(IDB_BITMAP22);
		Bitmap[22].LoadBitmap(IDB_BITMAP23);
		Bitmap[23].LoadBitmap(IDB_BITMAP24);
		Bitmap[24].LoadBitmap(IDB_BITMAP25);	
		Bitmap[25].LoadBitmap(IDB_BITMAP26);	
		Bitmap[26].LoadBitmap(IDB_BITMAP27);
		Bitmap[27].LoadBitmap(IDB_BITMAP28);	
		Bitmap[28].LoadBitmap(IDB_BITMAP29);	
		Bitmap[29].LoadBitmap(IDB_BITMAP30);
		Bitmap[30].LoadBitmap(IDB_BITMAP31);
		Bitmap[31].LoadBitmap(IDB_BITMAP32);
		Bitmap[32].LoadBitmap(IDB_BITMAP33);
}

void CLucky52Dlg::OnPlay() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnInitDialog();
    MCI_OPEN_PARMS mciOpenParms; // 打开MCI设备
    mciOpenParms.lpstrDeviceType="waveaudio";  //MCI设备名
	mciOpenParms.lpstrElementName="ding.wav"; //声音文件,此处写你考到文件夹下的声音文件名
	mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE|MCI_OPEN_ELEMENT,(DWORD)(LPVOID)&mciOpenParms);
    m_MCIDeviceID=mciOpenParms.wDeviceID;
	MCI_PLAY_PARMS mciPlayParms;
	mciPlayParms.dwFrom=0;  //从文件开始处开始播放
	mciSendCommand(m_MCIDeviceID,MCI_PLAY,MCI_FROM,
	(DWORD)(LPVOID)&mciPlayParms);
	
}
