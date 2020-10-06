#pragma once
#include <Windows.h>
#include <random>
#include "CommonData.h"
#include "DelayManager.h"
#include "Pos.h"

class Bullet{
private:
	CommonData* commonData;
	DelayManager moveDelay;
	Pos pos;

	int dir;								//총알방향
	bool isSurv = true;			//총알생존여부
	int isCrash;						//충돌한놈을 반환

public:
	Bullet(int x, int y, bool isPlayer, CommonData* commonData);	//x,y좌표설정 및 3번째 매개변수 값으로 dir 결정
	int GetXPos();
	int GetYPos();
	void SetSurv(bool surv);
	bool GetSurv();
	int Move(); //벽 접촉 시 0리턴 아니면 1리턴
	int IsHit();
};

