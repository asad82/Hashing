// 4i902View.cpp : implementation of the CMy4i902View class
//
/***************************************************************************
copyright            : (C) Asad Ali
email                : asad_82@yahoo.com
website				 : sites.google.com/site/asad82
***************************************************************************/
// Programmed by Asad Ali

#include "stdafx.h"
#include "4i902.h"

#include "4i902Doc.h"
#include "4i902View.h"
#include ".\4i902view.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy4i902View

IMPLEMENT_DYNCREATE(CMy4i902View, CFormView)

BEGIN_MESSAGE_MAP(CMy4i902View, CFormView)
	//{{AFX_MSG_MAP(CMy4i902View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_CALCULATE, OnBnClickedCalculate)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy4i902View construction/destruction

CMy4i902View::CMy4i902View()
	: CFormView(CMy4i902View::IDD)
	, m_FileName(_T("D:\\Dawn.txt"))
	, m_TableSize(4)
	, m_Selection(0)
	, m_A(0.618033)
	, m_Selection2(0)
	, m_Selection3(0)
{
	//{{AFX_DATA_INIT(CMy4i902View)
	m_TotalWordsRead = 0;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CMy4i902View::~CMy4i902View()
{
}

void CMy4i902View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy4i902View)
	DDX_Text(pDX, IDC_EDIT4, m_TotalWordsRead);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_LIST1, m_List1);
	DDX_Text(pDX, IDC_EDIT1, m_FileName);
	DDX_Text(pDX, IDC_EDIT2, m_TableSize);
	DDX_Text(pDX, IDC_EDIT3, m_A);
	DDX_Radio(pDX, IDC_RADIO1, m_Selection3);
}

BOOL CMy4i902View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMy4i902View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CMy4i902View printing

BOOL CMy4i902View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy4i902View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy4i902View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMy4i902View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CMy4i902View diagnostics

#ifdef _DEBUG
void CMy4i902View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy4i902View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy4i902Doc* CMy4i902View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy4i902Doc)));
	return (CMy4i902Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy4i902View message handlers

void CMy4i902View::OnBnClickedCalculate()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	totalWordsRead=0;
	for(int j=0;j<1000;j++)
		m_List1.DeleteString(0);

	CFile filePtr;
	DWORD counter=0;

	if (!filePtr.Open(m_FileName,CFile::modeRead,NULL) )
	{	 
		MessageBox("Unable to Open file for reading.");
		return;
	}

	DWORD fileLength = filePtr.GetLength();

	// when an enter is found / new line character 13 comes first followed
	// by character 10.
	char buffer[1];
	int * remainders;
	int wIndex=0;
	int sum=0,kIndex=0;
	char word[100];

	remainders = new int [m_TableSize];

	for(int clr=0;clr<m_TableSize;clr++)
		remainders[clr]=0;

	while(counter!=fileLength)
	{

		int bytesRead = filePtr.Read(buffer,1);
		counter++;
		
		if(buffer[0]==' ' || buffer[0]==10 || buffer[0]=='.' || buffer[0]==',')
		{
			if(wIndex > 0)
			{
				sum=0;
				for(int i=0;i<wIndex;i++)
				{
					sum+=word[i];
				}// end of for loop
				if(m_Selection3==0)
					remainders[(sum%m_TableSize)]++;
				else
				{	// knuth hash index calculation
					kIndex=(int)floor(m_TableSize * (sum*m_A - floor(sum*m_A) ) );
					remainders[kIndex]++;
				}
				totalWordsRead++;
			}
			wIndex=0;
		}
		else if(buffer[0]!=13)
		{
			word[wIndex++]=buffer[0];
		}// end of else if


	}// end of while


	CString str;		

	for(int i=0;i<m_TableSize;i++)
	{
		str.Format("%d",remainders[i]);
		m_List1.AddString(str);
	}

	delete [] remainders;
	m_TotalWordsRead = totalWordsRead;
	UpdateData(false);
	

}
