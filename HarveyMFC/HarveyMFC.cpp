//
#include "stdafx.h"
#include "myLinkList.h"
#include "CDAdd.h"
#include "resource.h"
#include "CDRemove.h"
#include <afxwin.h>
#include <math.h>
#include "Resource.h"
#include <strstream>
#include <string.h>
#include <iomanip>
#define IDC_EDIT 500

// Define an application object

using namespace std;

class CApp : public CWinApp
{
public :
	virtual BOOL InitInstance();
};

const int ORIG_INV_COUNT = 10;
LinkList originalStock;
LinkList customer;
NODE item[] = { 
 {"A100", 20, "Hammer\t\t$  ", 9.95},
 {"A250", 25, "Saw\t\t\t$",13.95},
 {"B400", 50, "Flat - Head Nails/Gross       $",11.99},
 {"C888", 50, "Flat - Head Screwdriver      $ ", 6.59},
 {"A499", 75, "Pliers\t\t\t$  ", 4.95},
 {"C667", 50, "Drill\t\t\t$",22.95},
 {"B875", 70, "Plummber\'s Wrench\t$",11.90},
 {"D547", 60, "Ladder 10 foot\t\t$",70.44},
 {"A910", 85, "Flashlight 10 inch\t\t$", 9.99},
 {"B123", 90, "Assorted Buss Fuses\t$  ", 4.99} };
// create an instance of the application

CApp App;

// Define the Window object

class CWindow : public CFrameWnd
{
	CEdit* ed1;
	CEdit* ed2;
	CEdit* ed3; 
	CStatic* cs1;
	CStatic* cs2;
	CStatic* cs3;
	CStatic* result;
	CButton* button;
	CButton* button2;
	CMenu *menu;
public:
	CWindow();
	afx_msg void HandleChange();
	afx_msg void HandleButton();
	// New Added
	afx_msg void HandleView();
	afx_msg void HandleAdd();
	afx_msg void HandleRemove();
	afx_msg void HandleQuit();
	afx_msg void HandleDisplay();
	afx_msg void HandleCheckOut();
	DECLARE_MESSAGE_MAP();
	virtual BOOL PreTranslateMessage(MSG *msg);

};

void loadLinkList() {
	for (int i{}; i < ORIG_INV_COUNT; i++) {
		originalStock.push(&item[i]);
	}
}

// This Function Interprets tab
// keys properly

BOOL CWindow::PreTranslateMessage(MSG *msg) {
	return ::IsDialogMessage(m_hWnd, msg);

}

// Message Map

BEGIN_MESSAGE_MAP(CWindow, CFrameWnd)
	//ON_EN_CHANGE (IDC_ED1, H)
	//ON_EN_CHANGE (IDC_ED2, HandleChange)
	//ON_EN_CHANGE (IDC_ED3, HandleChange)
	ON_BN_CLICKED (IDC_BUTTON, HandleButton)
	ON_COMMAND (IDD_DLG_VIEW, HandleView)
	ON_COMMAND (IDD_DLG_DISPLAY, HandleDisplay)
	ON_COMMAND(IDD_DLG_REMOVE, HandleRemove)
	ON_COMMAND (IDD_DLG_ADD, HandleAdd)
	ON_COMMAND(IDD_DLG_CHECKOUT, HandleCheckOut)
	ON_COMMAND (IDM_STORE_QUIT, HandleQuit)
	END_MESSAGE_MAP()

// Window Constructor

