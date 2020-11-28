#include "Core.h"

Core* Core::core = NULL;
bool Core::run = true;

Core::Core()
{

}

Core::~Core()
{
    SceneManager::ReleaseInst();
    Timer::ReleaseInst();
}

Core* Core::GetInst()
{
    if (NULL == core)
        core = new Core();

    return core;
}

void Core::ReleaseInst()
{
    delete core;
    core = NULL;
}

int Core::Run()
{
    MSG msg;

    while (run)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        Logic();
    }

    return (int)msg.wParam;
}

void Core::Logic()
{
    Timer::GetInst()->Update();     //타이머업데이트
    float deltaTime = Timer::GetInst()->GetDeltaTime();   //요값을 전달해서 이동시 사용하면됨
    
    Input(deltaTime);
    Update(deltaTime);
    LateUpdate(deltaTime);
    Collision(deltaTime);
    Render(deltaTime);
}

void Core::Input(float deltaTime)
{
    SceneManager::GetInst()->Input(deltaTime);
}

void Core::Update(float deltaTime)
{
    SceneManager::GetInst()->Update(deltaTime);
}

void Core::LateUpdate(float deltaTime)
{
    SceneManager::GetInst()->LateUpdate(deltaTime);
}

void Core::Collision(float deltaTime)
{
    SceneManager::GetInst()->Collision(deltaTime);
}

void Core::Render(float deltaTime)
{
    SceneManager::GetInst()->Render(hdc, deltaTime);
}

BOOL Core::Init(HINSTANCE hInstance)
{
    hInst = hInstance;
    ws.width = 1080;
    ws.height = 960;

    MyRegisterClass();
    Create();

    //화면DC생성
    hdc = GetDC(hWnd);

    //장면관리자 초기화
    if (!SceneManager::GetInst()->Init())
        return false;

    //타이머 초기화
    if (!Timer::GetInst()->Init())
        return false;

    return true;
}

ATOM Core::MyRegisterClass()
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = Core::WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInst;
    wcex.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;   //MAKEINTRESOURCEW(IDC_WIN32APIPRATICE);
    wcex.lpszClassName = L"SimpleGame";  //szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

    return RegisterClassExW(&wcex);
}

bool Core::Create()
{
    hWnd = CreateWindowW(L"SimpleGame", L"SimpleGame2", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInst, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    //윈도우 시작위치 및 크기 각종설정값들 지정
    SetWindowPos(hWnd, HWND_TOPMOST, 100, 100, ws.width, ws.height, SWP_NOMOVE | SWP_NOZORDER);

    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);

    return TRUE;
}

LRESULT CALLBACK Core::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static POINT mousePosition{ 0, 0 };

    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);


        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        run = false;
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}