// drawlineDoc.h : interface of the CDrawlineDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWLINEDOC_H__DA72602A_C9E0_483D_89AD_605461F6B3C0__INCLUDED_)
#define AFX_DRAWLINEDOC_H__DA72602A_C9E0_483D_89AD_605461F6B3C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDrawlineDoc : public CDocument
{
protected: // create from serialization only
	CDrawlineDoc();
	DECLARE_DYNCREATE(CDrawlineDoc)

// Attributes
public:

// Operations
	public:
		CObject* GetLineList();//获取当前线段的列表
		void DeleteContents();

	protected:
		CObList m_Linelist;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawlineDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDrawlineDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawlineDoc)
	afx_msg void Ondelete();
	afx_msg void Onsavedoc();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWLINEDOC_H__DA72602A_C9E0_483D_89AD_605461F6B3C0__INCLUDED_)
