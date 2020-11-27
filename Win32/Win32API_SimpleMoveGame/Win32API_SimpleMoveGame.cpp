// Win32API_SimpleMoveGame.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Win32API_SimpleMoveGame.h"
#include <cstdio>
#include <list>
#include "Player.h"
#include "Bullet.h"
#include "AI.h"

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

//사용할 변수들
bool run = true;
HWND hWnd;
Player* player;
AI* ai;
list<Bullet*> playerBullets;
list<Bullet*> aiBullets;
ShareData* shareData = ShareData::GetInstance();
RECT clientRect{ 0,0,0,0 };
RECT playerRect{ 100, 100, 200, 200 };

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32APISIMPLEMOVEGAME, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    MSG msg;
    HBITMAP hbmp;
    HDC mdc;
    static RECT aiBulletRect{ 0, 0, 50, 50 };

    while (run)
    {
        if (PeekMessage(&msg, hWnd, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            player->Move();
            player->Render();
            ai->Move();
            ai->Render();

            //ai총쏘기.. ai가 가진 변수값을 사용해서 총쏘는 시간간격 결정
            if (ai->IsShot())
                aiBullets.emplace_back(new Bullet(hWnd, aiBulletRect, CHARACTER::AI, 600, 500));
            
            //플레이어 총알이동
            for (auto b : playerBullets)
                b->Move();

            //ai총알 이동
            for (auto b : aiBullets)
                b->Move();

            //충돌or사거리초과시 플레이어총알삭제
            for (auto b = playerBullets.begin(); b != playerBullets.end();)
            {
                if ((*b)->IsDistanceLimited() || (*b)->IsCrash())   //총알사거리초과시 삭제
                {
                    (*b)->ReleaseBullet();        //총알RECT랑 총알구조체 메모리반환
                    b = playerBullets.erase(b);   //총알리스트에서 삭제
                }
                else
                    b++;
            }
            //충돌or사거리초과시 ai총알삭제
            for (auto b = aiBullets.begin(); b != aiBullets.end();)
            {
                if ((*b)->IsDistanceLimited() || (*b)->IsCrash())   //총알사거리초과시 삭제
                {
                    (*b)->ReleaseBullet();  //총알RECT랑 총알구조체 메모리반환
                    b = aiBullets.erase(b);   //총알리스트에서 삭제
                }
                else
                    b++;
            }

            //플레이어 총알 그리기
            for (auto b : playerBullets)
                b->Render();

            //ai총알 그리기
            for (auto b : aiBullets)
                b->Render();

            //더블버퍼링처리
            mdc = shareData->GetMemoryDC();
            GetClientRect(hWnd, &clientRect);
            BitBlt(GetDC(hWnd), 0, 0, clientRect.right, clientRect.bottom, mdc, 0, 0, SRCCOPY);

            DeleteObject(shareData->GetHBitMap());
            DeleteDC(mdc);
            mdc = CreateCompatibleDC(GetDC(hWnd));
            hbmp = CreateCompatibleBitmap(mdc, clientRect.right, clientRect.bottom);

            SelectObject(mdc, hbmp);
            FillRect(mdc, &clientRect, (HBRUSH)GetStockObject(WHITE_BRUSH)); //도화지 색 변경
            shareData->SetHBitMap(hbmp);
            shareData->SetMemoryDC(mdc);
        }
    }

    ShareData::ReleaseInstance();
    delete player;

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32APISIMPLEMOVEGAME));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32APISIMPLEMOVEGAME);
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
        player = new Player(hWnd, playerRect, 300);
        ai = new AI(hWnd, playerRect, 100, 200);

        break;

    case WM_KEYDOWN:        //음... 이위치가맞는지모르겠네
        if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && !(player->IsPause()) )
        {
            playerBullets.emplace_back(new Bullet(hWnd, playerRect, CHARACTER::PLAYER, 600, 300));
        }
        if ((GetAsyncKeyState(VK_ESCAPE) & 0x8000) && !(player->IsPause()))
        {
            player->Pause();
            for (auto b : playerBullets)
                b->Pause();
        }
        if ((GetAsyncKeyState(VK_TAB) & 0x8000) && player->IsPause())
        {
            player->PauseRelease();
            for (auto b : playerBullets)
                b->PauseRelease();
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
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        run = false;
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
