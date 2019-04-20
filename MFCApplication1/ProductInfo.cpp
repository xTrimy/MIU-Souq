// ProductInfo.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ProductInfo.h"
#include "afxdialogex.h"
#include "ProductsList.h"
#include "ContactSeller.h"


// ProductInfo dialog

IMPLEMENT_DYNAMIC(ProductInfo, CDialogEx)

ProductInfo::ProductInfo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PRODUCT_INFO, pParent)
{

}

ProductInfo::~ProductInfo()
{
}

void ProductInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ProductInfo, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDCANCEL, &ProductInfo::OnBnClickedOk)
	ON_BN_CLICKED(IDOK, &ProductInfo::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &ProductInfo::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK4, &ProductInfo::OnBnClickedOk4)
END_MESSAGE_MAP()


// ProductInfo message handlers


void ProductInfo::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CDialogEx::OnPaint() for painting messages
	CRect rectClient;
	GetClientRect(rectClient);


	CDialogEx::OnPaint();
	std::ifstream CheckFile("./products/" + std::to_string(currentProduct) + "/image2.jpg");
	if (!CheckFile) {
		return;
	}
	CStatic*  m_picture;    // pointer to a picture control
	m_picture = (CStatic *)GetDlgItem(PRODUCT_IMG);
	CImage image;
	CString imagePath;
	imagePath.Format(_T("./products/%d/image2.jpg"),currentProduct);
	image.Load(imagePath);
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


	m_picture->SetBitmap(bitmap);
}


void ProductInfo::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	ProductsList x;
	x.DoModal();
}


void ProductInfo::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	ContactSeller x;
	x.DoModal();
}


void ProductInfo::OnBnClickedOk4()
{
	// TODO: Add your control notification handler code here
}
