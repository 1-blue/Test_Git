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
    QueryPerformanceFrequency(&this->moveSpeedValue.allTime);    //��ü �ʴ� �����Ӽ�
    QueryPerformanceCounter(&this->moveSpeedValue.currentTime);  //���� �����Ӽ�
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
    //DeltaTime(�����Ӱ� �����ӻ����� �ð�)���ϱ�
    LARGE_INTEGER cTime;                //���������ӽð�
    QueryPerformanceCounter(&cTime);    //���������ӽð����ϱ�

    //       (���������� - ����������) / ��ü������ => ���� ���� �ð� 
    this->moveSpeedValue.DeltaTime = (cTime.QuadPart - this->moveSpeedValue.currentTime.QuadPart) / static_cast<double>(this->moveSpeedValue.allTime.QuadPart);
    this->moveSpeedValue.currentTime = cTime;

    //Ÿ�ӽ��������� (F1�̼�����, F2�̼Ӱ���)
    if (GetAsyncKeyState(VK_F1) & 0x8000)
    {
        this->moveSpeedValue.timeScale -= this->moveSpeedValue.DeltaTime;
        if (this->moveSpeedValue.timeScale <= this->moveSpeedValue.miniumSpeed)     //�����̵��ӵ�
            this->moveSpeedValue.timeScale = this->moveSpeedValue.miniumSpeed;
    }
    if (GetAsyncKeyState(VK_F2) & 0x8000)
    {
        this->moveSpeedValue.timeScale += this->moveSpeedValue.DeltaTime;
        if (this->moveSpeedValue.timeScale >= this->moveSpeedValue.maximumSpeed)     //�ְ��̵��ӵ�
            this->moveSpeedValue.timeScale = this->moveSpeedValue.maximumSpeed;
    }

    //�÷��̾� �ʴ� �̵��ӵ� : this->moveSpeedValue.speed������
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