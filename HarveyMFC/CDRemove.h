#pragma once


// CDRemove dialog

class CDRemove : public CDialog
{
	DECLARE_DYNAMIC(CDRemove)

public:
	CDRemove(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDRemove();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_REMOVE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_StockText;
	CString m_QText;
};
