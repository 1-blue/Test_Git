// Win32API_TestGame.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Win32API_TestGame.h"
#include <list>

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

//내가추가한것들
//float형 Rectangle
typedef struct {
    float l, t, r, b;
}fRect, *fPtrRect;
//총알구조체(총알크기, 사거리)
typedef struct {
    fPtrRect pBulletRect;
    float fDist;         //총알시작위치
    float fLimitDist;    //총알사거리
}bullet, *pBullet;

HWND hWnd;
bool gRun = true;
RECT gClientRect{ 0,0,800,600 };
fRect gPlayerRect{ 100,100,200,200 };

//시간계산
LARGE_INTEGER gATime;   //총프레임시간
LARGE_INTEGER gCTime;   //현재프레임
float gDTime;           //프레임간의차이

//플레이어총알
list<pBullet> gPlayerBullets;

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
    LoadStringW(hInstance, IDC_WIN32APITESTGAME, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32APITESTGAME));

    MSG msg;
    
    QueryPerformanceFrequency(&gATime);     //총프레임시간
    QueryPerformanceCounter(&gCTime);       //현재프레임시간

    // 기본 메시지 루프입니다:
    while (gRun)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
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
    HDC hdc = GetDC(hWnd);

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

    //플레이어 초당 이동속도 : 300
    float fPlayerSpeed = (300.f + 300.f * speedIncrease) * gDTime * timeScale;

    //만약 0.01초마다 한번씩 TestFunc()가 호출된다치면
    //gDTime이 0.01이 나올거고
    //fSpeed에는 300 * 0.01이고
    //그거를 위치값에서다가 더해주니까 값이 계속누적됨
    //누적되다보면 1초지나면 300만큼움직이게되는 개념

    //플레이어움직임
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        gPlayerRect.l += fPlayerSpeed;
        gPlayerRect.r += fPlayerSpeed;
    }
    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        gPlayerRect.l -= fPlayerSpeed;
        gPlayerRect.r -= fPlayerSpeed;
    }
    if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
        gPlayerRect.t -= fPlayerSpeed;
        gPlayerRect.b -= fPlayerSpeed;
    }
    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        gPlayerRect.t += fPlayerSpeed;
        gPlayerRect.b += fPlayerSpeed;
    }

    //플레이어의 총알이동속도 : 600
    float fbulletSpeed = 600.f * gDTime * timeScale;   

    //총알발사
    if (GetAsyncKeyState(VK_SPACE) & 0x8000)
    {
        float bulletSize = 50;  //총알 사이즈 결정
        pBullet bullets = new bullet();
        fPtrRect bullet = new fRect();
        bullet->l = gPlayerRect.r;
        bullet->r = gPlayerRect.r + bulletSize;
        bullet->t = (gPlayerRect.t + gPlayerRect.b) / 2 - (bulletSize / 2);
        bullet->b = bullet->t + bulletSize;

        bullets->pBulletRect = bullet;      //크기지정한 총알 구조체에 넣고
        bullets->fDist = gPlayerRect.r;                 //총알시작위치지정
        bullets->fLimitDist = 500.f + gPlayerRect.r;    //총알끝위치지정.. 사거리 500
        gPlayerBullets.emplace_back(bullets);
    }
    //플레이어 총알이동
    for (auto& bullet : gPlayerBullets)
    {
        bullet->pBulletRect->l += fbulletSpeed;
        bullet->pBulletRect->r += fbulletSpeed;
        bullet->fDist += fbulletSpeed;
    }
    //총알삭제
    for(auto bullet = gPlayerBullets.begin(); bullet != gPlayerBullets.end();)
    {
        if ((*bullet)->fDist < (*bullet)->fLimitDist)   //총알사거리초과시 삭제
        {
            bullet++;
            continue;
        }
        
        delete (*bullet)->pBulletRect;          //총알크기구조체삭제
        delete (*bullet);                       //총알구조체삭제
        bullet = gPlayerBullets.erase(bullet);  //총알리스트에서 삭제
    }
    //플레이어 총알그리기
    for (auto& bMove : gPlayerBullets)
    {
        Rectangle(hdc, bMove->pBulletRect->l, bMove->pBulletRect->t, bMove->pBulletRect->r, bMove->pBulletRect->b);
    }

    Rectangle(hdc, gPlayerRect.l, gPlayerRect.t, gPlayerRect.r, gPlayerRect.b);

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32APITESTGAME));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName = NULL;//MAKEINTRESOURCEW(IDC_WIN32APITESTGAME);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   //윈도우창크기를 지정한 크기로바꿈
   AdjustWindowRect(&gClientRect, WS_OVERLAPPED, false);
   //시작위치랑 지정한 크기를 메뉴바계산해서 정확하게 만듦
   SetWindowPos(hWnd, HWND_TOPMOST, 200, 200, gClientRect.right - gClientRect.left, gClientRect.bottom - gClientRect.top, SWP_NOZORDER);

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
        gRun = false;
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