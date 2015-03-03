// mymultiviewView.h : interface of the CMymultiviewView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYMULTIVIEWVIEW_H__F70C69BD_E0EE_4C0D_A516_FB7E079F5200__INCLUDED_)
#define AFX_MYMULTIVIEWVIEW_H__F70C69BD_E0EE_4C0D_A516_FB7E079F5200__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMymultiviewView : public CView
{
protected: // create from serialization only
	CMymultiviewView();
	DECLARE_DYNCREATE(CMymultiviewView)

// Attributes



public:
	CMymultiviewDoc* GetDocument();
public:
	CPoint m_ptEnd;
	CPoint m_ptStart;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMymultiviewView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMymultiviewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMymultiviewView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in mymultiviewView.cpp
inline CMymultiviewDoc* CMymultiviewView::GetDocument()
   { return (CMymultiviewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMULTIVIEWVIEW_H__F70C69BD_E0EE_4C0D_A516_FB7E079F5200__INCLUDED_)
