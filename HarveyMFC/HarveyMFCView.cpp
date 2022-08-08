
// HarveyMFCView.cpp : implementation of the CHarveyMFCView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "HarveyMFC.h"
#endif

#include "HarveyMFCDoc.h"
#include "HarveyMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHarveyMFCView

IMPLEMENT_DYNCREATE(CHarveyMFCView, CView)

BEGIN_MESSAGE_MAP(CHarveyMFCView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CHarveyMFCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CHarveyMFCView construction/destruction

CHarveyMFCView::CHarveyMFCView() noexcept
{
	// TODO: add construction code here

}

CHarveyMFCView::~CHarveyMFCView()
{
}

BOOL CHarveyMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CHarveyMFCView drawing

void CHarveyMFCView::OnDraw(CDC* /*pDC*/)
{
	CHarveyMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CHarveyMFCView printing


void CHarveyMFCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CHarveyMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHarveyMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHarveyMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CHarveyMFCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CHarveyMFCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CHarveyMFCView diagnostics

#ifdef _DEBUG
void CHarveyMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CHarveyMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHarveyMFCDoc* CHarveyMFCView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHarveyMFCDoc)));
	return (CHarveyMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CHarveyMFCView message handlers
