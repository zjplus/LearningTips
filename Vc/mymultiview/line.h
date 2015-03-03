// line.h: interface for the Cline class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__E4BC1D4B_3A42_48FD_A4E8_EFC823B27F00__INCLUDED_)
#define AFX_LINE_H__E4BC1D4B_3A42_48FD_A4E8_EFC823B27F00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Cline : public CObject 
{
public:
	CPoint m_Start;   //线段起点
	CPoint m_End;    //线段终点
public:
	Cline();
	virtual ~Cline();
	Cline(CPoint Start, CPoint End);
	void DrawLine(CDC* pDC);   //绘制线段

protected:
	virtual void Serialize(CArchive &ar);
	DECLARE_SERIAL(Cline)

};




#endif // !defined(AFX_LINE_H__E4BC1D4B_3A42_48FD_A4E8_EFC823B27F00__INCLUDED_)
