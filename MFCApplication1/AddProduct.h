#pragma once


// AddProduct dialog

class AddProduct : public CDialogEx
{
	DECLARE_DYNAMIC(AddProduct)

public:
	AddProduct(CWnd* pParent = nullptr);   // standard constructor
	virtual ~AddProduct();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_PRODUCT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton7();
};
