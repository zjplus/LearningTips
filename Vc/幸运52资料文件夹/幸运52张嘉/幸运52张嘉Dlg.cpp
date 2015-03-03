// ����52�ż�Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "����52�ż�.h"
#include "����52�ż�Dlg.h"

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
	  name[0]="С���ֻ�2";
	  name[1]="С���ֻ�2A";
	  name[2]="С���ֻ�3";
	  name[3]="С�׺���";
	  name[4]="�����ֻ�";
	  name[5]="����";
	  name[6]="С���ƶ���Դ";
	  name[7]="��������";
	  name[8]="С�׵���";
	  name[9]="С��·����"; 

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

	GetDlgItem(IDC_INPUT)->EnableWindow(FALSE);//���ù��۱༭��
	GetDlgItem(IDC_CONFIRM)->EnableWindow(FALSE);//����ȷ����ť
	GetDlgItem(IDC_NEXT)->EnableWindow(FALSE);//������һ����ť

	MCI_OPEN_PARMS mciOpenParms; // ��MCI�豸
	mciOpenParms.lpstrDeviceType="waveaudio";  //MCI�豸��
	mciOpenParms.lpstrElementName="1945.wav"; //�����ļ�,�˴�д�㿼���ļ����µ������ļ���
	mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE|MCI_OPEN_ELEMENT,(DWORD)(LPVOID)&mciOpenParms);
	m_MCIDeviceID=mciOpenParms.wDeviceID;
	MCI_PLAY_PARMS mciPlayParms;
	mciPlayParms.dwFrom=0;  //���ļ���ʼ����ʼ����
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
	MessageBox("��Ϸ������ллʹ�ã�","�˳���Ϸ",MB_OK);
	CDialog::OnOK();
}

void CMy52Dlg::OnHelp() 
{
	// TODO: Add your control notification handler code here
	MessageBox("1.��������ʼ����ť����Ϸ��ʼ��ϵͳ��������Ʒ��\n2.����֮����ܵ����һ����\n3.��Ѹ���������Ĺ��ۣ��������ȷ�ϡ���ť��\n4��ʱϵͳ����ʾ�����Ƶ���Ʒ�۸���˻��ǵ��ˣ��ڵ����ĶԻ���\n ������ȷ�ϡ���ť���ٴ������µĹ�ֵ���ظ���һ����ֱ���õ���\n ȷ�Ľ��,��ʱϵͳ����ʾ���н���!");	
	
	
}

