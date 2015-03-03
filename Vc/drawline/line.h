// line.h: interface for the Cline class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__5274C960_407B_4FB3_9576_3309186E316E__INCLUDED_)
#define AFX_LINE_H__5274C960_407B_4FB3_9576_3309186E316E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Cline : public CObject  
{
public:
	CPoint m_Start;   //�߶����
	CPoint m_End;    //�߶��յ�
public:
	Cline();
	virtual ~Cline();
	Cline(CPoint Start, CPoint End);
	void DrawLine(CDC* pDC);   //�����߶�

protected:
	virtual void Serialize(CArchive &ar);
	DECLARE_SERIAL(Cline)


};

#endif // !defined(AFX_LINE_H__5274C960_407B_4FB3_9576_3309186E316E__INCLUDED_)
