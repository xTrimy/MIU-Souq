#pragma once


// ProductsList dialog

class ProductsList : public CDialogEx
{
	DECLARE_DYNAMIC(ProductsList)

public:
	ProductsList(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ProductsList();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRODUCTS_LIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMThemeChangedScrollbar1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	CSliderCtrl m_var_slider1;
	CString m_var_Text1;
	afx_msg void OnStnClickedProductImage1();
	afx_msg void OnStnClickedProductImage2();
	afx_msg void OnStnClickedProductImage3();
	afx_msg void OnStnClickedProductImage4();
	afx_msg void OnStnClickedProductImage5();
	afx_msg void OnStnClickedProductImage6();
	afx_msg void OnBnClickedNext();
	afx_msg void OnBnClickedPrev();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedViewProd6();
	afx_msg void OnBnClickedViewProd5();
	afx_msg void OnBnClickedViewProd4();
	afx_msg void OnBnClickedViewProd3();
	afx_msg void OnBnClickedViewProd2();
	afx_msg void OnBnClickedViewProd1();
};
