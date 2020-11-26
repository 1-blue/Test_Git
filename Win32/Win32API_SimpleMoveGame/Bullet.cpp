#include "Bullet.h"

Bullet::Bullet(HWND hWnd, RECT characterRect, int isCharacter, unsigned int speed, double distance)
    : Object(hWnd, characterRect, speed)
{
    double bulletSize = 50;  //�Ѿ� ������ ����
    bullet = new BulletStructure();
    bulletRect = new dRECT();
    dRECT rect;              //ĳ������ RECT�� ���.. �Ѿ˹���, ������ġ����
    this->bullet->isCharacter = isCharacter;
    
    switch (isCharacter)
    {
    case CHARACTER::PLAYER:
        rect = shareData->GetPlayerRect();
        this->bullet->direction = 1;
        bulletRect->left = rect.right;
        bulletRect->right = rect.right + bulletSize;
        bulletRect->top = (rect.top + rect.bottom) / 2 - (bulletSize / 2);
        bulletRect->bottom = bulletRect->top + bulletSize;
        bullet->startLocation = bulletRect->right;              //�Ѿ˽�����ġ����
        bullet->endLocation = bulletRect->right + distance;     //�Ѿ˳���ġ����.. ��Ÿ� distance
        break;

    case CHARACTER::AI:
        rect = shareData->GetAIRect();
        this->bullet->direction = -1;
        bulletRect->left = rect.left - bulletSize;
        bulletRect->right = bulletRect->left + bulletSize;
        bulletRect->top = (rect.top + rect.bottom) / 2 - (bulletSize / 2);
        bulletRect->bottom = bulletRect->top + bulletSize;
        bullet->startLocation = bulletRect->left;             //�Ѿ˽�����ġ����
        bullet->endLocation = bulletRect->left - distance;    //�Ѿ˳���ġ����.. ��Ÿ� distance
        break;

    default:
        rect = shareData->GetPlayerRect();
        this->bullet->direction = 0;
    }

    bullet->bulletRect = bulletRect;                //ũ�������� �Ѿ� ����ü�� �ְ�
}

void Bullet::Move()
{
    double dBulletSpeed = this->MoveSpeedCalculation();

    bullet->bulletRect->left += dBulletSpeed * bullet->direction;
    bullet->bulletRect->right += dBulletSpeed * bullet->direction;
    bullet->startLocation += dBulletSpeed * bullet->direction;
}

void Bullet::Render()
{
    this->mdc = shareData->GetMemoryDC();
    Rectangle(mdc, static_cast<int>(bullet->bulletRect->left), static_cast<int>(bullet->bulletRect->top), static_cast<int>(bullet->bulletRect->right), static_cast<int>(bullet->bulletRect->bottom));
    shareData->SetMemoryDC(mdc);
}

bool Bullet::IsDistanceLimited()
{
    switch (bullet->direction)
    {
    case CHARACTERDIRECTION::RIGTH:
        if (bullet->startLocation >= bullet->endLocation)
            return true;
        break;
    case CHARACTERDIRECTION::LEFT:
        if (bullet->startLocation <= bullet->endLocation)
            return true;
        break;
    }
    return false;
}

bool Bullet::IsCrash()
{
    dRECT characterRect;

    switch (bullet->isCharacter)
    {
    case CHARACTER::PLAYER:
        characterRect = shareData->GetAIRect();
        break;

    case CHARACTER::AI:
        characterRect = shareData->GetPlayerRect();
        break;

    default:
        return false;
    }

    //�Ѿ˰� ĳ������ �浹ó��
    if ((characterRect.bottom >= this->bullet->bulletRect->top) 
        && (characterRect.right >= this->bullet->bulletRect->left)
        && (characterRect.top <= this->bullet->bulletRect->bottom)
        && (characterRect.left <= this->bullet->bulletRect->right)
        )
        return true;
        
    return false;
}

void Bullet::ReleaseBullet()
{
    delete this->bullet->bulletRect;    //�Ѿ˸�����
    delete this->bullet;                //�Ѿ˻���
}
