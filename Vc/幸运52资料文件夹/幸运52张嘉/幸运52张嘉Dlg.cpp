// 幸运52张嘉Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "幸运52张嘉.h"
#include "幸运52张嘉Dlg.h"

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
	m_INPUT = 0;
	m_NAME = _T("");
	m_TIMES = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	  name[0]="小米手机2";
	  name[1]="小米手机2A";
	  name[2]="小米手机3";
	  name[3]="小米盒子";
	  name[4]="红米手机";
	  name[5]="耳机";
	  name[6]="小米移动电源";
	  name[7]="蓝牙音响";
	  name[8]="小米电视";
	  name[9]="小米路由器"; 

	  price[0]=1799;
	  price[1]=1499;
	  price[2]=1999;
	  price[3]=299;
	  price[4]=799;
	  price[5]=199;
	  price[6]=59;
	  price[7]=169;
	  price[8]=2999;
	  price[9]=799;
	  num=1;

	  Bitmap[0].LoadBitmap(IDB_MI2);
	  Bitmap[1].LoadBitmap(IDB_MI2A);
	  Bitmap[2].LoadBitmap(IDB_MI3);
	  Bitmap[3].LoadBitmap(IDB_MIBOX);
	  Bitmap[4].LoadBitmap(IDB_MIH);
	  Bitmap[5].LoadBitmap(IDB_MIHEADSET);
	  Bitmap[6].LoadBitmap(IDB_MIPOWER);
	  Bitmap[7].LoadBitmap(IDB_MISOUND);
	  Bitmap[8].LoadBitmap(IDB_MITV);
	  Bitmap[9].LoadBitmap(IDB_MIWIFI);
	  m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy52Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy52Dlg)
	DDX_Control(pDX, IDC_NEXT, m_NEXT);
	DDX_Control(pDX, IDC_GO, m_GO);
	DDX_Control(pDX, IDC_CONFIRM, m_CONFIRM);
	DDX_Text(pDX, IDC_INPUT, m_INPUT);
	DDX_Text(pDX, IDC_NAME, m_NAME);
	DDX_Text(pDX, IDC_TINMES, m_TIMES);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy52Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy52Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_HELP, OnHelp)
	ON_BN_CLICKED(IDC_GO, OnGo)
	ON_BN_CLICKED(IDC_CONFIRM, OnConfirm)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
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
	count=0;

	GetDlgItem(IDC_INPUT)->EnableWindow(FALSE);//禁用估价编辑框
	GetDlgItem(IDC_CONFIRM)->EnableWindow(FALSE);//禁用确定按钮
	GetDlgItem(IDC_NEXT)->EnableWindow(FALSE);//禁用下一件按钮

	MCI_OPEN_PARMS mciOpenParms; // 打开MCI设备
	mciOpenParms.lpstrDeviceType="waveaudio";  //MCI设备名
	mciOpenParms.lpstrElementName="1945.wav"; //声音文件,此处写你考到文件夹下的声音文件名
	mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE|MCI_OPEN_ELEMENT,(DWORD)(LPVOID)&mciOpenParms);
	m_MCIDeviceID=mciOpenParms.wDeviceID;
	MCI_PLAY_PARMS mciPlayParms;
	mciPlayParms.dwFrom=0;  //从文件开始处开始播放
	mciSendCommand(m_MCIDeviceID,MCI_PLAY,MCI_FROM,
	(DWORD)(LPVOID)&mciPlayParms);
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

void CMy52Dlg::OnOK() 
{
	// TODO: Add extra validation here
	MessageBox("游戏结束！谢谢使用！","退出游戏",MB_OK);
	CDialog::OnOK();
}

void CMy52Dlg::OnHelp() 
{
	// TODO: Add your control notification handler code here
	MessageBox("1.单击“开始”按钮，游戏开始，系统将给出商品。\n2.猜中之后才能点击下一件。\n3.请迅速输入您的估价，并点击“确认”按钮。\n4这时系统会提示您估计的商品价格高了还是低了，在弹出的对话框\n 单击“确认”按钮，再次输入新的估值，重复上一步，直到得到正\n 确的结果,这时系统会提示你中奖了!");	
	
	
}

