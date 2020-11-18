// Win32_api1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Win32_api1.h"
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32API1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32API1));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))     //GetMessage()는 메시지큐에서 하나의 메시지를 꺼내서 msg에 저장
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);     //msg에 키보드 메시지가 존재하면 msg를 문자로 바꿈
            DispatchMessage(&msg);      //msg를 lpfnWndProc에 지정한 함수(윈도우프로시저)에 보냄
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32API1));
    wcex.hCursor        = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR1));
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDR_MENU1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);     //여기서 윈도우클래스를 등록해서 나중에 CreateWindow()에서 등록한 윈도우를 사용할 수 있음.. 맞나?
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   //아까 RegisterClassExW()로 등록한 윈도우를 생성.. 이게 최상위윈도우임
   //CreateWindow()의 리턴값이 윈도우핸들(=윈도우를 유지하는데 필요한 데이터구조체를 가르키는 포인터)
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, SW_SHOW);   //CreateWindow()로 생성한 윈도우가 화면에 보이게 만듦
   UpdateWindow(hWnd);          //갱신할 영역이 생기면 시스템상태와 상관없이 즉각적으로 갱신

   return TRUE;
}



//그리기GetDC(), ReleaseDC()
void RButtonPrint(HWND hWnd)
{
    char str[100];
    HDC hdc;
    for (int i = 0; i < 100; i++)
        str[i] = ((i != 98) ? ' ' : '\0');

    hdc = GetDC(hWnd);
    TextOut(hdc, 0, 0, str, strlen(str));
    ReleaseDC(hWnd, hdc);
}



//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//                       호출한 윈도우, 메시지,           부가적인 정보들
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    char str[100];
    DWORD dw_color;
    DWORD x;

    switch (message)
    {
    case WM_COMMAND:        //메뉴클릭시 실행.. wParam에 클릭한 메뉴의 ID가 전송됨
        {
            int wmId = LOWORD(wParam);  //받은 id값 형변환
            switch (wmId)   // 메뉴 선택을 구문 분석합니다:
            {
            case ID_32772:   //열기
                MessageBox(0, "열기", "매뉴연습", MB_OK);
                break;
            case ID_32773:   //저장
                MessageBox(0, "저장", "매뉴연습", MB_OK);
                break;
            case ID_32774:   //종료
                MessageBox(0, "종료", "매뉴연습", MB_OK);
                break;

            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_LBUTTONDOWN:
        dw_color = RGB(100, 200, 150);      //RGB값을 넣으면 DWORD형태로 반환해줌
        //값을 구할때는 GetRValue(de_color);형식으로 사용하면됨

        hdc = GetDC(hWnd);
        //TextOut(HDC, int x좌표, int y좌표, LPCTSTR 문자배열, int 문자길이)으로 화면에 글자를 출력가능...
        //윈도우에서는 글자를 픽셀단위로 출력함.. 따라서 문자를 아스키코드값으로 바꿔줘야함 (숫자도 문자열로 바꿔줘야함)
        //sprintf().. 메모리에 char[] 문자열을 넣어줌

        //50, 50에 RGB값 넣음 1pixel에 들어감
        SetPixel(hdc, 50, 50, RGB(111, 222, 001));

        //위치에 있는 COLORREF값을 얻음
        x = GetPixel(hdc, 50, 50);

        sprintf_s(str, "%d %d %d", GetRValue(dw_color), GetGValue(dw_color), GetRValue(x));
        TextOut(hdc, 0, 0, str, strlen(str));
        ReleaseDC(hWnd, hdc);
        break;

    case WM_RBUTTONDOWN:
        RButtonPrint(hWnd);
        break;

    case WM_PAINT:      //화면에 그리기
        {
            hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);     //메인 메시지큐에 WM_QUIT를 넣음.. 즉 윈도우종료
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
