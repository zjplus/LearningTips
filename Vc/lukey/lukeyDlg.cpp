// lukeyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "lukey.h"
#include "lukeyDlg.h"

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
// CLukeyDlg dialog

CLukeyDlg::CLukeyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLukeyDlg::IDD, pParent)
{	

	/* goods[0]="С��2";
	 goods[1]="С��3";
	 goods[2]="С�׺���";
	 goods[3]="С�׵���";
	 goods[4]="С��·����";

	 price[0]=1799;
	 price[1]=1999;
	 price[2]=299;
	 price[3]=2999;
	 price[4]=799;
	 num=1;

	 Bitmap[0].LoadBitmap(IDB_MI2);
	 Bitmap[1].LoadBitmap(IDB_MI3);
	 Bitmap[2].LoadBitmap(IDB_MIBOX);
	 Bitmap[3].LoadBitmap(IDB_MITV);
	 Bitmap[4].LoadBitmap(IDB_MIWIFI);*/

	//{{AFX_DATA_INIT(CLukeyDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLukeyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLukeyDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLukeyDlg, CDialog)
	//{{AFX_MSG_MAP(CLukeyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Go, OnGo)
	ON_BN_CLICKED(IDC_RULE, OnRule)
	ON_BN_CLICKED(IDC_NEXTONE, OnNextone)
	ON_BN_CLICKED(IDC_CONFIRM, OnConfirm)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLukeyDlg message handlers

BOOL CLukeyDlg::OnInitDialog()
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
	GetDlgItem(IDC_INPUT)->EnableWindow(FALSE);//���ù��۱༭��
	GetDlgItem(IDC_CONFIRM)->EnableWindow(FALSE);//����ȷ����ť
	GetDlgItem(IDC_NEXTONE)->EnableWindow(FALSE);//������һ����ť

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLukeyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLukeyDlg::OnPaint() 
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
HCURSOR CLukeyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLukeyDlg::OnChangeShow() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CLukeyDlg::OnGo() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_INPUT)->EnableWindow(TRUE);//�������۱༭��
	GetDlgItem(IDC_CONFIRM)->EnableWindow(TRUE);//����ȷ����ť
	GetDlgItem(IDC_INPUT)->SetFocus();//�����ʼ��ʱ��۽��������༭��
	
}

void CLukeyDlg::OnRule() 
{
	// TODO: Add your control notification handler code here
	MessageBox("1.��������ʼ����ť����Ϸ��ʼ��ϵͳ��������Ʒ��\n2.��Ѹ���������Ĺ��ۣ��������ȷ�ϡ���ť��\n3��ʱϵͳ����ʾ�����Ƶ���Ʒ�۸���˻��ǵ��ˣ��ڵ����ĶԻ���\n ������ȷ�ϡ���ť���ٴ������µĹ�ֵ���ظ���һ����ֱ���õ���\n ȷ�Ľ��,��ʱϵͳ����ʾ���н���!");	
	
}

void CLukeyDlg::OnOK() 
{
	// TODO: Add extra validation here
	MessageBox("��Ϸ������ллʹ�ã�","�˳���Ϸ",MB_OK);
	CDialog::OnOK();
}

void CLukeyDlg::OnNextone() 
{
	// TODO: Add your control notification handler code here
/*	m_INPUT=0;    //���INPUT
  srand(time(NULL));
  num=rand()%5;
  m_NEXTONE("%s",goods[num]);
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
	((CStatic *)GetDlgItem(IDC_PICTURE))->SetBitmap(HBITMAP(  Bitmap[4]) );*/
}

void CLukeyDlg::OnConfirm() 
{
	// TODO: Add your control notification handler code here
	
}
