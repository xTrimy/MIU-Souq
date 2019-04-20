#pragma once


// SignUp2 dialog

class SignUp2 : public CDialogEx
{
	DECLARE_DYNAMIC(SignUp2)

public:
	SignUp2(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SignUp2();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SIGNUP2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
};
