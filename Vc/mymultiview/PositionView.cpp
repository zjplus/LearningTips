// PositionView.cpp : implementation file
//

#include "stdafx.h"
#include "mymultiview.h"
#include "PositionView.h"
#include "MymultiviewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPositionView

IMPLEMENT_DYNCREATE(CPositionView, CView)

CPositionView::CPositionView()
{
}

CPositionView::~CPositionView()
{
}


BEGIN_MESSAGE_MAP(CPositionView, CView)
	//{{AFX_MSG_MAP(CPositionView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPositionView drawing

void CPositionView::OnDraw(CDC* pDC)
{
	CMymultiviewDoc* pDoc = (CMymultiviewDoc*)GetDocument();
	// TODO: add draw code here
	COblist* pList=(COblist*)pDoc->GetLineList();
	POSITION pos=pList->GetHeadPosition();
	CSTRING zuobiao;
	int i;
	i=1;
	while(pos!=NULL)
	{
		Cline* pLine=(Cline)(pList->GetNext(pos));
		zuobiao.Format("线段%d的起点和终点分别是：(%d,%d)和(%d,%d)"),
			i,pLine->m_Start.x,pLine->m_Start.y,pLine->m_End.x,pLine->m_End.y);
		pDC->TextOut(10,20*i,zuobiao);
		i++;
	}

}

/////////////////////////////////////////////////////////////////////////////
// CPositionView diagnostics

#ifdef _DEBUG
void CPositionView::AssertValid() const
{
	CView::AssertValid();
}

void CPositionView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPositionView message handlers