void CMy52Dlg::OnGo() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_INPUT)->EnableWindow(TRUE);//开启估价编辑框
	GetDlgItem(IDC_CONFIRM)->EnableWindow(TRUE);//开启确定按钮
	GetDlgItem(IDC_INPUT)->SetFocus();//程序最开始的时候聚焦到姓名编辑框
	GetDlgItem(IDC_GO)->EnableWindow(FALSE);//开启估价编辑框
	
		// TODO: Add your control notification handler code here
  m_INPUT=0;    //清空input
	  srand(time(NULL));
	  num=rand()%10;
	  m_NAME.Format("%s",name[num]);
 
	  UpdateData(FALSE);
		
	   if(num==0)
	   ((CStatic *)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(  Bitmap[0]) );
	 else if(num==1)
	   ((CStatic *)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(  Bitmap[1]) );
	 else if(num==2)
	   ((CStatic *)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(  Bitmap[2]) );
	 else if(num==3)
	   ((CStatic *)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(  Bitmap[3]) );
	 else if(num==4)
	   ((CStatic *)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(  Bitmap[4]) );
	 else if(num==5)
	   ((CStatic *)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(  Bitmap[5]) );
	 else if(num==6)
	   ((CStatic *)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(  Bitmap[6]) );
	 else if(num==7)
	   ((CStatic *)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(  Bitmap[7]) );
	 else if(num==8)
	   ((CStatic *)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(  Bitmap[8]) );
	 else if(num==9)
	   ((CStatic *)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(  Bitmap[9]) );	
}

void CMy52Dlg::OnConfirm() 
{
	// TODO: Add your control notification handler code here
	// TODO: Add extra validation here

	UpdateData();
   int priceTemp=m_INPUT;
	if(priceTemp>price[num])
   {
	MCI_OPEN_PARMS mciOpenParms; // 打开MCI设备
	mciOpenParms.lpstrDeviceType="waveaudio";  //MCI设备名
	mciOpenParms.lpstrElementName="ding.wav"; //声音文件,此处写你考到文件夹下的声音文件名
	mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE|MCI_OPEN_ELEMENT,(DWORD)(LPVOID)&mciOpenParms);
	m_MCIDeviceID=mciOpenParms.wDeviceID;
	MCI_PLAY_PARMS mciPlayParms;
	mciPlayParms.dwFrom=0;  //从文件开始处开始播放
	mciSendCommand(m_MCIDeviceID,MCI_PLAY,MCI_FROM,
	(DWORD)(LPVOID)&mciPlayParms);
	
    MessageBox("你真是土豪，用这么多的钱买这个破东西？高了高了！！","猜错了",MB_OK);

	mciSendCommand(m_MCIDeviceID,MCI_STOP,MCI_WAIT,NULL); //停止播放
	mciSendCommand(m_MCIDeviceID,MCI_CLOSE,MCI_WAIT,NULL); //关闭MCI设备

   }
 else if(priceTemp<price[num]) 
   {

	MCI_OPEN_PARMS mciOpenParms; // 打开MCI设备
	mciOpenParms.lpstrDeviceType="waveaudio";  //MCI设备名
	mciOpenParms.lpstrElementName="low.wav"; //声音文件,此处写你考到文件夹下的声音文件名
	mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE|MCI_OPEN_ELEMENT,(DWORD)(LPVOID)&mciOpenParms);
	m_MCIDeviceID=mciOpenParms.wDeviceID;
	MCI_PLAY_PARMS mciPlayParms;
	mciPlayParms.dwFrom=0;  //从文件开始处开始播放
	mciSendCommand(m_MCIDeviceID,MCI_PLAY,MCI_FROM,
	(DWORD)(LPVOID)&mciPlayParms);

    MessageBox("您想用这么少的钱买这个好东西？低了低了！！","猜错了",MB_OK);

	mciSendCommand(m_MCIDeviceID,MCI_STOP,MCI_WAIT,NULL); //停止播放
	mciSendCommand(m_MCIDeviceID,MCI_CLOSE,MCI_WAIT,NULL); //关闭MCI设备

   }
 else
   {
	MCI_OPEN_PARMS mciOpenParms; // 打开MCI设备
	mciOpenParms.lpstrDeviceType="waveaudio";  //MCI设备名
	mciOpenParms.lpstrElementName="drumroll.wav"; //声音文件,此处写你考到文件夹下的声音文件名
	mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE|MCI_OPEN_ELEMENT,(DWORD)(LPVOID)&mciOpenParms);
	m_MCIDeviceID=mciOpenParms.wDeviceID;
	MCI_PLAY_PARMS mciPlayParms;
	mciPlayParms.dwFrom=0;  //从文件开始处开始播放
	mciSendCommand(m_MCIDeviceID,MCI_PLAY,MCI_FROM,
	(DWORD)(LPVOID)&mciPlayParms);
	
    MessageBox("恭喜恭喜！！","猜对了",MB_OK);
	
	mciSendCommand(m_MCIDeviceID,MCI_STOP,MCI_WAIT,NULL); //停止播放
	mciSendCommand(m_MCIDeviceID,MCI_CLOSE,MCI_WAIT,NULL); //关闭MCI设备
	GetDlgItem(IDC_NEXT)->EnableWindow(TRUE);
    }
 	count=count+1;
	if(count==8)
	{	MessageBox("您错了8次，不能再猜这件商品，请点击下一件切换商品。",MB_OK);
		GetDlgItem(IDC_CONFIRM)->EnableWindow(FALSE);//关闭确认按钮
		GetDlgItem(IDC_NEXT)->EnableWindow(TRUE);//开启下一件编辑框
	}
	else
	{
		m_TIMES=count;
		UpdateData(FALSE);
	}


	
}

