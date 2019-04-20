#pragma once


// MyWishlist dialog

class MyWishlist : public CDialogEx
{
	DECLARE_DYNAMIC(MyWishlist)

public:
	MyWishlist(CWnd* pParent = nullptr);   // standard constructor
	virtual ~MyWishlist();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_WISHLIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOk();
};
