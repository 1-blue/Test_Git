#include "EnemyInfo.h"

int EnemyInfo::GetEnemyScore()
{
	return enemyScore;
}

void EnemyInfo::SetEnemyScore(int score)
{
	enemyScore = score;
}

bool EnemyInfo::GetIsSurv()
{
	return isSurv;
}

void EnemyInfo::SetIsSurv(bool surv)
{
	isSurv = surv;
}

int EnemyInfo::GetXPos()
{
	return pos.GetX();
}

void EnemyInfo::SetXPos(int x)
{
	pos.SetX(x);
}

int EnemyInfo::GetYPos()
{
	return pos.GetY();
}

void EnemyInfo::SetYPos(int y)
{
	pos.SetY(y);
}
