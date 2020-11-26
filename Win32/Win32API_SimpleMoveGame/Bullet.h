#pragma once
#include "ShareData.h"

typedef struct
{
	double startLocation;
	double endLocation;
	pDRECT bulletRect;
	int isCharacter;
	int direction;
}BulletStructure, *pBulletStructure;

class Bullet : public Object
{
private:
	ShareData* shareData = ShareData::GetInstance();
	pBulletStructure bullet;
	pDRECT bulletRect;


public:
	Bullet(HWND hWnd, RECT characterRect, int isCharacter, unsigned int speed, double distance);
	virtual void Move();
	virtual void Render();
	bool IsDistanceLimited();
	bool IsCrash();
	void ReleaseBullet();

};

