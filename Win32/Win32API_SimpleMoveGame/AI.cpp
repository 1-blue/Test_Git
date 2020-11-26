#include "AI.h"

//����Ʈ�Ű����� ���� ������..? �⺻�μ������Ƕ�µ�
//�ð������� 100������ 1��
AI::AI(HWND hWnd, RECT characterRect, unsigned int speed, double shotInterval)
    : Object(hWnd, characterRect, speed)
{
    //����ġ�� ������������.. 
    objectRect.left = static_cast<double>(clientRect.right) - 100.0;
    objectRect.top = 0.0;
    objectRect.right = objectRect.left + 100.0;
    objectRect.bottom = objectRect.top + 100.0;

    this->shotInterval = shotInterval;

    QueryPerformanceFrequency(&this->bulletSpeedValue.allTime);    //��ü �ʴ� �����Ӽ�
    QueryPerformanceCounter(&this->bulletSpeedValue.currentTime);  //���� �����Ӽ�
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
    LARGE_INTEGER cTime;                //���������ӽð�
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

