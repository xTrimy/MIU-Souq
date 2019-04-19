// ProductTest.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ProductTest.h"
#include "afxdialogex.h"
#include "MFCApplication1Dlg.h"

struct Product {
	int id;
	int user_id;
	float price;
	std::string desc; // description
};
// ProductTest dialog

IMPLEMENT_DYNAMIC(ProductTest, CDialogEx)

ProductTest::ProductTest(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

ProductTest::~ProductTest()
{

}

void ProductTest::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ProductTest, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &ProductTest::OnBnClickedOk)
END_MESSAGE_MAP()


// ProductTest message handlers

void ProductTest::OnPaint()
{
	CRect rect;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
	CRect rectClient;
	GetClientRect(rectClient);
	Product *prod = new Product;
	prod->id = currentProduct;
	prod->desc = "Description";


	std::string out_string;
	std::stringstream ss;
	ss << prod->desc;
	out_string = ss.str();
	std::string stdstr(out_string);

	CString cstr(stdstr.c_str());

	CWnd *label = GetDlgItem(IDC_STATIC);
	label->SetWindowText(cstr);
	/////////
	CPaintDC dc(this);	// device context for painting
	CPen pen;
	pen.CreatePen(PS_NULL,1,0x00FF0000); // Create White Border
	dc.SelectObject(&pen);

	CDialogEx::OnPaint();

	CStatic*  m_picture;    // pointer to a picture control
	m_picture = (CStatic *)GetDlgItem(IDC_STATIC2);
	CImage image;
	image.Load(_T("image2.jpg")); // just change extension to load jpg
	// Resizing Image Values <START>
	int iNewWidth;
	int iNewHeight;
	int maxWidth = 200, maxHeight = 200;
	if (image.GetWidth() > image.GetHeight()) {
		iNewWidth = maxWidth;
		iNewHeight = (image.GetHeight()*iNewWidth) / image.GetWidth();
	}
	else {
		iNewHeight = maxHeight;
		iNewWidth = (image.GetWidth()*iNewHeight) / image.GetHeight();
	}
	// Resizing Image Values <END>

	CDC *screenDC = GetDC();
	CDC *pMDC = new CDC;
	pMDC->CreateCompatibleDC(screenDC);

	CBitmap *pb = new CBitmap;
	pb->CreateCompatibleBitmap(screenDC, iNewWidth, iNewHeight);

	CBitmap *pob = pMDC->SelectObject(pb);

	//Resizing Image
	image.StretchBlt(pMDC->m_hDC, 0, 0, iNewWidth, iNewHeight, 0, 0, image.GetWidth(), image.GetHeight(), SRCCOPY);

	pMDC->SelectObject(pob);


	image.Detach();
	image.Attach((HBITMAP)(*pb));
	ReleaseDC(screenDC);

	CBitmap bitmap;
	bitmap.Attach(image.Detach());

	dc.Rectangle(rectClient.right / 2 - maxWidth/2, rectClient.bottom / 2- maxHeight/2, rectClient.right - ( rectClient.right / 2- maxWidth / 2), rectClient.bottom - (rectClient.bottom / 2 - maxHeight / 2));

	m_picture->SetBitmap(bitmap);
	m_picture->SetWindowPos(NULL, rectClient.right / 2 - (iNewWidth / 2), rectClient.bottom / 2 - (iNewHeight / 2), iNewWidth, iNewHeight, SWP_NOZORDER | SWP_NOSIZE);

}


void ProductTest::OnBnClickedOk()
{
	CDialogEx::OnOK();

	// TODO: Add your control notification handler code here
}
