#pragma once
#include "ShareData.h"

typedef struct
{
	double startLocation;
	double endLocation;
	pDRECT bulletRect;
}BulletStructure, *pBulletStructure;

class Bullet : public Object
{
private:
	ShareData* shareData = ShareData::GetInstance();
	pBulletStructure bullet;
	pDRECT bulletRect;

public:
	Bullet(HWND hWnd, RECT characterRect, unsigned int speed, double distance);
	virtual void Move();
	virtual void Render();
	bool IsRemove();
	void ReleaseBullet();


};

