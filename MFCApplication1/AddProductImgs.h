#pragma once


// AddProductImgs dialog

class AddProductImgs : public CDialogEx
{
	DECLARE_DYNAMIC(AddProductImgs)

public:
	AddProductImgs(CWnd* pParent = nullptr);   // standard constructor
	virtual ~AddProductImgs();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDPRODUCT_IMGS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedPublish();
	afx_msg void OnBnClickedCancel();
};
