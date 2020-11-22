// Win32API_Window_Function.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Win32API_Window_Function.h"
#include <stdio.h>

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
    LoadStringW(hInstance, IDC_WIN32APIWINDOWFUNCTION, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32APIWINDOWFUNCTION));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32APIWINDOWFUNCTION));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32APIWINDOWFUNCTION);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

/*
* 기본적인 윈도우 스타일/크기 결정
* CreateWindowW() 3->윈도우스타일,  6/7->가로/세로
* 
* 윈도우크기/스타일변경
* BOOL WINAPI AdjustWindowRect(LPRECT lpRect,, DOWRD dwStyle, BOOL bMenu)
* 윈도우 크기 Rect값 (0, 0, 299, 299)이런식으로 넣으면됨
* 윈도우스타일 기본값인 : WS_OVERLAPPEDWINDOW 사용
* CreateWindow에서 width, height를 바꿔줘야함.. 원래값은 시스템에서 정한값으로 윈도우크기를 정하기때문에 우리가 임의로 값을변경하면 그에맞게 크기도 변경해줘야함
* 
* 클라이언트영역 크기 조사
* BOOL WINAPI GetClientRect(HWND hWnd, LPRECT lpRect)
* lpRect : 클라이언트크기를 받을 RECT변수.. 
* 단 사용할때 가로세로에 +1을 해줘야함
* 
* 윈도우 크기 조사
* BOOL WINAPI GetWindowRect(HWND hWnd, LPRECT lpRect)
* lpRect에 윈도우 크기를 받아옴
* width : right - left // height bottom - top
* 
* 윈도우의 크기와 크기변경
* BOOL WINAPI MoveWindow(HWND hWnd, int X, int Y, int width, int height, BOOL repaint)
* X, Y : 윈도우위치
* width, heigth : 윈도우크기
* repaint : 다시그릴지여부 (T/F)
* 
*/

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   RECT rect{ 0, 0, 299, 299 };
   AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, true);

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, rect.right - rect.left, rect.bottom - rect.top, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static RECT rectClient{ 0, 0, 0, 0 };
    static RECT rectWindow{ 0, 0, 0, 0 };
    char strClient[100]{ '\0' };
    char strWindow[100]{ '\0' };

    switch (message)
    {
    case WM_MOUSEMOVE:
        GetClientRect(hWnd, &rectClient);
        GetWindowRect(hWnd, &rectWindow);
        InvalidateRect(hWnd, NULL, true);
        break;

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case ID_32771:      //메뉴에 크기조절누르면 실행
                MoveWindow(hWnd, 300, 300, 300, 300, true);
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
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            
            //GetClientRect
            sprintf_s(strClient, "x : %d, y : %d, width : %d, height : %d", rectClient.left, rectClient.top, rectClient.right, rectClient.bottom);
            TextOut(hdc, 10, 10, strClient, strlen(strClient));

            //GetWindowRect
            sprintf_s(strWindow, "width : %d, height : %d", rectWindow.right - rectWindow.left, rectWindow.bottom - rectWindow.top);
            TextOut(hdc, 10, 30, strWindow, strlen(strWindow));

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
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
