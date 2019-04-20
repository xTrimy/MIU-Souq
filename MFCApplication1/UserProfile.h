#pragma once


// UserProfile dialog

class UserProfile : public CDialogEx
{
	DECLARE_DYNAMIC(UserProfile)

public:
	UserProfile(CWnd* pParent = nullptr);   // standard constructor
	virtual ~UserProfile();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROFILE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton3();
};
