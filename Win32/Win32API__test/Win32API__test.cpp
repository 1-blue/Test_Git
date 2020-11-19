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



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
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

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

//왼쪽버튼눌렀을때 글자출력
void LButtonDownTest(HWND hWnd)
{
    HDC hdc = GetDC(hWnd);

    TextOut(hdc, 10, 10, "LButtonDown", 12);

    ReleaseDC(hWnd, hdc);
}
//오른쪽버튼눌렀을때 글자출력
void LButtonUPTest(HWND hWnd)
{
    HDC hdc = GetDC(hWnd);

    TextOut(hdc, 10, 10, "LButtonUP", 10);

    ReleaseDC(hWnd, hdc);
}

//펜으로 직선그리기
void PrintStraight(HWND hWnd)
{
    HDC hdc = GetDC(hWnd);

    //펜얻기
    HPEN hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));
    //펜선택
    HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);
    //그리기
    MoveToEx(hdc, 10, 100, NULL);
    LineTo(hdc, 200, 100);
    //원래펜으로교체
    SelectObject(hdc, hOldPen);
    //사용한 펜 삭제
    DeleteObject(hPen);

    ReleaseDC(hWnd, hdc);
}

//펜으로 사각형그리기
void PrintRectangle(HWND hWnd)
{
    static int count = 0;
    //HDC얻기.. 화면에 그리기위한 DC
    HDC hdc = GetDC(hWnd);
    //펜얻기
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
    switch (count)
    {
    case 0:
        hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
        break;
    case 1:
        hPen = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));
        break;
    case 2:
        hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
        count = -1;
        break;
    }
    
    //펜선택
    HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);
    //그리기
    Rectangle(hdc, 100, 100, 200, 200);
    //펜교체
    SelectObject(hdc, hOldPen);
    //펜삭제
    DeleteObject(hPen);

    ReleaseDC(hWnd, hdc);
    count++;
}

//움직일 사각형
RECT rect{ 100, 100, 200, 200 };

//브러시로 사각형 그리기
void PrintRectangleToBrush(HWND hWnd)
{
    static int count = 0;

    HDC hdc = GetDC(hWnd);
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
    //switch (++count)
    //{
    //case 0:
    //    hBrush = CreateSolidBrush(RGB(255, 0, 0));
    //    break;
    //case 1:
    //    hBrush = CreateSolidBrush(RGB(0, 255, 0));
    //    break;
    //case 2:
    //    hBrush = CreateSolidBrush(RGB(0, 0, 255));
    //    count = -1;
    //    break;
    //}
    
    HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
    Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
    SelectObject(hdc, hOldBrush);
    DeleteObject(hBrush);

    ReleaseDC(hWnd, hdc);
}

//마우스위치
POINT mousePosition{ 0, 0 };
//LButton클릭시 마우스 위치
POINT clikcMousePosition{ 0, 0 };
//이동거리계산
POINT moveMousePosition{ 0, 0 };

bool isClicked = false;

//마우스좌표출력
void PrintMousePosition(HWND hWnd)
{
    char str[100];
    HDC hdc = GetDC(hWnd);
    sprintf_s(str, "마우스 x : %d, 마우스 y : %d", mousePosition.x, mousePosition.y);
    TextOut(hdc, 10, 10, str, strlen(str));

    ReleaseDC(hWnd, hdc);
}



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_KEYDOWN:
        switch (wParam)     //wParam : 키보드로부터 입력받은 키를 가상키로 받음
        {
        case VK_LEFT:
            rect.left -= 5;
            rect.right -= 5;
            break;
            
        case VK_RIGHT:
            rect.left += 5;
            rect.right += 5;
            break;

        case VK_UP:
            rect.top -= 5;
            rect.bottom -= 5;
            break;

        case VK_DOWN:
            rect.top += 5;
            rect.bottom += 5;
            break;
        }
        InvalidateRect(hWnd, NULL, true);
        break;

    case WM_MOUSEMOVE:
        mousePosition.x = LOWORD(lParam);
        mousePosition.y = HIWORD(lParam);
        InvalidateRect(hWnd, NULL, true);
        break;

    case WM_LBUTTONDOWN:
        if ((mousePosition.x >= rect.left && mousePosition.x <= rect.right) && (mousePosition.y >= rect.top && mousePosition.y <= rect.bottom))  //마우스가 사각형내부에 존재한다면
        {
            clikcMousePosition.x = mousePosition.x;
            clikcMousePosition.y = mousePosition.y;
            isClicked = true;
        }
        break;

    case WM_LBUTTONUP:
        if (isClicked == true)
        {
            moveMousePosition.x = mousePosition.x - clikcMousePosition.x;
            moveMousePosition.y = mousePosition.y - clikcMousePosition.y;
            rect.left += moveMousePosition.x;
            rect.right += moveMousePosition.x;
            rect.top += moveMousePosition.y;
            rect.bottom += moveMousePosition.y;
            isClicked = false;
        }
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
            
            PrintRectangleToBrush(hWnd);
            PrintMousePosition(hWnd);

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
