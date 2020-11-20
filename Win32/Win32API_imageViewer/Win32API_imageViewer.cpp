// Win32API_imageViewer.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Win32API_imageViewer.h"
#include <commdlg.h>
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
    LoadStringW(hInstance, IDC_WIN32APIIMAGEVIEWER, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32APIIMAGEVIEWER));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32APIIMAGEVIEWER));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32APIIMAGEVIEWER);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
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
    OPENFILENAME ofn;
    static char strFileTitle[MAX_PATH];   //파일제목.. 260
    static char strFilePath[100];             //파일경로
    char str[100];
    HBITMAP hBitmap;    //파일핸들
    static BITMAP Bitmap;      //파일크기받는데사용할구조체변수
    static HDC hmdc;           //이미지저장할 DC;

    switch (message)
    {
    case WM_LBUTTONDOWN:
        InvalidateRect(hWnd, NULL, true);
        break;

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);

            switch (wmId)
            {
            case ID_32771:      //메뉴에 열기눌렀을때 실행
                //파일열기관련설정
                memset(&ofn, 0, sizeof(OPENFILENAME));      //ofn이라는 구조체의 멤버를 모두 0으로 초기화
                ofn.lStructSize = sizeof(OPENFILENAME);     //구조체크기설정
                ofn.lpstrTitle = "파일선택해";
                ofn.lpstrFile = strFilePath;    //파일명 입력받을 배열 전송
                ofn.lpstrFilter = "비트맵(*.bmp)\0*.bmp\0JPG파일(*.jpg)\0*.jpg\0";    //설명\0파일명 순서로 넣으면됨
                ofn.nMaxFile = MAX_PATH;        //파일경로최대길이설정
                ofn.nMaxFileTitle = MAX_PATH;   //파일제목최대길이설정

                if (GetOpenFileName(&ofn) != 0) //파일호출.. 0아니면 파일이 선택된것
                {
                    //비트맵으로 읽기
                    //1. 비트맵핸들얻기                    파일경로
                    hBitmap = (HBITMAP)LoadImage(NULL, strFilePath, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE | LR_DEFAULTSIZE);    //왜경고인지 애초에 strFilePath에 패스가 설정될때 조건으로 실행하는건데 strFilePath에 값이없을수 있다는 경고? 
                    if (hBitmap == NULL)
                    {
                        MessageBox(hWnd, "이미지로드실패", "로드실패", MB_OK);
                        return 0;
                    }
                    //2. 이미지 그려둘 DC생성
                    hmdc = CreateCompatibleDC(GetDC(hWnd));
                    //3. 복사한 DC에 이미지 그리기??
                    SelectObject(hmdc, hBitmap);

                    GetObject(hBitmap, sizeof(BITMAP), &Bitmap);

                    DeleteObject(hBitmap);

                    //출력
                    InvalidateRect(hWnd, NULL, true);
                }
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
            if (hmdc != NULL)
                BitBlt(hdc, 0, 0, Bitmap.bmWidth, Bitmap.bmHeight, hmdc, 0, 0, SRCCOPY);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        DeleteDC(hmdc);
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
