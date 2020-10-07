#pragma once
#include "EnemyInfo.h"
#include "CommonData.h"
#include "EffectManager.h"
#include "DelayManager.h"
#include <random>

class UfoEnemy
{
private:
	EnemyInfo ufo;
	CommonData* commondata;
	EffectManager* effectManager;
	DelayManager spawnDelay;
	DelayManager moveDelay;

	Pos pos;

public:
	UfoEnemy(CommonData * data, EffectManager * effectManager);
	void Init();
	void Spawn();
	void SetRandomScore();
	void Move();
	void DisapearUFO();
	void Hit();				//피격 시 처리
};