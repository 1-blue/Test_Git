
// Pratice4_2_ClockDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Pratice4_2_Clock.h"
#include "Pratice4_2_ClockDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPratice42ClockDlg 대화 상자



CPratice42ClockDlg::CPratice42ClockDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PRATICE4_2_CLOCK_DIALOG, pParent)
	, m_strYear(_T(""))
	, m_strMonth(_T(""))
	, m_strDay(_T(""))
	, m_strSecond(_T(""))
	, m_strMinute(_T(""))
	, m_strHour(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPratice42ClockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_year, m_strYear);
	DDX_Text(pDX, IDC_EDIT_month, m_strMonth);
	DDX_Text(pDX, IDC_EDIT_day, m_strDay);
	DDX_Text(pDX, IDC_EDIT_second, m_strSecond);
	DDX_Text(pDX, IDC_EDIT_minute, m_strMinute);
	DDX_Text(pDX, IDC_EDIT_hour, m_strHour);
}

BEGIN_MESSAGE_MAP(CPratice42ClockDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDC_RADIO_12, &CPratice42ClockDlg::OnRadio12)
	ON_COMMAND(IDC_RADIO_24, &CPratice42ClockDlg::OnRadio24)
	ON_BN_CLICKED(IDC_CHECK1_year, &CPratice42ClockDlg::OnClickedCheck1Year)
	ON_BN_CLICKED(IDC_CHECK_hour, &CPratice42ClockDlg::OnClickedCheckHour)
	ON_BN_CLICKED(IDC_BUTTON_help, &CPratice42ClockDlg::OnClickedButtonHelp)
END_MESSAGE_MAP()


// CPratice42ClockDlg 메시지 처리기

BOOL CPratice42ClockDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	((CButton*)GetDlgItem(IDC_RADIO_12))->SetCheck(true);		//오디오박스 12버튼체크
	((CButton*)GetDlgItem(IDC_CHECK_hour))->SetCheck(true);		//체크박스 hour체크



	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CPratice42ClockDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CPratice42ClockDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CPratice42ClockDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//12시간 라디오버튼클릭
void CPratice42ClockDlg::OnRadio12()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_bradioClickType = true;

}

//24시간 라디오버튼클릭
void CPratice42ClockDlg::OnRadio24()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_bradioClickType = false;

}

//년체크박스클릭
void CPratice42ClockDlg::OnClickedCheck1Year()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bCheckYear == false)	//체크박스눌러지면
	{
		GetDlgItem(IDC_EDIT_year)->ShowWindow(SW_SHOW);		//화면에 보이게 만듦
		GetDlgItem(IDC_EDIT_month)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_day)->ShowWindow(SW_SHOW);
		//ampm추가

		GetDlgItem(IDC_STATIC_year)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_month)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_day)->ShowWindow(SW_SHOW);

		m_bCheckYear = true;
	}
	else	//체크박스 체크해제일때
	{
		GetDlgItem(IDC_EDIT_year)->ShowWindow(SW_HIDE);		//화면에 안보이게 만듦
		GetDlgItem(IDC_EDIT_month)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_day)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_STATIC_year)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_month)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_day)->ShowWindow(SW_HIDE);

		m_bCheckYear = false;
	}
}

//시간체크박스클릭
void CPratice42ClockDlg::OnClickedCheckHour()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bCheckHour == false)	//체크박스눌러지면
	{
		GetDlgItem(IDC_EDIT_hour)->ShowWindow(SW_SHOW);		//화면에 보이게 만듦
		GetDlgItem(IDC_EDIT_minute)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_second)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_STATIC_hour)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_minute)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_second)->ShowWindow(SW_SHOW);

		m_bCheckHour = true;
	}
	else	//체크박스 체크해제일때
	{
		GetDlgItem(IDC_EDIT_hour)->ShowWindow(SW_HIDE);		//화면에 안보이게 만듦
		GetDlgItem(IDC_EDIT_minute)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_second)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_STATIC_hour)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_minute)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_second)->ShowWindow(SW_HIDE);

		m_bCheckHour = false;
	}
}

//버튼클릭
void CPratice42ClockDlg::OnClickedButtonHelp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.




}
