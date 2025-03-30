// pointerView.cpp : implementation of the CPointerView class
//

#include "stdafx.h"
#include "pointer.h"

#include "pointerDoc.h"
#include "pointerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPointerView

IMPLEMENT_DYNCREATE(CPointerView, CView)

BEGIN_MESSAGE_MAP(CPointerView, CView)
	//{{AFX_MSG_MAP(CPointerView)
	ON_COMMAND(ID_TOOLS_DRAWFREEHAND, OnToolsDrawfreehand)
	ON_COMMAND(ID_TOOLS_ELLIPSE, OnToolsEllipse)
	ON_COMMAND(ID_TOOLS_FILLFIGURE, OnToolsFillfigure)
	ON_COMMAND(ID_TOOLS_LINE, OnToolsLine)
	ON_COMMAND(ID_TOOLS_RECTANGLE, OnToolsRectangle)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_DRAWFREEHAND, OnUpdateToolsDrawfreehand)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_ELLIPSE, OnUpdateToolsEllipse)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_FILLFIGURE, OnUpdateToolsFillfigure)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_LINE, OnUpdateToolsLine)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_RECTANGLE, OnUpdateToolsRectangle)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPointerView construction/destruction

CPointerView::CPointerView()
{
	MakeAllFlagsFalse();
	// TODO: add construction code here

}

CPointerView::~CPointerView()
{

}

BOOL CPointerView::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = AfxRegisterWndClass(CS_DBLCLKS,
		AfxGetApp()->LoadStandardCursor(IDC_CROSS),
		(HBRUSH)(COLOR_WINDOW+1),
		AfxGetApp()->LoadIcon(IDR_MAINFRAME));
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPointerView drawing

void CPointerView::OnDraw(CDC* pDC)
{
	CPointerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	HMETAFILE MetaFileHandle = pDoc->pMetaFileDC->Close();
	pDC->PlayMetaFile(MetaFileHandle);
	CMetaFileDC* ReplacementMetaFile = new CMetaFileDC();
	ReplacementMetaFile->Create();
	ReplacementMetaFile->PlayMetaFile(MetaFileHandle);
	DeleteMetaFile(MetaFileHandle);
	delete pDoc->pMetaFileDC;
	pDoc->pMetaFileDC = ReplacementMetaFile;
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CPointerView printing

BOOL CPointerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPointerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPointerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPointerView diagnostics

#ifdef _DEBUG
void CPointerView::AssertValid() const
{
	CView::AssertValid();
}

void CPointerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPointerDoc* CPointerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPointerDoc)));
	return (CPointerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPointerView message handlers
void CPointerView::MakeAllFlagsFalse()
{
	bDrawFlag = false;
	bLineFlag = false;
	bRectangleFlag = false;
	bEllipseFlag = false;
	bFillFlag = false;
}

void CPointerView::OnToolsDrawfreehand() 
{
	MakeAllFlagsFalse();
	bDrawFlag = true;
	// TODO: Add your command handler code here
	
}

void CPointerView::OnToolsEllipse() 
{
	MakeAllFlagsFalse();
	bEllipseFlag = true;
	// TODO: Add your command handler code here
	
}

void CPointerView::OnToolsFillfigure() 
{
	MakeAllFlagsFalse();
	bFillFlag = true;
	// TODO: Add your command handler code here
	
}

void CPointerView::OnToolsLine() 
{
	MakeAllFlagsFalse();
	bLineFlag = true;
	// TODO: Add your command handler code here
	
}

void CPointerView::OnToolsRectangle() 
{
	MakeAllFlagsFalse();
	bRectangleFlag = true;

	// TODO: Add your command handler code here
	
}

void CPointerView::OnUpdateToolsDrawfreehand(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(bDrawFlag);
	// TODO: Add your command update UI handler code here
	
}

void CPointerView::OnUpdateToolsEllipse(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(bEllipseFlag);
	// TODO: Add your command update UI handler code here
	
}

void CPointerView::OnUpdateToolsFillfigure(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(bFillFlag);
	// TODO: Add your command update UI handler code here
	
}

void CPointerView::OnUpdateToolsLine(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(bLineFlag);
	// TODO: Add your command update UI handler code here
	
}

void CPointerView::OnUpdateToolsRectangle(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(bRectangleFlag);
	// TODO: Add your command update UI handler code here
	
}

void CPointerView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	Anchor.x = point.x;
	Anchor.y = point.y;
	OldPoint.x = Anchor.x;
	OldPoint.y = Anchor.y;
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDown(nFlags, point);
}

