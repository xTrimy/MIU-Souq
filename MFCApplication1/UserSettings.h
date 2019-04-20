#pragma once


// UserSettings dialog

class UserSettings : public CDialogEx
{
	DECLARE_DYNAMIC(UserSettings)

public:
	UserSettings(CWnd* pParent = nullptr);   // standard constructor
	virtual ~UserSettings();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USER_SETTINGS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
