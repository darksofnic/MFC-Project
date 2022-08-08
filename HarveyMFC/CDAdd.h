#pragma once


// CDAdd dialog

class CDAdd : public CDialog
{
	DECLARE_DYNAMIC(CDAdd)

public:
	CDAdd(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDAdd();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_ADD};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_StockText;
	CString m_QText;
};
