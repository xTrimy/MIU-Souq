// UserProfile.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "UserProfile.h"
#include "afxdialogex.h"
#include "ProductsList.h"
#include "ProductInfo.h"


// UserProfile dialog

IMPLEMENT_DYNAMIC(UserProfile, CDialogEx)

UserProfile::UserProfile(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PROFILE, pParent)
{

}

UserProfile::~UserProfile()
{
}

void UserProfile::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UserProfile, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &UserProfile::OnBnClickedOk)
	ON_BN_CLICKED(IDOK, &UserProfile::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, &UserProfile::OnBnClickedButton3)
END_MESSAGE_MAP()


// UserProfile message handlers


void UserProfile::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	ProductsList x;
	x.DoModal();
}


void UserProfile::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	ProductInfo x;
	x.DoModal();
}
