// CDAdd.cpp : implementation file
//

#include "stdafx.h"
#include "CDAdd.h"
#include "resource.h"
#include "afxdialogex.h"


// CDAdd dialog

IMPLEMENT_DYNAMIC(CDAdd, CDialog)

CDAdd::CDAdd(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DLG_ADD, pParent)
	, m_StockText(_T(""))
	, m_QText(_T(""))
{

}

CDAdd::~CDAdd()
{
}

void CDAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_StockText);
	DDX_Text(pDX, IDC_EDIT2, m_QText);
}


BEGIN_MESSAGE_MAP(CDAdd, CDialog)
END_MESSAGE_MAP()


// CDAdd message handlers
