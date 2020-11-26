#include "Player.h"

Player::Player(HWND hWnd, RECT characterRect, unsigned int speed = 300)
    : Object(hWnd, characterRect, speed)
{
}

void Player::Move()
{
    double dPlayerSpeed = this->MoveSpeedCalculation();

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        objectRect.left += dPlayerSpeed;
        objectRect.right += dPlayerSpeed;
        dir = CHARACTERDIRECTION::dir::RIGTH;
    }
    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        objectRect.left -= dPlayerSpeed;
        objectRect.right -= dPlayerSpeed;
        dir = CHARACTERDIRECTION::dir::LEFT;
    }
    if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
        objectRect.top -= dPlayerSpeed;
        objectRect.bottom -= dPlayerSpeed;
        dir = CHARACTERDIRECTION::dir::TOP;
    }
    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        objectRect.top += dPlayerSpeed;
        objectRect.bottom += dPlayerSpeed;
        dir = CHARACTERDIRECTION::dir::BOTTOM;
    }

    shareData->SetPlayerRect(objectRect);
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


