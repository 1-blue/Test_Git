#include "Bullet.h"

Bullet::Bullet(HWND hWnd, RECT characterRect, unsigned int speed = 600, double distance = 500)
    : Object(hWnd, characterRect, speed)
{
    dRECT playerRect = shareData->GetLocation();  //�÷��̾� RECT�� ���
    double bulletSize = 50;  //�Ѿ� ������ ����
    bullet = new BulletStructure();
    bulletRect = new dRECT();
    bulletRect->left = playerRect.right;
    bulletRect->right = playerRect.right + bulletSize;
    bulletRect->top = (playerRect.top + playerRect.bottom) / 2 - (bulletSize / 2);
    bulletRect->bottom = bulletRect->top + bulletSize;

    bullet->bulletRect = bulletRect;      //ũ�������� �Ѿ� ����ü�� �ְ�
    bullet->startLocation = playerRect.right;                 //�Ѿ˽�����ġ����
    bullet->endLocation = 500.0 + playerRect.right;    //�Ѿ˳���ġ����.. ��Ÿ� 500
}

void Bullet::Move()
{
    double dBulletSpeed = this->SpeedCalculation();
    //�ʿ��ϸ� �÷��̾�¹���޾Ƽ� �ѽ��
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
    delete this->bullet->bulletRect;    //�Ѿ˸�����
    delete this->bullet;                //�Ѿ˻���
}
