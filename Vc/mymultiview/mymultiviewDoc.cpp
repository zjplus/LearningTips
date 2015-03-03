// mymultiviewDoc.cpp : implementation of the CMymultiviewDoc class
//

#include "stdafx.h"
#include "mymultiview.h"

#include "mymultiviewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMymultiviewDoc

IMPLEMENT_DYNCREATE(CMymultiviewDoc, CDocument)

BEGIN_MESSAGE_MAP(CMymultiviewDoc, CDocument)
	//{{AFX_MSG_MAP(CMymultiviewDoc)
	ON_COMMAND(ID_C, OnC)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMymultiviewDoc construction/destruction

CMymultiviewDoc::CMymultiviewDoc()
{
	// TODO: add one-time construction code here

}

CMymultiviewDoc::~CMymultiviewDoc()
{
}

BOOL CMymultiviewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMymultiviewDoc serialization

void CMymultiviewDoc::Serialize(CArchive& ar)
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
// CMymultiviewDoc diagnostics

#ifdef _DEBUG
void CMymultiviewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMymultiviewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMymultiviewDoc commands

void CMymultiviewDoc::OnC() 
{
	// TODO: Add your command handler code here
	this->DeleteContents();
	this->UpdateAllViews(NULL);
	
}
