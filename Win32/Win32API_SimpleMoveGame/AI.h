#pragma once
#include "ShareData.h"

class AI : public Object
{
private:
	ShareData* shareData = ShareData::GetInstance();
	int direction{ 1 };
	double shotInterval = 0.0;		//총알 발사간격
	double shotValue = 0.0;			//시간에 맞게 총알발사여부판단을위한변수
	//시간값에따라서 발사하는데 시간값을 누적시켜서 shotInterval값에 한번씩 발사하도록 만듦

	//총알이동속도
	SpeedStructure bulletSpeedValue;

public:
	AI(HWND hWnd, RECT characterRect, unsigned int speed, double shotInterval);
	double ShotSpeedCalculation();
	virtual void Move();
	bool IsShot();
	virtual void Render();


};

