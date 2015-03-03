// documentView.h : interface of the CDocumentView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DOCUMENTVIEW_H__1E817689_5DCA_4EF1_ABB3_45D61FD9FD11__INCLUDED_)
#define AFX_DOCUMENTVIEW_H__1E817689_5DCA_4EF1_ABB3_45D61FD9FD11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDocumentView : public CView
{
protected: // create from serialization only
	CDocumentView();
	DECLARE_DYNCREATE(CDocumentView)

// Attributes
public:
	CDocumentDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDocumentView)
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
	virtual ~CDocumentView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDocumentView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in documentView.cpp
inline CDocumentDoc* CDocumentView::GetDocument()
   { return (CDocumentDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOCUMENTVIEW_H__1E817689_5DCA_4EF1_ABB3_45D61FD9FD11__INCLUDED_)
