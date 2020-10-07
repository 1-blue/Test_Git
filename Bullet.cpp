#include "Bullet.h"

Bullet::Bullet(int x, int y, bool isPlayer ,CommonData * commonData)
{
	srand((unsigned)time(NULL));

	this->commonData = commonData;

	if (isPlayer)
	{
		dir = -1;
		moveDelay.SetDelayTime(40);
	}
	else
	{
		dir = 1;
		switch ( rand()%3 )
		{
		case 1: moveDelay.SetDelayTime(130);
			break;
		default: moveDelay.SetDelayTime(80);
			break;
		}
	}
		
	pos.SetX(x);
	pos.SetY(y + dir);

	isCrash = -1;

	commonData->SetBoard(pos.GetX(),pos.GetY(), BULLET);
}

int Bullet::GetXPos()
{
	return pos.GetX();
}

int Bullet::GetYPos()
{
	return pos.GetY();
}

void Bullet::SetSurv(bool surv)
{
	isSurv = surv;
}

bool Bullet::GetSurv()
{
	return isSurv;
}

int Bullet::Move()
{
	isCrash = IsHit();
	if (isCrash != BLANK && isCrash != BULLET)		//공백이나 자기자신아니면 충돌한놈 반환
		return isCrash;

	if (!isSurv)		//적과플레이어충돌검사확인했을때 blank이면 전부 변화없어서 리턴값으로사용해봄
		return BLANK;

	if (moveDelay.CkEndDelay()) {
		commonData->SetBoard(pos.GetX(), pos.GetY(), BLANK);
		pos.SetY(pos.GetY() + dir);

		//총알이 움직이고나서 적이나 캐릭터 충돌여부 반환
		isCrash = IsHit();
		if (isCrash != BLANK && isCrash != BULLET)
			return isCrash;

		commonData->SetBoard(pos.GetX(), pos.GetY(), BULLET);
	}

	//아무것도 충돌안했으면 BLANK반환
	return BLANK;
}

int Bullet::IsHit()
{
	if (HIT == commonData->GetBoard(pos.GetX(), pos.GetY()))
		return BLANK;
	else
		return commonData->GetBoard(pos.GetX(), pos.GetY());
}
