// ContactSeller.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ContactSeller.h"
#include "afxdialogex.h"
#include "UserProfile.h"
#include "ProductInfo.h"


// ContactSeller dialog

IMPLEMENT_DYNAMIC(ContactSeller, CDialogEx)

ContactSeller::ContactSeller(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CONTACT_SELLER, pParent)
{

}

ContactSeller::~ContactSeller()
{
}

void ContactSeller::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ContactSeller, CDialogEx)
	ON_BN_CLICKED(IDOK, &ContactSeller::OnBnClickedOk)
	ON_BN_CLICKED(IDOK2, &ContactSeller::OnBnClickedOk2)
	ON_BN_CLICKED(IDCANCEL, &ContactSeller::OnBnClickedCancel)
END_MESSAGE_MAP()


// ContactSeller message handlers


void ContactSeller::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	UserProfile x;
	x.DoModal();
}


void ContactSeller::OnBnClickedOk2()
{
	// TODO: Add your control notification handler code here
}


void ContactSeller::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
	ProductInfo x;
	x.DoModal();
}
