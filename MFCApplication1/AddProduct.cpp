// AddProduct.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "AddProduct.h"
#include "afxdialogex.h"
#include "ProductsList.h"
#include "MyProducts.h"
#include "AddProductImgs.h"


// AddProduct dialog

IMPLEMENT_DYNAMIC(AddProduct, CDialogEx)

AddProduct::AddProduct(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD_PRODUCT, pParent)
{

}

AddProduct::~AddProduct()
{
}

void AddProduct::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddProduct, CDialogEx)
	ON_BN_CLICKED(IDOK, &AddProduct::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &AddProduct::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON7, &AddProduct::OnBnClickedButton7)
END_MESSAGE_MAP()


// AddProduct message handlers


void AddProduct::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	ProductsList x;
	x.DoModal();
}


void AddProduct::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	MyProducts x;
	x.DoModal();
}


void AddProduct::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	AddProductImgs x;
	x.DoModal();
}
