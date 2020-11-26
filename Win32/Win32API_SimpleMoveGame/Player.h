#pragma once
#include "ShareData.h"

class Player : public Object
{
private:
	ShareData* shareData = ShareData::GetInstance();
	int dir = CHARACTERDIRECTION::dir::RIGTH;

public:
	Player(HWND hWnd, RECT characterRect, unsigned int speed);
	virtual void Move();
	virtual void Render();

	int GetDiraction();		//플레이어방향.. 필요하면사용
	virtual ~Player() {};
};
