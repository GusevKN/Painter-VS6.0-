// pointerDoc.cpp : implementation of the CPointerDoc class
//

#include "stdafx.h"
#include "pointer.h"

#include "pointerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPointerDoc

IMPLEMENT_DYNCREATE(CPointerDoc, CDocument)

BEGIN_MESSAGE_MAP(CPointerDoc, CDocument)
	//{{AFX_MSG_MAP(CPointerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPointerDoc construction/destruction

CPointerDoc::CPointerDoc()
{
	pMetaFileDC = new CMetaFileDC();
	pMetaFileDC->Create();
	// TODO: add one-time construction code here

}

CPointerDoc::~CPointerDoc()
{
}

BOOL CPointerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPointerDoc serialization

void CPointerDoc::Serialize(CArchive& ar)
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
// CPointerDoc diagnostics

#ifdef _DEBUG
void CPointerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPointerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPointerDoc commands
