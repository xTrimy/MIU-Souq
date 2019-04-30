// CSignUp.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "CSignUp.h"
#include "afxdialogex.h"
#include "MFCApplication1Dlg.h"
#include "SignUp2.h"
#pragma warning(disable : 4996)


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
struct user {
	CString FirstName;
	CString SecondName;
	CString Username;
	CString Email;
	CString ID;
	CString Phone;
	CString Faculty;
	CString Gender;
	CString Birth;
	CString Password;
	CString Password2;
	int Pass() {
		if (FirstName.GetLength() > 2 && SecondName.GetLength() > 2 && Username.GetLength() > 4 && Email.GetLength() > 25 && ID.GetLength() > 5) {
			for (int i = 0; i < FirstName.GetLength(); i++)
				if ((char)FirstName[i] == ' ')
					return 2;
			for (int i = 0; i < SecondName.GetLength(); i++)
				if ((char)SecondName[i] == ' ')
					return 3;
			for (int i = 0; i < Username.GetLength(); i++)
				if ((char)Username[i] == ' ')
					return 4;
			for (int i = 0; i < Email.GetLength(); i++)
				if ((char)Email[i] == ' ')
					return 5;
			for (int i = 0; i < ID.GetLength(); i++)
				if (!isdigit((char)ID[i]))
					return 6;
			for (int i = 0; i < Phone.GetLength(); i++)
				if (!isdigit((char)Phone[i]))
					return 7;
			if (Password2 != Password)
				return 8;
			return 0;

		}
		return 1;
	}
};
void createUserFolder(char fullPath[256]) {
	int ucount;
	std::stringstream intToSt;
	FILE *u;
	u = fopen("users.bin", "r");
	if (!u) {
		std::fstream userCount;
		userCount.close();
		userCount.open("users.bin", std::ofstream::out | std::ofstream::binary);
		userCount << "1";
		ucount = 1;
		userCount.close();
	}
	else {
		std::fstream userCount("users.bin", std::ifstream::in | std::ifstream::binary);
		std::string count;
		userCount >> count;
		userCount.close();
		std::istringstream iss(count);
		iss >> ucount;
		ucount++;
		userCount.open("users.bin", std::ofstream::out | std::ofstream::binary);
		userCount << ucount;
		userCount.close();
	}
	intToSt << ucount;
	currentSignUpUser = ucount;
	mkdir(intToSt.str().c_str());
	char dir[4];
	strcpy(dir, intToSt.str().c_str());
	strcat(dir, "/");
	strcpy(fullPath, dir);
	strcat(fullPath, "Data.bin");
}
std::string toStr(CString x) {
	CT2CA pszConvertedAnsiString(x);
	std::string str(pszConvertedAnsiString);
	return str;
}
void CSignUp::OnBnSignUp()
{
	user u;
	GetDlgItem(IDC_EDIT1)->GetWindowText(u.FirstName);
	GetDlgItem(IDC_EDIT10)->GetWindowText(u.SecondName);
	GetDlgItem(IDC_EDIT15)->GetWindowText(u.Username);
	GetDlgItem(IDC_EDIT16)->GetWindowText(u.Email);
	GetDlgItem(IDC_EDIT17)->GetWindowText(u.ID);
	GetDlgItem(IDC_EDIT18)->GetWindowText(u.Phone);
	GetDlgItem(IDC_COMBO1)->GetWindowText(u.Faculty);
	GetDlgItem(IDC_DATETIMEPICKER1)->GetWindowText(u.Birth);
	GetDlgItem(IDC_EDIT20)->GetWindowText(u.Password);
	GetDlgItem(IDC_EDIT21)->GetWindowText(u.Password2);
	if (u.Pass() == 0) {
		char fullPath[256];
		createUserFolder(fullPath);
		std::ofstream data(fullPath, std::ios::binary);
		data 
		<< toStr(u.FirstName) << "\t" << toStr(u.SecondName) << "\t" 
		<< toStr(u.Username) << "\t" << toStr(u.Email) << "\t" << toStr(u.ID) 
		<< "\t" << toStr(u.Phone) << "\t" << toStr(u.Faculty) << "\t" << toStr(u.Birth) 
		<< "\t" << toStr(u.Password);
		data.close();
		CDialogEx::OnOK();
		SignUp2 x;
		x.DoModal();
	}
	else if(u.Pass() == 2){
		MessageBox(_T("First Name Can't Have Spaces"));

	}
	else if (u.Pass() == 3) {
		MessageBox(_T("Last Name Can't Have Spaces"));

	}
	else if (u.Pass() == 4) {
		MessageBox(_T("Username Can't Have Spaces"));
	}
	else if (u.Pass() == 5) {
		MessageBox(_T("Please Enter a Valid University Email\n e.g.:example1234567@miuegypt.edu.eg"));
	}
	else if (u.Pass() == 6) {
		MessageBox(_T("Please Enter a valid ID\nUniversity ID Must contain only Numbers"));
	}
	else if (u.Pass() == 7) {
		MessageBox(_T("Enter Valid Mobile Number"));
	}
	else if (u.Pass() == 8) {
		MessageBox(_T("Please check your password"));
	}
	else {
		MessageBox(_T("Please Enter Full Details"));
	}


}


void CSignUp::OnBnClickedBack()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	CMFCApplication1Dlg x;
	x.DoModal();
}



