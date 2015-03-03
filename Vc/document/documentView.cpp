// documentView.cpp : implementation of the CDocumentView class
//

#include "stdafx.h"
#include "document.h"

#include "documentDoc.h"
#include "documentView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDocumentView

IMPLEMENT_DYNCREATE(CDocumentView, CView)

BEGIN_MESSAGE_MAP(CDocumentView, CView)
	//{{AFX_MSG_MAP(CDocumentView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDocumentView construction/destruction

CDocumentView::CDocumentView()
{
	// TODO: add construction code here

}

CDocumentView::~CDocumentView()
{
}

BOOL CDocumentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDocumentView drawing

void CDocumentView::OnDraw(CDC* pDC)
{
	CDocumentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here


	CRect rcView;
	GetClientRect(rcView);
	//Create sample string to display.
	CString str(_T ("Awesome Shadow Text£®£®£®"));
	pDC->SetBkMode(TRANSPARENT);
	//Draw black shadow text.
	rcView.OffsetRect (1,1);
	pDC->SetTextColor(RGB(0,0,0));
	pDC->DrawText(str,str.GetLength(), rcView,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
	//Draw red text.
	rcView.OffsetRect (-1,-1);
	pDC->SetTextColor (RGB (255, 0, 0));
	pDC->DrawText (str,str.GetLength(),rcView,DT_SINGLELINE|DT_CENTER|DT_VCENTER);



	pDC->DrawText(CString("This is a  long string"),
				  CRect(10,10,80,30),DT_LEFT|DT_END_ELLIPSIS);

	//Add ellpsis to middle of string if it does not fit
	pDC->DrawText(AfxGetApp()->m_pszHelpFilePath,
				  CRect(10,40,800,60),DT_LEFT|DT_PATH_ELLIPSIS);
	

	HICON hIcon=::ExtractIcon(AfxGetInstanceHandle(),
	_T("NotePad.exe"),0);
	if (hIcon &&hIcon!=(HICON)-1)
	pDC->DrawIcon(10,80,hIcon);

	HICON HIcon=AfxGetApp()->LoadStandardIcon(IDI_QUESTION);
	ASSERT(HIcon);
	AfxGetMainWnd()->SendMessage(WM_SETICON,TRUE,(LPARAM)HIcon);

	for(int i=0;i<6;i++)
	{Sleep(200);
	HICON hIcon=::LoadIcon(NULL,(LPCTSTR)(32512+i));
	if (hIcon&&hIcon!=(HICON)-1)
	pDC->DrawIcon(100+50*i,100,hIcon);}
		

}

/////////////////////////////////////////////////////////////////////////////
// CDocumentView printing

BOOL CDocumentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDocumentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDocumentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDocumentView diagnostics

#ifdef _DEBUG
void CDocumentView::AssertValid() const
{
	CView::AssertValid();
}

void CDocumentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDocumentDoc* CDocumentView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDocumentDoc)));
	return (CDocumentDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDocumentView message handlers
