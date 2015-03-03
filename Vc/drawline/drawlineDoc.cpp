// drawlineDoc.cpp : implementation of the CDrawlineDoc class
//

#include "stdafx.h"
#include "drawline.h"

#include "drawlineDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawlineDoc

IMPLEMENT_DYNCREATE(CDrawlineDoc, CDocument)

BEGIN_MESSAGE_MAP(CDrawlineDoc, CDocument)
	//{{AFX_MSG_MAP(CDrawlineDoc)
	ON_COMMAND(ID_delete, Ondelete)
	ON_COMMAND(ID_savedoc, Onsavedoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawlineDoc construction/destruction

CDrawlineDoc::CDrawlineDoc()
{
	// TODO: add one-time construction code here

}

CDrawlineDoc::~CDrawlineDoc()
{
}

BOOL CDrawlineDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

CObject* CDrawlineDoc::GetLineList()
{
	return (&m_Linelist);
}

void CDrawlineDoc::DeleteContents()
{ 
	while(m_Linelist.GetHeadPosition())
		delete m_Linelist.RemoveHead();
	CDocument::DeleteContents();
}

/////////////////////////////////////////////////////////////////////////////
// CDrawlineDoc serialization

void CDrawlineDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
	m_Linelist.Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawlineDoc diagnostics

#ifdef _DEBUG
void CDrawlineDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawlineDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawlineDoc commands



void CDrawlineDoc::Ondelete() 
{
	// TODO: Add your command handler code here
	this->DeleteContents();
	this->UpdateAllViews(NULL);

}

void CDrawlineDoc::Onsavedoc() 
{
	// TODO: Add your command handler code here
}
