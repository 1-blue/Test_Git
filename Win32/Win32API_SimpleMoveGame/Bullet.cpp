#include "Bullet.h"

Bullet::Bullet(HWND hWnd, RECT characterRect, unsigned int speed = 600, double distance = 500)
    : Object(hWnd, characterRect, speed)
{
    dRECT playerRect = shareData->GetLocation();  //플레이어 RECT값 얻기
    double bulletSize = 50;  //총알 사이즈 결정
    bullet = new BulletStructure();
    bulletRect = new dRECT();
    bulletRect->left = playerRect.right;
    bulletRect->right = playerRect.right + bulletSize;
    bulletRect->top = (playerRect.top + playerRect.bottom) / 2 - (bulletSize / 2);
    bulletRect->bottom = bulletRect->top + bulletSize;

    bullet->bulletRect = bulletRect;      //크기지정한 총알 구조체에 넣고
    bullet->startLocation = playerRect.right;                 //총알시작위치지정
    bullet->endLocation = 500.0 + playerRect.right;    //총알끝위치지정.. 사거리 500
}

void Bullet::Move()
{
    double dBulletSpeed = this->SpeedCalculation();
    //필요하면 플레이어보는방향받아서 총쏘고
    bullet->bulletRect->left += dBulletSpeed;
    bullet->bulletRect->right += dBulletSpeed;
    bullet->startLocation += dBulletSpeed;
}

void Bullet::Render()
{
    this->mdc = shareData->GetMemoryDC();
    Rectangle(mdc, static_cast<int>(bullet->bulletRect->left), static_cast<int>(bullet->bulletRect->top), static_cast<int>(bullet->bulletRect->right), static_cast<int>(bullet->bulletRect->bottom));
    shareData->SetMemoryDC(mdc);
}

bool Bullet::IsRemove()
{
    if (bullet->startLocation < bullet->endLocation)
        return true;

    return false;
}

void Bullet::ReleaseBullet()
{
    delete this->bullet->bulletRect;    //총알모양삭제
    delete this->bullet;                //총알삭제
}
