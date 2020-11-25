#include "Object.h"

Object::Object(HWND hWnd, RECT characterRect, unsigned int speed)
{
    GetClientRect(hWnd, &clientRect);
    this->hWnd = hWnd;
    hdc = GetDC(hWnd);
    mdc = CreateCompatibleDC(hdc);
    hbmp = CreateCompatibleBitmap(mdc, clientRect.right, clientRect.bottom);
    SelectObject(mdc, hbmp);
    FillRect(mdc, &clientRect, (HBRUSH)GetStockObject(WHITE_BRUSH)); //��ȭ�� �� ����

    //�÷��̾� RECT�޾Ƽ� doubleRect�� ��ȯ�ؼ� ����
    //double�ϴ������� ���ݴ� �����ϰ� �����̱�����
    this->objectRect.left = static_cast<double>(characterRect.left);
    this->objectRect.top = static_cast<double>(characterRect.top);
    this->objectRect.right = static_cast<double>(characterRect.right);
    this->objectRect.bottom = static_cast<double>(characterRect.bottom);

    //�ӵ����ú����� �ʱ�ȭ
    QueryPerformanceFrequency(&this->speedValue.allTime);    //��ü �ʴ� �����Ӽ�
    QueryPerformanceCounter(&this->speedValue.currentTime);  //���� �����Ӽ�
    this->speedValue.speed = speed;
    this->speedValue.timeScale = 1.0;
    this->speedValue.speedIncrease = 0.0;
    this->speedValue.miniumSpeed = 0.1;
    this->speedValue.maximumSpeed = 5.0;
    this->speedValue.PreviousTimeScale = 0.0;
    this->speedValue.isStop = false;
}

double Object::SpeedCalculation()
{
    //DeltaTime(�����Ӱ� �����ӻ����� �ð�)���ϱ�
    LARGE_INTEGER cTime;                //���������ӽð�
    QueryPerformanceCounter(&cTime);    //���������ӽð����ϱ�

    //       (���������� - ����������) / ��ü������ => ���� ���� �ð� 
    //this->speedValue.DeltaTime = (cTime.QuadPart - this->speedValue.currentTime.QuadPart) / static_cast<double>(this->speedValue.allTime.QuadPart);
    this->speedValue.DeltaTime = (cTime.QuadPart - this->speedValue.currentTime.QuadPart) / (double)this->speedValue.allTime.QuadPart;
    this->speedValue.currentTime = cTime;

    //Ÿ�ӽ��������� (F1�̼�����, F2�̼Ӱ���)
    if (GetAsyncKeyState(VK_F1) & 0x8000)
    {
        this->speedValue.timeScale -= this->speedValue.DeltaTime;
        if (this->speedValue.timeScale <= this->speedValue.miniumSpeed)     //�����̵��ӵ�
            this->speedValue.timeScale = this->speedValue.miniumSpeed;
    }
    if (GetAsyncKeyState(VK_F2) & 0x8000)
    {
        this->speedValue.timeScale += this->speedValue.DeltaTime;
        if (this->speedValue.timeScale >= this->speedValue.maximumSpeed)     //�ְ��̵��ӵ�
            this->speedValue.timeScale = this->speedValue.maximumSpeed;
    }

    //�÷��̾� �ʴ� �̵��ӵ� : this->speedValue.speed������
    return (this->speedValue.speed + this->speedValue.speed * this->speedValue.speedIncrease) * this->speedValue.DeltaTime * this->speedValue.timeScale;
}

void Object::Pause()
{
    this->speedValue.PreviousTimeScale = this->speedValue.timeScale;
    this->speedValue.timeScale = 0;
    this->speedValue.isStop = true;
}

bool Object::IsPause()
{
    return this->speedValue.isStop;
}

void Object::PauseRelease()
{
    this->speedValue.timeScale = this->speedValue.PreviousTimeScale;
    this->speedValue.isStop = false;
}

Object::~Object()
{
    DeleteObject(hbmp);
    DeleteDC(mdc);
    ReleaseDC(hWnd, hdc);
}