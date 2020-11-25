#pragma once
#include "ShareData.h"

namespace PlayerDiraction
{
	enum dir
	{
		LEFT,
		TOP,
		RIGTH,
		BOTTOM
	};
}

class Player : public Object
{
private:
	ShareData* shareData = ShareData::GetInstance();
	int dir = PlayerDiraction::dir::RIGTH;

public:
	Player(HWND hWnd, RECT characterRect, unsigned int speed);
	virtual void Move();
	virtual void Render();

	int GetDiraction();		//�÷��̾����.. �ʿ��ϸ���

	virtual ~Player() {};
};
