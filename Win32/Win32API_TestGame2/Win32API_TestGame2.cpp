// Win32API_TestGame2.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Win32API_TestGame2.h"
#include <cstdio>
#include <list>
#include <cmath>

using namespace std;

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

typedef struct {
    float x;
    float y;
    float r;
    float angle;
    float startDistance;
    float limitDistance;
}Circle, *pCircle;

HWND hWnd;
pCircle player;
list<pCircle> bullets;

//time
LARGE_INTEGER gATime;   //총프레임시간
LARGE_INTEGER gCTime;   //현재프레임
float gDTime;           //프레임간의차이

//총구
float gunX;
float gunY;
float gunLength = 100.f;
float gunAngle;

void TestFunc();

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
    LoadStringW(hInstance, IDC_WIN32APITESTGAME2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32APITESTGAME2));

    MSG msg;

    QueryPerformanceFrequency(&gATime);

    // 기본 메시지 루프입니다:
    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                return 0;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            TestFunc();
        }
    }

    return (int) msg.wParam;
}

void TestFunc()
{
    RECT r;
    GetClientRect(hWnd, &r);
    HDC hdc = GetDC(hWnd);
    HDC mdc = CreateCompatibleDC(hdc);
    HBITMAP hbmp = CreateCompatibleBitmap(hdc, r.right, r.bottom);
    SelectObject(mdc, hbmp);
    FillRect(mdc, &r, (HBRUSH)GetStockObject(WHITE_BRUSH)); //도화지 색 변경

    //DeltaTime(프레임과 프레임사이의 시간)구하기
    LARGE_INTEGER cTime;                //현재프레임시간
    QueryPerformanceCounter(&cTime);    //현재프레임시간구하기
    static float timeScale = 1.0f;      //1초에 이동속도 300.. 증가하면 3초에 300 이런식으로
    float speedIncrease = 0.0f;         //속도증가량 %로

    //       (현재프레임 - 이전프레임) / 전체프레임 => 현재 지난 시간 
    gDTime = (cTime.QuadPart - gCTime.QuadPart) / (float)gATime.QuadPart;
    gCTime = cTime;

    //타임스케일조정 (F1이속증가, F2이속감소)
    if (GetAsyncKeyState(VK_F1) & 0x8000)
    {
        timeScale -= gDTime;
        if (timeScale <= 0.1f)     //최저이동속도
            timeScale = 0.1f;
    }
    if (GetAsyncKeyState(VK_F2) & 0x8000)
    {
        timeScale += gDTime;
        if (timeScale >= 3)     //최고이동속도
            timeScale = 3.0f;
    }

   //플레이어 이동
    float playerSpeed = (300.f + 300.f * speedIncrease) * gDTime * timeScale;
    if (GetAsyncKeyState(VK_UP))
    {
        player->y -= playerSpeed;
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        player->y += playerSpeed;
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        player->x -= playerSpeed;
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        player->x += playerSpeed;
    }

    //총구방향
    if (GetAsyncKeyState('A'))
    {
        player->angle += playerSpeed * 0.05f;
    }
    if (GetAsyncKeyState('D'))
    {
        player->angle -= playerSpeed * 0.05f;
    }

    //총구
    gunAngle = player->angle;
    gunX = player->x + cosf(gunAngle) * gunLength;
    gunY = player->y + sinf(gunAngle) * gunLength;
    
    //총알생성
    if (GetAsyncKeyState(VK_SPACE))
    {
        bullets.emplace_back(new Circle{ player->x + player->r * cosf(player->angle), player->y + player->r * sinf(player->angle), 25.f, gunAngle, 0, 500 });
    }

    //총알스킬1
    if (GetAsyncKeyState('1'))
    {
        float a = player->angle - 3.141592 / 12.f;
        for (int i = -1; i <= 1; i++)
        {
            bullets.emplace_back(new Circle{ player->x + player->r * cosf(a), player->y + player->r * sinf(a), 25.f, a, 0, 500 });
            a += 3.141592 / 12.f;
        }
    }

    //총알발사
    float bulletSpeed = (500.f + 500.f * speedIncrease) * gDTime * timeScale;
    for (auto bullet : bullets)
    {
        bullet->x += bulletSpeed * cosf(bullet->angle);
        bullet->y += bulletSpeed * sinf(bullet->angle);
    }
    char str[100];

    //그리기
    Ellipse(mdc, player->x - player->r, player->y - player->r, player->x + player->r, player->y + player->r);
    MoveToEx(mdc, player->x, player->y, NULL);
    LineTo(mdc, gunX, gunY);
    for (auto bullet : bullets)
    {
        Ellipse(mdc, bullet->x - bullet->r, bullet->y - bullet->r, bullet->x + bullet->r, bullet->y + bullet->r);
    }

    BitBlt(hdc, 0, 0, r.right, r.bottom, mdc, 0, 0, SRCCOPY);

    DeleteDC(mdc);
    DeleteObject(hbmp);
    ReleaseDC(hWnd, hdc);
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32APITESTGAME2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32APITESTGAME2);
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
    switch (message)
    {
    case WM_CREATE:
        //player_init()
        player = new Circle();
        player->x = 100;
        player->y = 100;
        player->r = 50;
        player->startDistance = player->x;
        player->limitDistance = player->x + 500.f;
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
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        delete player;
        for (auto bullet : bullets)
        {
            delete bullet;
        }
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
