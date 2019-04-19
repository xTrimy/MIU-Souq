#pragma once


// ProductTest dialog

class ProductTest : public CDialogEx
{
	DECLARE_DYNAMIC(ProductTest)

public:
	ProductTest(CWnd* pParent = nullptr);   // standard constructor
	CFileFind finder;       // for file loading
	virtual ~ProductTest();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();
};
