#pragma once
#include "Pos.h"
class EnemyInfo{
private:
	int enemyScore;			//점수
	bool isSurv;		//생존유무
	Pos pos;
public:
	int GetEnemyScore();
	void SetEnemyScore(int score);

	bool GetIsSurv();
	void SetIsSurv(bool surv);

	int GetXPos();
	void SetXPos(int x);

	int GetYPos();
	void SetYPos(int y);
};

