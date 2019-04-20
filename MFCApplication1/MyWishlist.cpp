// MyWishlist.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MyWishlist.h"
#include "afxdialogex.h"
#include "ProductsList.h"


// MyWishlist dialog

IMPLEMENT_DYNAMIC(MyWishlist, CDialogEx)

MyWishlist::MyWishlist(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY_WISHLIST, pParent)
{

}

MyWishlist::~MyWishlist()
{
}

void MyWishlist::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyWishlist, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &MyWishlist::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &MyWishlist::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MyWishlist::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &MyWishlist::OnBnClickedOk)
END_MESSAGE_MAP()


// MyWishlist message handlers


void MyWishlist::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
}


void MyWishlist::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
}


void MyWishlist::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	ProductsList ProductsL;
	ProductsL.DoModal();
}
