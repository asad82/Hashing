// 4i902View.h : interface of the CMy4i902View class
//
/////////////////////////////////////////////////////////////////////////////

#include "afxwin.h"
#if !defined(AFX_4I902VIEW_H__28F3E29D_B8E3_4DA3_969A_408CF5ED2945__INCLUDED_)
#define AFX_4I902VIEW_H__28F3E29D_B8E3_4DA3_969A_408CF5ED2945__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy4i902View : public CFormView
{
protected: // create from serialization only
	CMy4i902View();
	DECLARE_DYNCREATE(CMy4i902View)

public:
	//{{AFX_DATA(CMy4i902View)
	enum { IDD = IDD_MY4I902_FORM };
	int		m_TotalWordsRead;
	//}}AFX_DATA

// Attributes
public:
	CMy4i902Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy4i902View)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy4i902View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy4i902View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCalculate();
	CListBox m_List1;
	CString m_FileName;
	int m_TableSize;
	int m_Selection;
	double m_A;
	int m_Selection2;
	int m_Selection3;
	int totalWordsRead;
};

#ifndef _DEBUG  // debug version in 4i902View.cpp
inline CMy4i902Doc* CMy4i902View::GetDocument()
   { return (CMy4i902Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_4I902VIEW_H__28F3E29D_B8E3_4DA3_969A_408CF5ED2945__INCLUDED_)