void CMy52Dlg::OnGo() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_INPUT)->EnableWindow(TRUE);//�������۱༭��
	GetDlgItem(IDC_CONFIRM)->EnableWindow(TRUE);//����ȷ����ť
	GetDlgItem(IDC_INPUT)->SetFocus();//�����ʼ��ʱ��۽��������༭��
	GetDlgItem(IDC_GO)->EnableWindow(FALSE);//�������۱༭��
	
		// TODO: Add your control notification handler code here
  m_INPUT=0;    //���input
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
	MCI_OPEN_PARMS mciOpenParms; // ��MCI�豸
	mciOpenParms.lpstrDeviceType="waveaudio";  //MCI�豸��
	mciOpenParms.lpstrElementName="ding.wav"; //�����ļ�,�˴�д�㿼���ļ����µ������ļ���
	mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE|MCI_OPEN_ELEMENT,(DWORD)(LPVOID)&mciOpenParms);
	m_MCIDeviceID=mciOpenParms.wDeviceID;
	MCI_PLAY_PARMS mciPlayParms;
	mciPlayParms.dwFrom=0;  //���ļ���ʼ����ʼ����
	mciSendCommand(m_MCIDeviceID,MCI_PLAY,MCI_FROM,
	(DWORD)(LPVOID)&mciPlayParms);
	
    MessageBox("����������������ô���Ǯ������ƶ��������˸��ˣ���","�´���",MB_OK);

	mciSendCommand(m_MCIDeviceID,MCI_STOP,MCI_WAIT,NULL); //ֹͣ����
	mciSendCommand(m_MCIDeviceID,MCI_CLOSE,MCI_WAIT,NULL); //�ر�MCI�豸

   }
 else if(priceTemp<price[num]) 
   {

	MCI_OPEN_PARMS mciOpenParms; // ��MCI�豸
	mciOpenParms.lpstrDeviceType="waveaudio";  //MCI�豸��
	mciOpenParms.lpstrElementName="low.wav"; //�����ļ�,�˴�д�㿼���ļ����µ������ļ���
	mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE|MCI_OPEN_ELEMENT,(DWORD)(LPVOID)&mciOpenParms);
	m_MCIDeviceID=mciOpenParms.wDeviceID;
	MCI_PLAY_PARMS mciPlayParms;
	mciPlayParms.dwFrom=0;  //���ļ���ʼ����ʼ����
	mciSendCommand(m_MCIDeviceID,MCI_PLAY,MCI_FROM,
	(DWORD)(LPVOID)&mciPlayParms);

    MessageBox("��������ô�ٵ�Ǯ������ö��������˵��ˣ���","�´���",MB_OK);

	mciSendCommand(m_MCIDeviceID,MCI_STOP,MCI_WAIT,NULL); //ֹͣ����
	mciSendCommand(m_MCIDeviceID,MCI_CLOSE,MCI_WAIT,NULL); //�ر�MCI�豸

   }
 else
   {
	MCI_OPEN_PARMS mciOpenParms; // ��MCI�豸
	mciOpenParms.lpstrDeviceType="waveaudio";  //MCI�豸��
	mciOpenParms.lpstrElementName="drumroll.wav"; //�����ļ�,�˴�д�㿼���ļ����µ������ļ���
	mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE|MCI_OPEN_ELEMENT,(DWORD)(LPVOID)&mciOpenParms);
	m_MCIDeviceID=mciOpenParms.wDeviceID;
	MCI_PLAY_PARMS mciPlayParms;
	mciPlayParms.dwFrom=0;  //���ļ���ʼ����ʼ����
	mciSendCommand(m_MCIDeviceID,MCI_PLAY,MCI_FROM,
	(DWORD)(LPVOID)&mciPlayParms);
	
    MessageBox("��ϲ��ϲ����","�¶���",MB_OK);
	
	mciSendCommand(m_MCIDeviceID,MCI_STOP,MCI_WAIT,NULL); //ֹͣ����
	mciSendCommand(m_MCIDeviceID,MCI_CLOSE,MCI_WAIT,NULL); //�ر�MCI�豸
	GetDlgItem(IDC_NEXT)->EnableWindow(TRUE);
    }
 	count=count+1;
	if(count==8)
	{	MessageBox("������8�Σ������ٲ������Ʒ��������һ���л���Ʒ��",MB_OK);
		GetDlgItem(IDC_CONFIRM)->EnableWindow(FALSE);//�ر�ȷ�ϰ�ť
		GetDlgItem(IDC_NEXT)->EnableWindow(TRUE);//������һ���༭��
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
	//�˶�Դ�����԰ٶ��Ŀ⣬�޸ĺ�ʹ��
	  count=0;
	  m_TIMES=0;
	  m_INPUT=0;    //���input
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
	 GetDlgItem(IDC_NEXT)->EnableWindow(FALSE);//������һ����ť
	 GetDlgItem(IDC_CONFIRM)->EnableWindow(TRUE);//����ȷ�ϰ�ť
}

void CMy52Dlg::OnPlay() 
{
	// TODO: Add your control notification handler code here
}

void CMy52Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
		MessageBox("1.��������ʼ����ť����Ϸ��ʼ��ϵͳ��������Ʒ��\n2.����֮����ܵ����һ����\n3.��Ѹ���������Ĺ��ۣ��������ȷ�ϡ���ť��\n4��ʱϵͳ����ʾ�����Ƶ���Ʒ�۸���˻��ǵ��ˣ��ڵ����ĶԻ���\n ������ȷ�ϡ���ť���ٴ������µĹ�ֵ���ظ���һ����ֱ���õ���\n ȷ�Ľ��,��ʱϵͳ����ʾ���н���!");	
	
}
