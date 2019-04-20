#pragma once


// ContactSeller dialog

class ContactSeller : public CDialogEx
{
	DECLARE_DYNAMIC(ContactSeller)

public:
	ContactSeller(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ContactSeller();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONTACT_SELLER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedOk2();
	afx_msg void OnBnClickedCancel();
};
