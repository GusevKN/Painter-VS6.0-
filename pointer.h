// pointer.h : main header file for the POINTER application
//

#if !defined(AFX_POINTER_H__646F624B_DB3A_4C43_B1CB_91B503F25988__INCLUDED_)
#define AFX_POINTER_H__646F624B_DB3A_4C43_B1CB_91B503F25988__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPointerApp:
// See pointer.cpp for the implementation of this class
//

class CPointerApp : public CWinApp
{
public:
	CPointerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPointerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPointerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POINTER_H__646F624B_DB3A_4C43_B1CB_91B503F25988__INCLUDED_)