void CMy52Dlg::OnNext() 
{
	// TODO: Add your control notification handler code here
	//此段源码来自百度文库，修改后使用
	  count=0;
	  m_TIMES=0;
	  m_INPUT=0;    //清空input
	  srand(time(NULL));
	  num=rand()%10;
	  m_NAME.Format("%s",name[num]);
 
	  UpdateData(FALSE);
		
	   if(num==0)
	   ((CStatic *)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(  Bitmap[0]) );
	 else if(num==1)
	   ((CStatic *)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(  Bitmap[1]) );
	 else if(num==2)
	   ((CStatic *)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(  Bitmap[2]) );
	 else if(num==3)
	   ((CStatic *)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(  Bitmap[3]) );
	 else if(num==4)
	   ((CStatic *)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(  Bitmap[4]) );
	 else if(num==5)
	   ((CStatic *)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(  Bitmap[5]) );
	 else if(num==6)
	   ((CStatic *)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(  Bitmap[6]) );
	 else if(num==7)
	   ((CStatic *)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(  Bitmap[7]) );
	 else if(num==8)
	   ((CStatic *)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(  Bitmap[8]) );
	 else if(num==9)
	   ((CStatic *)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(  Bitmap[9]) );	
	 GetDlgItem(IDC_NEXT)->EnableWindow(FALSE);//禁用下一件按钮
	 GetDlgItem(IDC_CONFIRM)->EnableWindow(TRUE);//开启确认按钮
}

void CMy52Dlg::OnPlay() 
{
	// TODO: Add your control notification handler code here
}

void CMy52Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
		MessageBox("1.单击“开始”按钮，游戏开始，系统将给出商品。\n2.猜中之后才能点击下一件。\n3.请迅速输入您的估价，并点击“确认”按钮。\n4这时系统会提示您估计的商品价格高了还是低了，在弹出的对话框\n 单击“确认”按钮，再次输入新的估值，重复上一步，直到得到正\n 确的结果,这时系统会提示你中奖了!");	
	
}
