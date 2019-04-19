#pragma once


// CSignUp dialog

class CSignUp : public CDialogEx
{
	DECLARE_DYNAMIC(CSignUp)

public:
	CSignUp(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSignUp();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = DLG_SIGNUP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnSignUp();
	afx_msg void OnBnClickedBack();
};
