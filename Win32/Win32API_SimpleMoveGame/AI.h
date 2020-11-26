#pragma once
#include "ShareData.h"

class AI : public Object
{
private:
	ShareData* shareData = ShareData::GetInstance();
	int direction{ 1 };
	double shotInterval = 0.0;		//�Ѿ� �߻簣��
	double shotValue = 0.0;			//�ð��� �°� �Ѿ˹߻翩���Ǵ������Ѻ���
	//�ð��������� �߻��ϴµ� �ð����� �������Ѽ� shotInterval���� �ѹ��� �߻��ϵ��� ����

	//�Ѿ��̵��ӵ�
	SpeedStructure bulletSpeedValue;

public:
	AI(HWND hWnd, RECT characterRect, unsigned int speed, double shotInterval);
	double ShotSpeedCalculation();
	virtual void Move();
	bool IsShot();
	virtual void Render();


};

