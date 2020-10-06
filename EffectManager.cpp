#include "EffectManager.h"

EffectManager::EffectManager(CommonData* commonData)
{
	this->commonData = commonData;
}

void EffectManager::Init()
{
	delayManager.clear();
	hitPosList.clear();

	deleteIndex = 0;
	deleteCount = 0;
	isDelete = false;
}

void EffectManager::PrintHitEffect(Pos pos)
{
	soundManager.PlayEffectSound();
	delayManager.emplace_back(new DelayManager());

	hitPosList.emplace_back(pos); 

	commonData->SetBoard(pos.GetX(), pos.GetY(), HIT);
}

void EffectManager::DeleteHitEffect()
{
	deleteIndex = 0;
	deleteCount = 0;
	isDelete = false;

	for (auto i = delayManager.begin(); i != delayManager.end(); i++)
	{
		if ( (*i)->CkEndDelay() ) {
			delete(*i);
			delayManager.erase(i);
			isDelete = true;
			break;
		}
		else
			deleteIndex++;
	}

	if (isDelete == false)
		return;

	for (auto i = hitPosList.begin(); i != hitPosList.end(); i++){
		if (deleteCount == deleteIndex) {
			switch (commonData->GetBoard((*i).GetX(), (*i).GetY())) {
			case HIT:
				commonData->SetBoard((*i).GetX(), (*i).GetY(), BLANK);
				hitPosList.erase(i);
				break;
			default:
				hitPosList.erase(i);
				break;
			}
			break;
		}
		else
			deleteCount++;	
	}
}