CWindow::CWindow()
{

	// create the window

	Create(NULL, _T("Store"), WS_OVERLAPPED | WS_MINIMIZEBOX |WS_MAXIMIZE| WS_SYSMENU, CRect(CPoint(10, 10), CSize(800, 800)));
	//Create the Labels
	loadLinkList();
	ed1 = new CEdit();
	//ed1->Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP, CRect(CPoint(76, 10), CSize(64, 24)), this, IDC_ED1);

	/*cs1 = new CStatic();
	cs1->Create(_T("Amount"), WS_CHILD | WS_VISIBLE, CRect(CPoint(8, 10), CSize(66, 16)), this);
	cs2 = new CStatic();
	cs2->Create(_T("Rate(%)"), WS_CHILD | WS_VISIBLE, CRect(CPoint(8, 46), CSize(66, 16)), this);
	cs3 = new CStatic();
	cs3->Create(_T("Time(yrs)"), WS_CHILD | WS_VISIBLE, CRect(CPoint(8, 80), CSize(66, 16)), this);

	//Create  the Edit Controls

	ed1 = new CEdit();
	ed1->Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP, CRect(CPoint(76, 10), CSize(64, 24)), this, IDC_ED1);
	ed2 = new CEdit();
	ed2->Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP, CRect(CPoint(76, 46), CSize(64, 24)), this, IDC_ED2);
	ed3 = new CEdit();
	ed3->Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP, CRect(CPoint(76, 80), CSize(64, 24)), this, IDC_ED3);
	*/
	//Create te result Label

	result = new CStatic();
	result->Create(_T("Welcome to the store.\n where everything is cheap."), WS_CHILD |WS_VISIBLE, CRect(CPoint(10, 10), CSize(600, 600)), this, IDC_RESULT);


	/*// Create Quit Button
	button = new CButton();
	button->Create(_T("&Clear"), WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(CPoint(20, 162), CSize(138, 36)), this, IDC_BUTTON);
	button2 = new CButton();
	button2->Create(_T("&Quit"), WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(CPoint(20, 202), CSize(138, 42)), this, IDM_STORE_QUIT);
	*/// Create Menu Bar

    LoadAccelTable(_T("MainAccelTable"));
	menu = new CMenu();
	menu->LoadMenu(_T("MainManu"));
	SetMenu(menu);
	DrawMenuBar();

	result->SetFocus();
}
//	ON_COMMAND (IDC_ED1,HandleChange)



// Handl The Quit Button

void CWindow::HandleView() {
	char s[65353];
	ostrstream ostr(s, 65353);
	originalStock.print(ostr,FALSE,FALSE);
	SetDlgItemText(IDC_RESULT, s);
	result->SetFocus();
}

void CWindow::HandleAdd()
{
	CDAdd dlgSetText;
	if (dlgSetText.DoModal() == IDOK) {
		for (int i{}; i < ORIG_INV_COUNT; i++) {
			if (originalStock.search(dlgSetText.m_StockText)) {
				if (originalStock.getQ() > 0) {
					if (_ttoi(dlgSetText.m_QText) <= originalStock.getQ()) {
						if (customer.search(dlgSetText.m_StockText)) {
							customer.setQuantity(_ttoi(dlgSetText.m_QText), TRUE);
							originalStock.setQuantity(_ttoi(dlgSetText.m_QText), FALSE);
							originalStock.setQuantity(_ttoi(dlgSetText.m_QText), FALSE);
							MessageBox("This item Was ADDED to your cart", "Add", MB_ICONINFORMATION | MB_OK);
							char s[65353];
							ostrstream ostr(s, 65353);
							originalStock.print(ostr, FALSE, FALSE);
							SetDlgItemText(IDC_RESULT, s);
							result->SetFocus();
							return;

						}
						else {
							customer.push(originalStock.getNode(), _ttoi(dlgSetText.m_QText));
							originalStock.setQuantity(_ttoi(dlgSetText.m_QText), FALSE);
							MessageBox("This item Was ADDED to your cart", "Add", MB_ICONINFORMATION | MB_OK);
							char s[65353];
							ostrstream ostr(s, 65353);
							originalStock.print(ostr,FALSE,FALSE);
							SetDlgItemText(IDC_RESULT, s);
							result->SetFocus();
							return;
						}
					}
					else{
						MessageBox("You are Exceding the limit of the Item", "Alert", MB_ICONERROR | MB_OK);
					return;
					}
				}
				else{
					MessageBox("This Item is out of Stock", "Alert", MB_ICONERROR | MB_OK);
				return;
				}
			}
		}
		MessageBox("Error", "Alert", MB_ICONERROR | MB_OK);
	}

}

