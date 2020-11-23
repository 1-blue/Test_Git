// Win32API_BitMap.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Win32API_BitMap.h"

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
    LoadStringW(hInstance, IDC_WIN32APIBITMAP, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32APIBITMAP));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32APIBITMAP));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32APIBITMAP);
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

//비트맵
//bmp, jpg, gif, tga등 사용
//비트맵다루는방법2가지
//1. 비트맵을 리소스에 등록해서 사용
//2. LoadImage()함수 이용해서 파일로부터 읽어서 사용

//1. 비트맵의 핸들을 얻고  LoadImage()
//2. 메모리 DC를 얻고   HDC CreateCompatibleDC(HDC, hdc);    //이미지를 메모리에 적재하기위해
//3. 핸들을 선택하고    HGDIOBJ SelectObject(HDC hdc, h);    //메모리DC에 비트맵 적용
//4. 비트맵을 화면에 출력  BOOL BitBlt(hdc, int x, int y, int w, int h, HDC 메모리DC, int x, int y(메모리DC의 시작위치), DWORD 출력방법)
//이미지사이즈를 얻는 함수 : GetObject()
//5. 메모리DC와 비트맵 제거 : DeleteDC(), DeleteObject()

//이미지 출력관련 변수들 저장한 구조체
struct ImageData
{
    HBITMAP hFileLoadBitMap;    //이미지파일을 읽음
    HBITMAP oldBitMap;      //이미지파일을 읽음
    HDC hMemorydc;          //메모리DC 
    BITMAP bm;      //이미지크기받아올 비트맵 구조체변수(bm.w, bm.h)
};

//이미지 시작위치값을 저장할 구조체변수
RECT imagePosition{ 10, 10, 0, 0 };

//이미지 출력하는 함수
void FileImagePrint(HWND hWnd, const char* path)
{
    ImageData* Data = new ImageData();
    HDC hdc = GetDC(hWnd);
    //1. 비트맵의 핸들얻기
    Data->hFileLoadBitMap = (HBITMAP)LoadImage(NULL, path, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE | LR_DEFAULTSIZE);
    if (Data->hFileLoadBitMap == NULL)
    {
        MessageBox(hWnd, "이미지로드실패", "로드실패", MB_OK);
        return;
    }
    //2. 메모리DC생성... (화면특성과 동일한 DC를 메모리DC라고함)
    Data->hMemorydc = CreateCompatibleDC(hdc);  //인자로 전달해준 DC와 동일한 특성을 가지는 메모리DC를 만들어서 반환
    //3. 메모리DC사용을 설정
    Data->oldBitMap = (HBITMAP)SelectObject(Data->hMemorydc, Data->hFileLoadBitMap);    //메모리DC에 읽은 BITMAP핸들을 넣고
    //3-5 이미지크기받기
    GetObject(Data->hFileLoadBitMap, sizeof(BITMAP), &Data->bm);
    imagePosition.right = Data->bm.bmWidth + imagePosition.left;
    imagePosition.bottom = Data->bm.bmHeight + imagePosition.top;
    //4. 비트맵출력
    BitBlt(hdc, imagePosition.left, imagePosition.top, Data->bm.bmWidth, Data->bm.bmHeight, Data->hMemorydc, 0, 0, SRCCOPY);   //hdc즉 윈도우화면에 메모리DC를 복사해서 넣음
    //5. 사용한 DC 및 비트맵 삭제
    DeleteObject(Data->hFileLoadBitMap);
    DeleteDC(Data->hMemorydc);

    ReleaseDC(hWnd, hdc);
    delete Data;
}

//사각형출력
void PrintRactangle(HWND hWnd)
{
    HDC hdc = GetDC(hWnd);
    HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255));
    HBRUSH old = (HBRUSH)SelectObject(hdc, hBrush);
    Rectangle(hdc, 500, 500, 600, 600);
    SelectObject(hdc, old);
    DeleteObject(hBrush);
    ReleaseDC(hWnd, hdc);
}

//마우스위치를저장할 구조체변수
POINT mousePosition{ 0,0 };

//마우스 이동거리넣을 구조체
POINT mouseMove{ 0,0 };

//그림 움직이는거 제한
bool is = false;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_MOUSEMOVE:
        mousePosition.x = LOWORD(lParam);   //마우스가로위치.. 이것들도 자세히 알아보기
        mousePosition.y = HIWORD(lParam);   //마우스세로위치
        break;

    case WM_LBUTTONDOWN:
        if ((mousePosition.x >= imagePosition.left && mousePosition.x <= imagePosition.right) && (mousePosition.y >= imagePosition.top && mousePosition.y <= imagePosition.bottom))
        {
            mouseMove.x = mousePosition.x;
            mouseMove.y = mousePosition.y;
            is = true;
        }
        break;

    case WM_LBUTTONUP:
        if (is == false)
            break;
        imagePosition.left += mousePosition.x - mouseMove.x;
        imagePosition.right += mousePosition.x - mouseMove.x;
        imagePosition.top += mousePosition.y - mouseMove.y;
        imagePosition.bottom += mousePosition.y - mouseMove.y;
        InvalidateRect(hWnd, NULL, true);
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
            Rectangle(hdc, 0, 0, 200, 200);
            FileImagePrint(hWnd, "image\\test.bmp");
            
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
