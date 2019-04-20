// CSignUp.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "CSignUp.h"
#include "afxdialogex.h"
#include "MFCApplication1Dlg.h"
#include "SignUp2.h"


// CSignUp dialog

IMPLEMENT_DYNAMIC(CSignUp, CDialogEx)

CSignUp::CSignUp(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DLG_SIGNUP, pParent)
{

}

CSignUp::~CSignUp()
{
}

void CSignUp::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSignUp, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSignUp::OnBnSignUp)
	ON_BN_CLICKED(IDCANCEL, &CSignUp::OnBnClickedBack)
END_MESSAGE_MAP()


// CSignUp message handlers


void CSignUp::OnBnSignUp()
{
	CDialogEx::OnOK();
	SignUp2 x;
	x.DoModal();
}


void CSignUp::OnBnClickedBack()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	CMFCApplication1Dlg x;
	x.DoModal();
}
