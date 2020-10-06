#pragma once
#include "CommonData.h"
#include "SoundManager.h"
#include "Pos.h"
#include "DelayManager.h"
#include <list>
#include <ctime>

class EffectManager
{
private:
	list<DelayManager *> delayManager;
	list<Pos> hitPosList;

	CommonData* commonData;
	SoundManager soundManager;

	int deleteIndex = 0;
	int deleteCount = 0;

	bool isDelete = false;
public:
	EffectManager(CommonData * commonData);
	void Init();

	void PrintHitEffect(Pos pos);

	void DeleteHitEffect();
};

