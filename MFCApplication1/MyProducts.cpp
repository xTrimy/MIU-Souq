// MyProducts.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MyProducts.h"
#include "afxdialogex.h"
#include "ProductsList.h"
#include "AddProduct.h"


// MyProducts dialog

IMPLEMENT_DYNAMIC(MyProducts, CDialogEx)

MyProducts::MyProducts(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY_PRODUCTS, pParent)
{

}

MyProducts::~MyProducts()
{
}

void MyProducts::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyProducts, CDialogEx)
	ON_BN_CLICKED(IDOK, &MyProducts::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &MyProducts::OnBnClickedOk)
	ON_BN_CLICKED(IDNP, &MyProducts::OnBnClickedNewP)
END_MESSAGE_MAP()


// MyProducts message handlers


void MyProducts::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	ProductsList x;
	x.DoModal();
}


void MyProducts::OnBnClickedNewP()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	AddProduct x;
	x.DoModal();
}
