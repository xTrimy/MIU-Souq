// CSignUp.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "CSignUp.h"
#include "afxdialogex.h"
#include "MFCApplication1Dlg.h"
#include <fstream>
#include <string>

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
	CFileDialog FileDialog(TRUE,
		_T("*.jpg"),
		NULL,
		OFN_HIDEREADONLY,
		_T("Jpg Files: (*.jpg)|*.jpg||"));
	if (FileDialog.DoModal() == IDOK) {
		// Some code here https://stackoverflow.com/questions/35607986/binary-open-and-copy-image-file-c
		// Some code here http://www.cplusplus.com/reference/ostream/ostream/write/
		// Some code here http://www.cplusplus.com/reference/istream/istream/read/
		// Some code here https://stackoverflow.com/questions/2490661/how-to-load-png-jpeg-images-using-mfc (Convert image to bitmap to load in MFC)
		CString filePath;
		filePath = FileDialog.GetPathName();

		std::string fileData;
		std::ifstream fileIn (filePath, std::ifstream::binary);
		fileIn.seekg(0, fileIn.end);
		long size = fileIn.tellg();
		fileIn.seekg(0);


		char * buffer = new char[size];
		fileIn.read(buffer, size);
		std::ofstream fileOut ("./image2.jpg", std::ofstream::binary);
		fileOut.write(buffer, size);
		fileIn.close();
		fileOut.close();
		MessageBox(filePath);

	}
}


void CSignUp::OnBnClickedBack()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	CMFCApplication1Dlg test;
	test.DoModal();

}
