// CDRemove.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "CDRemove.h"
#include "afxdialogex.h"


// CDRemove dialog

IMPLEMENT_DYNAMIC(CDRemove, CDialog)

CDRemove::CDRemove(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DLG_REMOVE, pParent)
	, m_StockText(_T(""))
	, m_QText(_T(""))
{

}

CDRemove::~CDRemove()
{
}

void CDRemove::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_StockText);
	DDX_Text(pDX, IDC_EDIT2, m_QText);
}


BEGIN_MESSAGE_MAP(CDRemove, CDialog)
END_MESSAGE_MAP()


// CDRemove message handlers
