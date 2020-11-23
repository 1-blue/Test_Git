// Win32API__test.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Win32API__test.h"
#include <cstdio>

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.      ..하나의 프로그램 ID
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
    LoadStringW(hInstance, IDC_WIN32APITEST, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32APITEST));

    MSG msg;

    // 기본 메시지 루프입니다:
    /*while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }*/
    BOOL run = true;
    while (run)
    {
        if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            
        }
    }

    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;       //WindowClass설정.. 윈도우창만드는데 필요한 정보 등록

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32APITEST));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32APITEST);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);     //윈도우창 등록
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)        
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   //윈도우창만들기 반환값은 윈도우핸들
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);      //만든 윈도우창 그리기
   UpdateWindow(hWnd);              //변경사항있으면 업데이트하기

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HBITMAP hBitmap;
    static BITMAP bmp;
    static HDC mdc;
    static RECT r{ 0, 0, 0, 0 };
    static int deathIdx = -1;

    HBITMAP hBitmapMove;
    static BITMAP bmpMove;
    static HDC mdcMove;
    static RECT rectMove{ 0, 0, 0, 0 };
    static int rMoveIdx = -1;

    HBITMAP hBitmapAttack;
    static BITMAP bmpAttack;
    static HDC mdcAttack;
    static int rAttackIdx = -1;

    HDC hdc = GetDC(hWnd);

    switch (message)
    {
    case WM_CREATE:
        mdc = CreateCompatibleDC(GetDC(hWnd));
        r.left = 300;
        r.top = 300;
        SetTimer(hWnd, 1, 150, NULL);

        mdcMove = CreateCompatibleDC(GetDC(hWnd));
        rectMove.left = 500;
        rectMove.top = 300;

        mdcAttack = CreateCompatibleDC(GetDC(hWnd));

        break;

    case WM_TIMER:
        switch (wParam)
        {
        case 1:     //죽음
            InvalidateRect(hWnd, &r, true);
            break;
            
        case 2:     //공격
            switch (++rAttackIdx)
            {
            case 0:
                hBitmapAttack = (HBITMAP)LoadImage(NULL, "image\\우측공격\\1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                break;
            case 1:
                hBitmapAttack = (HBITMAP)LoadImage(NULL, "image\\우측공격\\2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                break;
            case 2:
                hBitmapAttack = (HBITMAP)LoadImage(NULL, "image\\우측공격\\3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                break;
            case 3:
                hBitmapAttack = (HBITMAP)LoadImage(NULL, "image\\우측공격\\4.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                break;
            case 4:
                hBitmapAttack = (HBITMAP)LoadImage(NULL, "image\\우측공격\\5.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                break;
            case 5:
                hBitmapAttack = (HBITMAP)LoadImage(NULL, "image\\우측공격\\6.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                rAttackIdx = -1;
                KillTimer(hWnd, 2);
                break;
            default:
                hBitmapAttack = (HBITMAP)LoadImage(NULL, "image\\11.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            }
            GetObject(hBitmapAttack, sizeof(BITMAP), &bmpAttack);
            SelectObject(mdcAttack, hBitmapAttack);
            BitBlt(hdc, rectMove.left, rectMove.top, rectMove.right, rectMove.bottom, mdcAttack, 0, 0, SRCCOPY);
            DeleteObject(hBitmapAttack);
            break;
        }
        break;

    case WM_KEYDOWN:
        
        switch (wParam)
        {
        case VK_RIGHT:      //우측걷기
            switch (++rMoveIdx)
            {
            case 0:
                hBitmapMove = (HBITMAP)LoadImage(NULL, "image\\우측걷기\\1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                break;
            case 1:
                hBitmapMove = (HBITMAP)LoadImage(NULL, "image\\우측걷기\\2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                break;
            case 2:
                hBitmapMove = (HBITMAP)LoadImage(NULL, "image\\우측걷기\\3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                break;
            case 3:
                hBitmapMove = (HBITMAP)LoadImage(NULL, "image\\우측걷기\\4.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                break;
            case 4:
                hBitmapMove = (HBITMAP)LoadImage(NULL, "image\\우측걷기\\5.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                break;
            case 5:
                hBitmapMove = (HBITMAP)LoadImage(NULL, "image\\우측걷기\\6.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                break;
            case 6:
                hBitmapMove = (HBITMAP)LoadImage(NULL, "image\\우측걷기\\7.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                break;
            case 7:
                hBitmapMove = (HBITMAP)LoadImage(NULL, "image\\우측걷기\\8.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                rMoveIdx = -1;
                break;
            default:
                hBitmapMove = (HBITMAP)LoadImage(NULL, "image\\11.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            }
            GetObject(hBitmapMove, sizeof(BITMAP), &bmpMove);
            SelectObject(mdcMove, hBitmapMove);
            rectMove.left += 4;
            rectMove.right = rectMove.left + bmpMove.bmWidth;
            rectMove.bottom = rectMove.top + bmpMove.bmHeight;
            BitBlt(hdc, rectMove.left, rectMove.top, rectMove.right, rectMove.bottom, mdcMove, 0, 0, SRCCOPY);
            DeleteObject(hBitmapMove);
            break;

        case VK_SPACE:      //공격
            SetTimer(hWnd, 2, 80, NULL);
            break;
        }
        DeleteDC(hdc);
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
            switch (++deathIdx)
            {
            case 0:
                hBitmap = (HBITMAP)LoadImage(NULL, "image\\사망모션\\1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                break;
            case 1:
                hBitmap = (HBITMAP)LoadImage(NULL, "image\\사망모션\\2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                break;
            case 2:
                hBitmap = (HBITMAP)LoadImage(NULL, "image\\사망모션\\3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                break;
            case 3:
                hBitmap = (HBITMAP)LoadImage(NULL, "image\\사망모션\\4.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                break;
            case 4:
                hBitmap = (HBITMAP)LoadImage(NULL, "image\\사망모션\\5.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                break;
            case 5:
                hBitmap = (HBITMAP)LoadImage(NULL, "image\\사망모션\\6.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                break;
            case 6:
                hBitmap = (HBITMAP)LoadImage(NULL, "image\\사망모션\\7.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                deathIdx = -1;
                break;
            default:
                hBitmap = (HBITMAP)LoadImage(NULL, "image\\11.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            }
            GetObject(hBitmap, sizeof(BITMAP), &bmp);
            SelectObject(mdc, hBitmap);
            r.right = r.left + bmp.bmWidth;
            r.bottom = r.top + bmp.bmHeight;
            BitBlt(hdc, r.left, r.top, r.right, r.bottom, mdc, 0, 0, SRCCOPY);
            DeleteObject(hBitmap);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        DeleteDC(mdc);
        KillTimer(hWnd, 1);
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
