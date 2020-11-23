// Win32API__.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Win32API__.h"
#include <stdio.h>

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
HWND hWnd;
RECT rc{ 0, 0, 0, 0 };

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
    LoadStringW(hInstance, IDC_WIN32API, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32API));

    MSG msg;
    bool running = true;
    static RECT r{ 0, 0, 100 ,100 };
    static RECT r2{ 100, 100, 200 ,200 };
    static char str[10];

    while (true)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))       //메시지있으면실행
        {
            if (msg.message == WM_QUIT)
                return 0;
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else        //메시지 없으면 실행    
        {
            GetClientRect(hWnd, &rc);
            HDC hdc = GetDC(hWnd);
            HDC mdc = CreateCompatibleDC(hdc);
            HBITMAP mBitmap = CreateCompatibleBitmap(mdc, rc.right, rc.bottom);

            SelectObject(mdc, mBitmap);
            FillRect(mdc, &rc, (HBRUSH)GetStockObject(WHITE_BRUSH)); //도화지 색 변경

            r.left++;
            r.right++;

            if (r.left >= rc.right)
            {
                r.left = 0;
                r.right = 100;
            }

            switch (msg.message)
            {
            case WM_KEYDOWN:
                if (GetAsyncKeyState(VK_RIGHT))
                {
                    r2.left++;
                    r2.right++;
                }
                if (GetAsyncKeyState(VK_LEFT))
                {
                    r2.left--;
                    r2.right--;
                }
                Rectangle(mdc, r2.left, r2.top, r2.right, r2.bottom);
                break;
            }

            Rectangle(mdc, r.left, r.top, r.right, r.bottom);
            Rectangle(mdc, r2.left, r2.top, r2.right, r2.bottom);

            BitBlt(hdc, 0, 0, rc.right, rc.bottom, mdc, 0, 0, SRCCOPY);

            DeleteObject(mBitmap);
            ReleaseDC(hWnd, mdc);
            ReleaseDC(hWnd, hdc);
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32API));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32API);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

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
    static RECT r{ 100, 100, 200, 200 };

    switch (message)
    {
    case WM_KEYDOWN:
        //if (wParam == VK_RIGHT)
        //{
        //    HDC hdc = GetDC(hWnd);
        //    HDC mdc = CreateCompatibleDC(hdc);
        //    HBITMAP hBitmap = CreateCompatibleBitmap(mdc, rc.right, rc.bottom);
        //    SelectObject(mdc, hBitmap);
        //    FillRect(mdc, &rc, (HBRUSH)GetStockObject(WHITE_BRUSH)); //도화지 색 변경

        //    Rectangle(mdc, r.left, r.top, r.right, r.bottom);
        //    r.left++;
        //    r.right++;

        //    BitBlt(hdc, 0, 0, rc.right, rc.bottom, mdc, 0, 0, SRCCOPY);

        //    DeleteObject(hBitmap);
        //    ReleaseDC(hWnd, mdc);
        //    ReleaseDC(hWnd, hdc);
        //}
        break;

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
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
