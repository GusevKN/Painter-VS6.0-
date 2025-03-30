// pointerDoc.h : interface of the CPointerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_POINTERDOC_H__5663383B_92E1_432B_B5FF_A6E672A828D3__INCLUDED_)
#define AFX_POINTERDOC_H__5663383B_92E1_432B_B5FF_A6E672A828D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPointerDoc : public CDocument
{
protected: // create from serialization only
	CPointerDoc();
	DECLARE_DYNCREATE(CPointerDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPointerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPointerDoc();
	CMetaFileDC* pMetaFileDC;
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPointerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POINTERDOC_H__5663383B_92E1_432B_B5FF_A6E672A828D3__INCLUDED_)
