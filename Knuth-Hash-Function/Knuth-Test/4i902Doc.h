// 4i902Doc.h : interface of the CMy4i902Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_4I902DOC_H__59A98208_6B6A_41A3_8A95_BEB5F08F6A2E__INCLUDED_)
#define AFX_4I902DOC_H__59A98208_6B6A_41A3_8A95_BEB5F08F6A2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy4i902Doc : public CDocument
{
protected: // create from serialization only
	CMy4i902Doc();
	DECLARE_DYNCREATE(CMy4i902Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy4i902Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy4i902Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy4i902Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_4I902DOC_H__59A98208_6B6A_41A3_8A95_BEB5F08F6A2E__INCLUDED_)