void CPointerView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CPointerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	DrawTo.x = point.x;
	DrawTo.y = point.y;
	CClientDC* pDC = new CClientDC(this);
	if(bLineFlag){
		pDC->MoveTo(Anchor.x, Anchor.y);
		pDC->LineTo(DrawTo.x, DrawTo.y);
		pDoc->pMetaFileDC->MoveTo(Anchor.x, Anchor.y);
		pDoc->pMetaFileDC->LineTo(DrawTo.x, DrawTo.y);
	}
	if(bRectangleFlag){
		pDC->SelectStockObject(NULL_BRUSH);
		pDC->Rectangle(Anchor.x,Anchor.y,DrawTo.x,DrawTo.y);
		pDoc->pMetaFileDC->SelectStockObject(NULL_BRUSH);
		pDoc->pMetaFileDC->Rectangle(Anchor.x, Anchor.y, DrawTo.x,DrawTo.y);
	}
	if(bEllipseFlag){
		pDC->SelectStockObject(NULL_BRUSH);
		pDC->Ellipse(Anchor.x,Anchor.y,DrawTo.x,DrawTo.y);
		pDoc->pMetaFileDC->SelectStockObject(NULL_BRUSH);
		pDoc->pMetaFileDC->Ellipse(Anchor.x,Anchor.y,DrawTo.x,DrawTo.y);
	}
	if(bFillFlag){
		pDC->SelectStockObject(BLACK_BRUSH);
		pDC->FloodFill(Anchor.x,Anchor.y, RGB(0,0,0));
		pDoc->pMetaFileDC->SelectStockObject(BLACK_BRUSH);
		pDoc->pMetaFileDC->FloodFill(Anchor.x,Anchor.y, RGB(0,0,0));
	}
			delete pDC;
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonUp(nFlags, point);
}

void CPointerView::OnMouseMove(UINT nFlags, CPoint point) 
{
	int nOldMode;

	CClientDC* pDC = new CClientDC(this);
	
	if((nFlags &&MK_LBUTTON) && bDrawFlag){
		pDC->MoveTo(Anchor.x,Anchor.y);
		pDC->LineTo(point.x, point.y);
		
		Anchor.x = point.x;
		Anchor.y = point.y;
	}
	if((nFlags && MK_LBUTTON) && bLineFlag){
	nOldMode = pDC->GetROP2();
	pDC->SetROP2(R2_NOT);
	pDC->MoveTo(Anchor.x,Anchor.y);
	pDC->LineTo(OldPoint.x, OldPoint.y);
	pDC->LineTo(point.x, point.y);
	OldPoint.x = point.x;
	OldPoint.y = point.y;
	pDC->SetROP2(nOldMode);
	}
	if((nFlags && MK_LBUTTON) && bRectangleFlag){
	nOldMode = pDC->GetROP2();
	pDC->SetROP2(R2_NOT);
	pDC->SelectStockObject(NULL_BRUSH);
	pDC->Rectangle(OldPoint.x, OldPoint.y, Anchor.x,Anchor.y);
	pDC->Rectangle(Anchor.x,Anchor.y, point.x, point.y);
	OldPoint.x = point.x;
	OldPoint.y = point.y;
	pDC->SetROP2(nOldMode);
	}
	if((nFlags && MK_LBUTTON) && bEllipseFlag){
	CClientDC dc(this);
	nOldMode = pDC->GetROP2();
	pDC->SetROP2(R2_NOT);
	pDC->SelectStockObject(NULL_BRUSH);
	pDC->Ellipse(OldPoint.x, OldPoint.y, Anchor.x, Anchor.y);
	pDC->Ellipse(Anchor.x,Anchor.y, point.x, point.y);
	OldPoint.x = point.x;
	OldPoint.y = point.y;
	pDC->SetROP2(nOldMode);
	}
	delete pDC;

	// TODO: Add your message handler code here and/or call default
	
	CView::OnMouseMove(nFlags, point);
}

void CPointerView::OnFileSave() 
{
	CPointerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	HMETAFILE MetaFileHandle = pDoc->pMetaFileDC->Close();
	CopyMetaFile(MetaFileHandle, "pointer.wmf");

	CMetaFileDC* ReplacementMetaFile = new CMetaFileDC();
	ReplacementMetaFile->Create();
	ReplacementMetaFile->PlayMetaFile(MetaFileHandle);
	DeleteMetaFile(MetaFileHandle);
	delete pDoc->pMetaFileDC;
	pDoc->pMetaFileDC = ReplacementMetaFile;
	// TODO: Add your command handler code here
	
}

void CPointerView::OnFileNew()
{
	CPointerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CMetaFileDC* ReplacementMetaFile = new CMetaFileDC();
	ReplacementMetaFile->Create();
	delete pDoc -> pMetaFileDC;
	pDoc->pMetaFileDC = ReplacementMetaFile;
	Invalidate();
	// TODO: Add your command handler code here

}

void CPointerView::OnFileOpen()
{
	CPointerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	HMETAFILE MetaFileHandle = GetMetaFile("pointer.wmf");
	CMetaFileDC* ReplacementMetaFile = new CMetaFileDC();
	ReplacementMetaFile->Create();
	ReplacementMetaFile->PlayMetaFile(MetaFileHandle);
	DeleteMetaFile(MetaFileHandle);
	delete pDoc->pMetaFileDC;
	pDoc->pMetaFileDC = ReplacementMetaFile;
	Invalidate();
	// TODO: Add your command handler code here

}
