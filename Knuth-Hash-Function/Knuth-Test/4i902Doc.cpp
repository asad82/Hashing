// 4i902Doc.cpp : implementation of the CMy4i902Doc class
//

#include "stdafx.h"
#include "4i902.h"

#include "4i902Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy4i902Doc

IMPLEMENT_DYNCREATE(CMy4i902Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy4i902Doc, CDocument)
	//{{AFX_MSG_MAP(CMy4i902Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy4i902Doc construction/destruction

CMy4i902Doc::CMy4i902Doc()
{
	// TODO: add one-time construction code here

}

CMy4i902Doc::~CMy4i902Doc()
{
}

BOOL CMy4i902Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMy4i902Doc serialization

void CMy4i902Doc::Serialize(CArchive& ar)
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
// CMy4i902Doc diagnostics

#ifdef _DEBUG
void CMy4i902Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy4i902Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy4i902Doc commands
