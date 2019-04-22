// SingUp2.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "SignUp2.h"
#include "afxdialogex.h"
#include "ProductsList.h"
#include "RandomAvatar.h"
bool photoSelected = false;

// SingUp2 dialog

IMPLEMENT_DYNAMIC(SignUp2, CDialogEx)

SignUp2::SignUp2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SIGNUP2, pParent)
{
	photoSelected = false;

	RandomAvatar avt;
	avt.create("img.bmp");
}

SignUp2::~SignUp2()
{
}

void SignUp2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SignUp2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &SignUp2::OnBnClickedButton1)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON2, &SignUp2::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &SignUp2::OnBnClickedButton4)
END_MESSAGE_MAP()


// SingUp2 message handlers


void SignUp2::OnPaint()
{

	CPaintDC dc(this); // device context for painting
						   // TODO: Add your message handler code here
						   // Do not call CDialogEx::OnPaint() for painting messages
	CRect rectClient;
	GetClientRect(rectClient);
	CRect UserPic;
	GetDlgItem(IDC_USER_PIC)->GetWindowRect(UserPic);

	CDialogEx::OnPaint();

	CStatic*  m_picture;    // pointer to a picture control
	m_picture = (CStatic *)GetDlgItem(IDC_USER_PIC);
	CImage image;
	CString imagePath;
	if (photoSelected) {
		imagePath.Format(_T("./userImage.jpg"), currentProduct);
	}
	else {
		imagePath.Format(_T("./userDefault.jpg"), currentProduct);

	}
	image.Load(imagePath);
	// Resizing Image Values <START>
	int iNewWidth;
	int iNewHeight;
	int maxWidth = UserPic.Width(), maxHeight = UserPic.Height();
	if (image.GetWidth() > image.GetHeight()) {
		iNewWidth = maxWidth;
		iNewHeight = (image.GetHeight()*iNewWidth) / image.GetWidth();
	}
	else {
		iNewHeight = maxHeight;
		iNewWidth = (image.GetWidth()*iNewHeight) / image.GetHeight();
	}
	// Resizing Image Values <END>

	CDC *screenDC = GetDC();
	CDC *pMDC = new CDC;
	pMDC->CreateCompatibleDC(screenDC);

	CBitmap *pb = new CBitmap;
	pb->CreateCompatibleBitmap(screenDC, iNewWidth, iNewHeight);

	CBitmap *pob = pMDC->SelectObject(pb);

	//Resizing Image
	image.StretchBlt(pMDC->m_hDC, 0, 0, iNewWidth, iNewHeight, 0, 0, image.GetWidth(), image.GetHeight(), SRCCOPY);

	pMDC->SelectObject(pob);


	image.Detach();
	image.Attach((HBITMAP)(*pb));
	ReleaseDC(screenDC);

	CBitmap bitmap;
	bitmap.Attach(image.Detach());


	m_picture->SetBitmap(bitmap);
}


void SignUp2::OnBnClickedButton1()
{
	CFileDialog FileDialog(TRUE,
		_T("*.jpg;*.png;*pgm"),
		NULL,
		OFN_HIDEREADONLY,
		_T("Image Files: (*.jpg,*.png,*pgm)|*.jpg;*.png;*.pgm"));



	if (FileDialog.DoModal() == IDOK) {
		// Some code here https://stackoverflow.com/questions/35607986/binary-open-and-copy-image-file-c
		// Some code here http://www.cplusplus.com/reference/ostream/ostream/write/
		// Some code here http://www.cplusplus.com/reference/istream/istream/read/
		// Some code here https://stackoverflow.com/questions/2490661/how-to-load-png-jpeg-images-using-mfc (Convert image to bitmap to load in MFC)
		CString filePath;
		filePath = FileDialog.GetPathName();
		std::string fileData;
		std::ifstream fileIn(filePath, std::ifstream::binary);
		fileIn.seekg(0, fileIn.end);
		long size = fileIn.tellg();
		fileIn.seekg(0);
		char * buffer = new char[size];
		fileIn.read(buffer, size);
		std::ofstream fileOut;
		fileOut.open("./userImage.jpg", std::ofstream::binary);
		fileOut.write(buffer, size);
		fileIn.close();
		fileOut.close();
		photoSelected = true;
		SignUp2::Invalidate();

	}
	// TODO: Add your control notification handler code here
}



void SignUp2::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	ProductsList x;
	x.DoModal();
}


void SignUp2::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	ProductsList x;
	x.DoModal();
}
