#include "AI.h"

//디폴트매개변수 오류 이유는..? 기본인수재정의라는데
//시간관련은 100단위로 1초
AI::AI(HWND hWnd, RECT characterRect, unsigned int speed, double shotInterval)
    : Object(hWnd, characterRect, speed)
{
    //적위치는 오른쪽제일위.. 
    objectRect.left = static_cast<double>(clientRect.right) - 100.0;
    objectRect.top = 0.0;
    objectRect.right = objectRect.left + 100.0;
    objectRect.bottom = objectRect.top + 100.0;

    this->shotInterval = shotInterval;

    QueryPerformanceFrequency(&this->bulletSpeedValue.allTime);    //전체 초당 프레임수
    QueryPerformanceCounter(&this->bulletSpeedValue.currentTime);  //현재 프레임수
    this->bulletSpeedValue.speed = speed;
    this->bulletSpeedValue.timeScale = 1.0;
    this->bulletSpeedValue.speedIncrease = 0.0;
    this->bulletSpeedValue.miniumSpeed = 0.1;
    this->bulletSpeedValue.maximumSpeed = 5.0;
    this->bulletSpeedValue.PreviousTimeScale = 0.0;
    this->bulletSpeedValue.isStop = false;
}

double AI::ShotSpeedCalculation()
{
    LARGE_INTEGER cTime;                //현재프레임시간
    QueryPerformanceCounter(&cTime);

    this->bulletSpeedValue.DeltaTime = (cTime.QuadPart - this->bulletSpeedValue.currentTime.QuadPart) / static_cast<double>(this->bulletSpeedValue.allTime.QuadPart);
    this->bulletSpeedValue.currentTime = cTime;

    return (this->bulletSpeedValue.speed + this->bulletSpeedValue.speed * this->bulletSpeedValue.speedIncrease) * this->bulletSpeedValue.DeltaTime * this->bulletSpeedValue.timeScale;
}

void AI::Move()
{
    double dAISpeed = this->MoveSpeedCalculation();
    dAISpeed *= direction;

    objectRect.top += dAISpeed;
    objectRect.bottom += dAISpeed;

    if ((objectRect.top <= clientRect.top) || (objectRect.bottom >= clientRect.bottom))
    {
        objectRect.top = objectRect.top - dAISpeed;
        objectRect.bottom = objectRect.bottom - dAISpeed;
        direction *= -1;
    }
    shareData->SetAIRect(objectRect);
}

bool AI::IsShot()
{
    double dShotSpeed = this->ShotSpeedCalculation();
    shotValue += dShotSpeed;

    if (shotValue >= shotInterval) 
    {
        shotValue -= shotInterval;
        return true;
    }

    return false;
}

void AI::Render()
{
    this->mdc = shareData->GetMemoryDC();
    Rectangle(mdc, static_cast<int>(objectRect.left), static_cast<int>(objectRect.top), static_cast<int>(objectRect.right), static_cast<int>(objectRect.bottom));
    shareData->SetMemoryDC(mdc);
}

