// mymultiviewDoc.h : interface of the CMymultiviewDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYMULTIVIEWDOC_H__7A2EDEAA_5941_4984_90B9_1ACB7F4E9596__INCLUDED_)
#define AFX_MYMULTIVIEWDOC_H__7A2EDEAA_5941_4984_90B9_1ACB7F4E9596__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMymultiviewDoc : public CDocument
{
protected: // create from serialization only
	CMymultiviewDoc();
	DECLARE_DYNCREATE(CMymultiviewDoc)

// Attributes
public:

// Operations

public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMymultiviewDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMymultiviewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMymultiviewDoc)
	afx_msg void OnC();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMULTIVIEWDOC_H__7A2EDEAA_5941_4984_90B9_1ACB7F4E9596__INCLUDED_)
