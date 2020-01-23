// 4i902.h : main header file for the 4I902 application
//

#if !defined(AFX_4I902_H__B2B1B11A_8BB8_4B20_82E1_B6657E0778CD__INCLUDED_)
#define AFX_4I902_H__B2B1B11A_8BB8_4B20_82E1_B6657E0778CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy4i902App:
// See 4i902.cpp for the implementation of this class
//

class CMy4i902App : public CWinApp
{
public:
	CMy4i902App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy4i902App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMy4i902App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_4I902_H__B2B1B11A_8BB8_4B20_82E1_B6657E0778CD__INCLUDED_)
