// line.cpp: implementation of the Cline class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "mymultiview.h"
#include "line.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_SERIAL(Cline, CObject,1)

void Cline::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar<<m_Start<<m_End;
	}
	else
	{
		ar>>m_Start>>m_End;
	}
};

Cline::Cline()
{
	m_Start=m_End=0;

}

Cline::~Cline() { }

Cline::Cline(CPoint Start, CPoint End)
{
	m_Start=Start;
	m_End=End;
}

void Cline::DrawLine(CDC* pDC)
{ 
	pDC->MoveTo(m_Start);
	pDC->LineTo(m_End);
}
