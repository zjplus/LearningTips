// drawlineView.h : interface of the CDrawlineView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWLINEVIEW_H__E4F97730_72E7_4F3C_B734_2B40001AFD44__INCLUDED_)
#define AFX_DRAWLINEVIEW_H__E4F97730_72E7_4F3C_B734_2B40001AFD44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include"line.h"


class CDrawlineView : public CScrollView
{
protected: // create from serialization only
	CDrawlineView();
	DECLARE_DYNCREATE(CDrawlineView)

// Attributes
public:
	CDrawlineDoc* GetDocument();
	CPoint m_ptEnd;
	CPoint m_ptStart;
	CPoint ptOrg;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawlineView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDrawlineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawlineView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in drawlineView.cpp
inline CDrawlineDoc* CDrawlineView::GetDocument()
   { return (CDrawlineDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWLINEVIEW_H__E4F97730_72E7_4F3C_B734_2B40001AFD44__INCLUDED_)
