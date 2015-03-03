// mymultiviewView.cpp : implementation of the CMymultiviewView class
//

#include "stdafx.h"
#include "mymultiview.h"

#include "mymultiviewDoc.h"
#include "mymultiviewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMymultiviewView

IMPLEMENT_DYNCREATE(CMymultiviewView, CView)

BEGIN_MESSAGE_MAP(CMymultiviewView, CView)
	//{{AFX_MSG_MAP(CMymultiviewView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMymultiviewView construction/destruction




CMymultiviewView::CMymultiviewView()
{
	// TODO: add construction code here
	m_ptEnd=0;
	m_ptStart=0;

}

CMymultiviewView::~CMymultiviewView()
{
}

BOOL CMymultiviewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMymultiviewView drawing

void CMymultiviewView::OnDraw(CDC* pDC)
{
	CMymultiviewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMymultiviewView printing

BOOL CMymultiviewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMymultiviewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMymultiviewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMymultiviewView diagnostics

#ifdef _DEBUG
void CMymultiviewView::AssertValid() const
{
	CView::AssertValid();
}

void CMymultiviewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMymultiviewDoc* CMymultiviewView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMymultiviewDoc)));
	return (CMymultiviewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMymultiviewView message handlers

void CMymultiviewView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SetCapture();
	m_ptStart=m_ptEnd=point;
	
	CView::OnLButtonDown(nFlags, point);
}

void CMymultiviewView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (GetCapture()!=this)
		return;
	CClientDC dc(this);
	m_ptEnd=point;
	dc.MoveTo(m_ptStart);
	dc.LineTo(m_ptEnd);
	ReleaseCapture();
	
	CView::OnLButtonUp(nFlags, point);
}

void CMymultiviewView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (GetCapture()!=this)
		return;
	CClientDC dc(this);
	CPen newPen(1,1,RGB(0,0,255));
	CPen* oldPen=dc.SelectObject(&newPen);
	int nOldMode=dc.SetROP2(R2_NOTXORPEN);
	dc.MoveTo(m_ptStart);
	dc.LineTo(m_ptEnd);
	dc.SelectObject(oldPen);
	dc.SetROP2(nOldMode);
		
	
	CView::OnMouseMove(nFlags, point);
}
