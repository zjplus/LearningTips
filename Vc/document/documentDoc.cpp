// documentDoc.cpp : implementation of the CDocumentDoc class
//

#include "stdafx.h"
#include "document.h"

#include "documentDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDocumentDoc

IMPLEMENT_DYNCREATE(CDocumentDoc, CDocument)

BEGIN_MESSAGE_MAP(CDocumentDoc, CDocument)
	//{{AFX_MSG_MAP(CDocumentDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDocumentDoc construction/destruction

CDocumentDoc::CDocumentDoc()
{
	// TODO: add one-time construction code here

}

CDocumentDoc::~CDocumentDoc()
{
}

BOOL CDocumentDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDocumentDoc serialization

void CDocumentDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDocumentDoc diagnostics

#ifdef _DEBUG
void CDocumentDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDocumentDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDocumentDoc commands
