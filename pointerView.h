// pointerView.h : interface of the CPointerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_POINTERVIEW_H__1A1F69CA_D5AD_4F73_AC95_F5E54BAEF620__INCLUDED_)
#define AFX_POINTERVIEW_H__1A1F69CA_D5AD_4F73_AC95_F5E54BAEF620__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPointerView : public CView
{
protected: // create from serialization only
	CPointerView();
	DECLARE_DYNCREATE(CPointerView)

// Attributes
public:
	CPointerDoc* GetDocument();

// Operations
public:
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPointerView)
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
	virtual ~CPointerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CPoint Anchor;
	CPoint DrawTo;
	CPoint OldPoint;
	boolean bDrawFlag;
	boolean bLineFlag;
	boolean bRectangleFlag;
	boolean bEllipseFlag;
	boolean bFillFlag;
	void MakeAllFlagsFalse();
// Generated message map functions
protected:
	//{{AFX_MSG(CPointerView)
	afx_msg void OnToolsDrawfreehand();
	afx_msg void OnToolsEllipse();
	afx_msg void OnToolsFillfigure();
	afx_msg void OnToolsLine();
	afx_msg void OnToolsRectangle();
	afx_msg void OnUpdateToolsDrawfreehand(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolsEllipse(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolsFillfigure(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolsLine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolsRectangle(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnFileSave();
	afx_msg void OnFileNew();
	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in pointerView.cpp
inline CPointerDoc* CPointerView::GetDocument()
   { return (CPointerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POINTERVIEW_H__1A1F69CA_D5AD_4F73_AC95_F5E54BAEF620__INCLUDED_)
