// drawlineView.cpp : implementation of the CDrawlineView class
//

#include "stdafx.h"
#include "drawline.h"

#include "drawlineDoc.h"
#include "drawlineView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawlineView

IMPLEMENT_DYNCREATE(CDrawlineView, CView)

BEGIN_MESSAGE_MAP(CDrawlineView, CView)
	//{{AFX_MSG_MAP(CDrawlineView)
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
// CDrawlineView construction/destruction

CDrawlineView::CDrawlineView()
{
	m_ptEnd=0;
	m_ptStart=0;// TODO: add construction code here

}

CDrawlineView::~CDrawlineView()
{
}

BOOL CDrawlineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawlineView drawing

void CDrawlineView::OnDraw(CDC* pDC)
{
	CDrawlineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CObList* pList=(CObList*)pDoc->GetLineList();
	POSITION pos=pList->GetHeadPosition();
	while (pos!=NULL)
	{
		class Cline* pLine=(Cline*)(pList->GetNext(pos));
		pLine->DrawLine(pDC);
	}

}

/////////////////////////////////////////////////////////////////////////////
// CDrawlineView printing

BOOL CDrawlineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawlineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawlineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDrawlineView diagnostics

#ifdef _DEBUG
void CDrawlineView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawlineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawlineDoc* CDrawlineView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawlineDoc)));
	return (CDrawlineDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawlineView message handlers

void CDrawlineView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SetCapture();
	m_ptStart=m_ptEnd=point;

	ptOrg=GetScrollPosition();

	CView::OnLButtonDown(nFlags, point);
}

void CDrawlineView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (GetCapture()!=this)
		return;
	CClientDC dc(this);
	m_ptEnd=point;
	dc.MoveTo(m_ptStart);
	dc.LineTo(m_ptEnd);

	m_ptStart+=ptOrg;
	m_ptEnd=point+ptOrg;

	if (m_ptStart!=m_ptEnd)
	{
		Cline* pLine =new Cline(m_ptStart,m_ptEnd);
		CDrawlineDoc*pDoc=GetDocument();
		CObList* pList=(CObList*)pDoc->GetLineList();
		pList->AddTail(pLine);
		pDoc->UpdateAllViews(this,NULL,NULL);
		pDoc->SetModifiedFlag(TRUE);;
	};

	ReleaseCapture();
		
	
	CView::OnLButtonUp(nFlags, point);
}

void CDrawlineView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (GetCapture()!=this)
		return;
	CClientDC dc(this);
	CPen newPen(1,1,RGB(12,21,255));
	CPen* oldPen=dc.SelectObject(&newPen);
	int nOldMode=dc.SetROP2(R2_NOTXORPEN);
	dc.MoveTo(m_ptStart);
	dc.LineTo(m_ptEnd);
	dc.SelectObject(oldPen);
	dc.SetROP2(nOldMode);
	
	CView::OnMouseMove(nFlags, point);
}

void CDrawlineView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
        CSize Totalsize;
	Totalsize.cx=Totalsize.cy=2000; //滚动视图的大小
	SetScrollSizes(MM_TEXT,Totalsize); //设置滚动视图的映射模式和大小
		
}
