#include "Object.h"

Object::Object(HWND hWnd, RECT characterRect, unsigned int speed)
{
    GetClientRect(hWnd, &clientRect);
    this->hWnd = hWnd;
    hdc = GetDC(hWnd);
    mdc = CreateCompatibleDC(hdc);
    hbmp = CreateCompatibleBitmap(mdc, clientRect.right, clientRect.bottom);
    SelectObject(mdc, hbmp);
    FillRect(mdc, &clientRect, (HBRUSH)GetStockObject(WHITE_BRUSH)); //도화지 색 변경

    //플레이어 RECT받아서 doubleRect에 변환해서 넣음
    //double하는이유는 조금더 정교하게 움직이기위함
    this->objectRect.left = static_cast<double>(characterRect.left);
    this->objectRect.top = static_cast<double>(characterRect.top);
    this->objectRect.right = static_cast<double>(characterRect.right);
    this->objectRect.bottom = static_cast<double>(characterRect.bottom);

    //속도관련변수들 초기화
    QueryPerformanceFrequency(&this->moveSpeedValue.allTime);    //전체 초당 프레임수
    QueryPerformanceCounter(&this->moveSpeedValue.currentTime);  //현재 프레임수
    this->moveSpeedValue.speed = speed;
    this->moveSpeedValue.timeScale = 1.0;
    this->moveSpeedValue.speedIncrease = 0.0;
    this->moveSpeedValue.miniumSpeed = 0.1;
    this->moveSpeedValue.maximumSpeed = 5.0;
    this->moveSpeedValue.PreviousTimeScale = 0.0;
    this->moveSpeedValue.isStop = false;
}

double Object::MoveSpeedCalculation()
{
    //DeltaTime(프레임과 프레임사이의 시간)구하기
    LARGE_INTEGER cTime;                //현재프레임시간
    QueryPerformanceCounter(&cTime);    //현재프레임시간구하기

    //       (현재프레임 - 이전프레임) / 전체프레임 => 현재 지난 시간 
    this->moveSpeedValue.DeltaTime = (cTime.QuadPart - this->moveSpeedValue.currentTime.QuadPart) / static_cast<double>(this->moveSpeedValue.allTime.QuadPart);
    this->moveSpeedValue.currentTime = cTime;

    //타임스케일조정 (F1이속증가, F2이속감소)
    if (GetAsyncKeyState(VK_F1) & 0x8000)
    {
        this->moveSpeedValue.timeScale -= this->moveSpeedValue.DeltaTime;
        if (this->moveSpeedValue.timeScale <= this->moveSpeedValue.miniumSpeed)     //최저이동속도
            this->moveSpeedValue.timeScale = this->moveSpeedValue.miniumSpeed;
    }
    if (GetAsyncKeyState(VK_F2) & 0x8000)
    {
        this->moveSpeedValue.timeScale += this->moveSpeedValue.DeltaTime;
        if (this->moveSpeedValue.timeScale >= this->moveSpeedValue.maximumSpeed)     //최고이동속도
            this->moveSpeedValue.timeScale = this->moveSpeedValue.maximumSpeed;
    }

    //플레이어 초당 이동속도 : this->moveSpeedValue.speed변수값
    return (this->moveSpeedValue.speed + this->moveSpeedValue.speed * this->moveSpeedValue.speedIncrease) * this->moveSpeedValue.DeltaTime * this->moveSpeedValue.timeScale;
}

void Object::Pause()
{
    this->moveSpeedValue.PreviousTimeScale = this->moveSpeedValue.timeScale;
    this->moveSpeedValue.timeScale = 0;
    this->moveSpeedValue.isStop = true;
}

bool Object::IsPause()
{
    return this->moveSpeedValue.isStop;
}

void Object::PauseRelease()
{
    this->moveSpeedValue.timeScale = this->moveSpeedValue.PreviousTimeScale;
    this->moveSpeedValue.isStop = false;
}

Object::~Object()
{
    DeleteObject(hbmp);
    DeleteDC(mdc);
    ReleaseDC(hWnd, hdc);
}