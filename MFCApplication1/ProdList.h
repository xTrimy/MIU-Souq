#pragma once


// ProdList dialog

class ProdList : public CDialogEx
{
	DECLARE_DYNAMIC(ProdList)

public:
	ProdList(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ProdList();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRODUCTS_LIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
