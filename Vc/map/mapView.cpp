// mapView.cpp : implementation of the CMapView class
//

#include "stdafx.h"
#include "map.h"
#include "math.h"
#include "mapDoc.h"
#include "mapView.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMapView

IMPLEMENT_DYNCREATE(CMapView, CView)

BEGIN_MESSAGE_MAP(CMapView, CView)
	//{{AFX_MSG_MAP(CMapView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMapView construction/destruction

CMapView::CMapView()
{
	// TODO: add construction code here

}

CMapView::~CMapView()
{
}

BOOL CMapView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMapView drawing

void CMapView::OnDraw(CDC* pDC)
{
	CMapDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	for(int i=0;i<7;i++)
		{
		//��һ������������
		CFont NewFont;
		//����CreateFont��Ա����ʵ�ʴ�������
		NewFont.CreateFont(30-i,0,300*i,0,400,FALSE,FALSE,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH&FF_SWISS,"Arial");
		//�ڶ��������µ�����ѡ���豸�����������������
		CFont * pOldFont=(CFont *)pDC->SelectObject(&NewFont);
		//��TextOut����ı�
		pDC->TextOut(100*cos(3.1415926/6.0*i)+300,-100*sin(3.1415926/6.0*i)+300,"���ֵ�������");
		//���������ָ��豸�����еľ�����
		pDC->SelectObject(pOldFont);
		}
}

/////////////////////////////////////////////////////////////////////////////
// CMapView printing

BOOL CMapView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMapView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMapView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMapView diagnostics

#ifdef _DEBUG
void CMapView::AssertValid() const
{
	CView::AssertValid();
}

void CMapView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMapDoc* CMapView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMapDoc)));
	return (CMapDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMapView message handlers
