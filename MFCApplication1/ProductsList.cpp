// ProductsList.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ProductsList.h"
#include "afxdialogex.h"
#include "ProductInfo.h"
// ProductsList dialog

IMPLEMENT_DYNAMIC(ProductsList, CDialogEx)

ProductsList::ProductsList(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PRODUCTS_LIST, pParent)
{

}

ProductsList::~ProductsList()
{
}

void ProductsList::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ProductsList, CDialogEx)
	ON_BN_CLICKED(BTN_NEXT, &ProductsList::OnBnClickedNext)
	ON_BN_CLICKED(BTN_PREV, &ProductsList::OnBnClickedPrev)
	ON_WM_PAINT()
	ON_BN_CLICKED(BN_View_Prod6, &ProductsList::OnBnClickedViewProd6)
	ON_BN_CLICKED(BN_View_Prod5, &ProductsList::OnBnClickedViewProd5)
	ON_BN_CLICKED(BN_View_Prod4, &ProductsList::OnBnClickedViewProd4)
	ON_BN_CLICKED(BN_View_Prod3, &ProductsList::OnBnClickedViewProd3)
	ON_BN_CLICKED(BN_View_Prod2, &ProductsList::OnBnClickedViewProd2)
	ON_BN_CLICKED(BN_View_Prod1, &ProductsList::OnBnClickedViewProd1)
END_MESSAGE_MAP()


// ProductsList message handlers

ProductInfo Product;
CStatic*  m_picture[6];	    // pointer to a picture control
int page = 0;
int ProductsId[6] = { -1 };
bool maxPage = false;
void ProductsList::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CDialogEx::OnPaint() for painting messages
	CRect rectClient;
	GetClientRect(rectClient);
	CRect Image[6];
	for (int i = 0; i < 6; i++) {
		GetDlgItem(IDC_PRODUCT_IMAGE1 + i)->GetWindowRect(&Image[i]);
		*(m_picture+i) = (CStatic *)GetDlgItem(IDC_PRODUCT_IMAGE1+i);
	}

	CImage image;
	for(int i = 0; i < 6; i++){
		int prod_id = i + 1 + page * 6;
		ProductsId[i] = prod_id;
		std::ifstream CheckFile("./products/"+ std::to_string(prod_id) +"/image2.jpg");
		if (!CheckFile) {
			continue;
		}
		std::ifstream CheckMaxPage("./products/" + std::to_string(prod_id + 1) + "/image2.jpg");
		if (!CheckMaxPage) {
			maxPage = true;
		}
		CString imagePath;
		imagePath.Format(_T("./products/%d/image2.jpg"),i+1 + page*6);
		image.Load(imagePath);
		int iNewWidth;
		int iNewHeight;
		int maxWidth = Image[0].Width(), maxHeight = Image[0].Height();
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

		m_picture[i]->SetBitmap(bitmap);

	}
}






//------------------------ Next & Previous Buttons-------------------------------

void ProductsList::OnBnClickedNext()
{
	if (maxPage == false) {
		for (int i = 0; i < 6; i++)
			m_picture[i]->SetBitmap(NULL);
		page++;
		ProductsList::OnPaint();
	}

	// TODO: Add your control notification handler code here
}

//------------------------ Product View -------------------------------

void ProductsList::OnBnClickedPrev()
{
	if (page > 0) {
		for (int i = 0; i < 6; i++)
			m_picture[i]->SetBitmap(NULL);
		page--;
		ProductsList::OnPaint();
		maxPage = false;
	}

	// TODO: Add your control notification handler code here
}


void ProductsList::OnBnClickedViewProd1()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	currentProduct = ProductsId[0];
	Product.DoModal();
}


void ProductsList::OnBnClickedViewProd2()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	currentProduct = ProductsId[1];
	Product.DoModal();
}


void ProductsList::OnBnClickedViewProd3()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	currentProduct = ProductsId[2];
	Product.DoModal();
}


void ProductsList::OnBnClickedViewProd4()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	currentProduct = ProductsId[3];
	Product.DoModal();
}


void ProductsList::OnBnClickedViewProd5()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	currentProduct = ProductsId[4];
	Product.DoModal();

}


void ProductsList::OnBnClickedViewProd6()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	currentProduct = ProductsId[5];
	Product.DoModal();
}
