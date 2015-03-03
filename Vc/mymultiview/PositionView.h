#if !defined(AFX_POSITIONVIEW_H__B2A09207_B010_4347_839B_9BF1ECB044FA__INCLUDED_)
#define AFX_POSITIONVIEW_H__B2A09207_B010_4347_839B_9BF1ECB044FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PositionView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPositionView view

class CPositionView : public CView
{
protected:
	CPositionView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CPositionView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPositionView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CPositionView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CPositionView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POSITIONVIEW_H__B2A09207_B010_4347_839B_9BF1ECB044FA__INCLUDED_)
