
// Pratice4_2_ClockDlg.h: 헤더 파일
//

#pragma once
#include "CClockHelpDlg.h"


// CPratice42ClockDlg 대화 상자
class CPratice42ClockDlg : public CDialogEx
{
// 생성입니다.
public:
	CPratice42ClockDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRATICE4_2_CLOCK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strYear;
	CString m_strMonth;
	CString m_strDay;
	CString m_strSecond;
	CString m_strMinute;
	CString m_strHour;

	afx_msg void OnRadio12();
	afx_msg void OnRadio24();

	bool m_bradioClickType;		// 라디오버튼변수
	bool m_bCheckYear;			//체크박스변수
	bool m_bCheckHour;			
	afx_msg void OnClickedCheck1Year();
	afx_msg void OnClickedCheckHour();
	afx_msg void OnClickedButtonHelp();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CString m_strAmPm;

	bool m_bViewHelp;
	CClockHelpDlg m_dlgCheckHelp;
};
