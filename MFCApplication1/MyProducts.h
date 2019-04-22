#pragma once


// MyProducts dialog

class MyProducts : public CDialogEx
{
	DECLARE_DYNAMIC(MyProducts)

public:
	MyProducts(CWnd* pParent = nullptr);   // standard constructor
	virtual ~MyProducts();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_PRODUCTS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedNewP();
//	afx_msg void OnPaint();
};
