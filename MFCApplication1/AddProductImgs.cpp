// AddProductImgs.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "AddProductImgs.h"
#include "afxdialogex.h"
#include "ProductsList.h"
#include "AddProduct.h"


// AddProductImgs dialog

IMPLEMENT_DYNAMIC(AddProductImgs, CDialogEx)

AddProductImgs::AddProductImgs(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADDPRODUCT_IMGS, pParent)
{

}

AddProductImgs::~AddProductImgs()
{
}

void AddProductImgs::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddProductImgs, CDialogEx)
	ON_BN_CLICKED(IDPUBLISH, &AddProductImgs::OnBnClickedPublish)
	ON_BN_CLICKED(IDCANCEL, &AddProductImgs::OnBnClickedCancel)
END_MESSAGE_MAP()


// AddProductImgs message handlers


void AddProductImgs::OnBnClickedPublish()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	ProductsList x;
	x.DoModal();
}


void AddProductImgs::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	AddProduct x;
	x.DoModal();
}
