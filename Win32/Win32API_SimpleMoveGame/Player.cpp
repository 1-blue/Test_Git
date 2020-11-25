#include "Player.h"

Player::Player(HWND hWnd, RECT characterRect, unsigned int speed = 300)
    : Object(hWnd, characterRect, speed)
{
}

void Player::Move()
{
    double dPlayerSpeed = this->SpeedCalculation();

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        objectRect.left += dPlayerSpeed;
        objectRect.right += dPlayerSpeed;
        dir = PlayerDiraction::dir::RIGTH;
    }
    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        objectRect.left -= dPlayerSpeed;
        objectRect.right -= dPlayerSpeed;
        dir = PlayerDiraction::dir::LEFT;
    }
    if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
        objectRect.top -= dPlayerSpeed;
        objectRect.bottom -= dPlayerSpeed;
        dir = PlayerDiraction::dir::TOP;
    }
    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        objectRect.top += dPlayerSpeed;
        objectRect.bottom += dPlayerSpeed;
        dir = PlayerDiraction::dir::BOTTOM;
    }

    shareData->SetLocation(objectRect);
}

void Player::Render()
{
    this->mdc = shareData->GetMemoryDC();
    Rectangle(mdc, static_cast<int>(objectRect.left), static_cast<int>(objectRect.top), static_cast<int>(objectRect.right), static_cast<int>(objectRect.bottom));
    shareData->SetMemoryDC(mdc);
}

int Player::GetDiraction()
{
    return this->dir;
}


