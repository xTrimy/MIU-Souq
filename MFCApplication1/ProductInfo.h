#pragma once


// ProductInfo dialog

class ProductInfo : public CDialogEx
{
	DECLARE_DYNAMIC(ProductInfo)

public:
	ProductInfo(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ProductInfo();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRODUCT_INFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
