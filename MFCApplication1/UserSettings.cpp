// UserSettings.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "UserSettings.h"
#include "afxdialogex.h"
#include "ProductsList.h"


// UserSettings dialog

IMPLEMENT_DYNAMIC(UserSettings, CDialogEx)

UserSettings::UserSettings(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_USER_SETTINGS, pParent)
{

}

UserSettings::~UserSettings()
{
}

void UserSettings::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UserSettings, CDialogEx)
	ON_BN_CLICKED(IDOK, &UserSettings::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &UserSettings::OnBnClickedCancel)
END_MESSAGE_MAP()


// UserSettings message handlers


void UserSettings::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	ProductsList x;
	x.DoModal();
}


void UserSettings::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
	CDialogEx::OnOK();
	ProductsList x;
	x.DoModal();
}
