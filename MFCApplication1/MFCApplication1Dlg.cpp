
// MFCApplication1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "CSignUp.h"
#include "ProductTest.h"
#include "ProductsList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg dialog



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DLG_LOGIN, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication1Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMFCApplication1Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDCANCEL2, &CMFCApplication1Dlg::OnBnClickedCancel2)
	ON_BN_CLICKED(IDOK2, &CMFCApplication1Dlg::OnBnClickedOk2)
END_MESSAGE_MAP()


// CMFCApplication1Dlg message handlers

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization 

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);

		// // // // // // // // // // // // //

	}
	else
	{
		CDialogEx::OnPaint();

	}

	//Convert JPG to Bitmap

	//int iNewWidth = 200;
	//int iNewHeight = 200;
	//CStatic*  m_picture;    // pointer to a picture control

	//m_picture = (CStatic *)GetDlgItem(IDC_STATIC);

	//CImage image;
	//image.Load(_T("image2.jpg")); // just change extension to load jpg

	//CDC *screenDC = GetDC();
	//CDC *pMDC = new CDC;
	//pMDC->CreateCompatibleDC(screenDC);

	//CBitmap *pb = new CBitmap;
	//pb->CreateCompatibleBitmap(screenDC, iNewWidth, iNewHeight);

	//CBitmap *pob = pMDC->SelectObject(pb);
	//image.StretchBlt(pMDC->m_hDC, 0, 0, iNewWidth, iNewHeight, 0, 0, image.GetWidth(), image.GetHeight(), SRCCOPY);
	//pMDC->SelectObject(pob);


	//image.Detach();
	//image.Attach((HBITMAP)(*pb));
	//ReleaseDC(screenDC);

	//CBitmap bitmap;
	//bitmap.Attach(image.Detach());
	//CRect rectClient;
	//GetClientRect(rectClient);

	//m_picture->ModifyStyle(0xF, SS_BITMAP, 0);
	////m_picture->SetBitmap(bitmap);
	//m_picture->SetWindowPos(NULL, rectClient.right/2 - (iNewWidth/2), rectClient.bottom / 2 - (iNewHeight / 2), iNewWidth, iNewHeight, SWP_NOZORDER | SWP_NOSIZE);

}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	CSignUp test;

	test.DoModal();

}


void CMFCApplication1Dlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CMFCApplication1Dlg::OnBnClickedCancel2()
{
	// TODO: Add your control notification handler code here

}



void CMFCApplication1Dlg::OnBnClickedOk2()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	ProductsList ProdList;
	currentProduct = 3;
	/*_mkdir("./abc");*/
	ProdList.DoModal();
}