void CWindow::HandleRemove() {
	CDRemove dlgSetText;
	if (dlgSetText.DoModal() == IDOK) {
		for (int i{}; i < ORIG_INV_COUNT; i++) {
			if (customer.search(dlgSetText.m_StockText)) {
				if (customer.getQ() > 0) {
					if (_ttoi(dlgSetText.m_QText) <= customer.getQ()) {
							customer.setQuantity(_ttoi(dlgSetText.m_QText), FALSE);
							originalStock.setQuantity(_ttoi(dlgSetText.m_QText), TRUE);

							MessageBox("This item Was remove to your cart", "Add",  MB_ICONINFORMATION | MB_OK);
							char s[65353];
							ostrstream ostr(s, 65353);
							originalStock.print(ostr,FALSE,FALSE);
							SetDlgItemText(IDC_RESULT, s);
							result->SetFocus();
							return;
					}
					else {
						MessageBox("You have no more item to remove", "Alert", MB_ICONERROR | MB_OK);
						return;
					}
				}
				else {
					MessageBox("You have no more of this item in our cart", "Alert", MB_ICONERROR | MB_OK);
					return;
				}
			}
		}
		MessageBox("Error", "Alert", MB_ICONERROR | MB_OK);
	}

}

void CWindow::HandleDisplay() {
	char s[65353];
	ostrstream ostr(s, 65353);
	customer.print(ostr,TRUE,FALSE);

	SetDlgItemText(IDC_RESULT, s);
}

void CWindow::HandleCheckOut() {
	char s[65353];
	ostrstream ostr(s, 65353);
	customer.print(ostr, TRUE,TRUE);
	SetDlgItemText(IDC_RESULT, s);

cs1 = new CStatic();
cs1->Create(_T("Name"), WS_CHILD | WS_VISIBLE, CRect(CPoint(300, 350), CSize(66, 16)), this);
cs2 = new CStatic();
cs2->Create(_T("Address"), WS_CHILD | WS_VISIBLE, CRect(CPoint(300, 380), CSize(66, 16)), this);


//Create  the Edit Controls

ed1 = new CEdit();
ed1->Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP, CRect(CPoint(376, 350), CSize(200, 24)), this, IDC_ED1);
ed2 = new CEdit();
ed2->Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP, CRect(CPoint(376, 380), CSize(200, 24)), this, IDC_ED2);

button = new CButton();
button->Create(_T("Pay"), WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(CPoint(340, 500), CSize(138, 36)), this, IDC_BUTTON);


}

void CWindow::HandleChange() {

	char s[65353];
	ostrstream ostr(s, 65353);
	originalStock.print(ostr,FALSE,FALSE);

	SetDlgItemText(IDC_RESULT, s);

}

void CWindow::HandleQuit() {
	int result2 = MessageBox(_T("Are you sure \nyou want to quit(Y/N)?"), _T("Exiting!"), MB_ICONQUESTION | MB_YESNO);

	if (result2 == IDYES)
	{
		Beep(1000, 100);
		DestroyWindow();
	}
	else
	{
		Beep(200, 100);
		result->SetFocus();
	}



}
// Old Ones
void CWindow::HandleButton() {
	Beep(200, 100);
	MessageBox("Your items will arrived in 5 Bussiness Day", "Puchers", MB_ICONINFORMATION | MB_OK);
	DestroyWindow();
	result->SetFocus();
}




// Init the application and the main windon

BOOL CApp::InitInstance()
{
	m_pMainWnd = new CWindow();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
		return TRUE;
}