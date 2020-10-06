#include "DelayManager.h"

DelayManager::DelayManager()
{
	startTime = clock();
	delayTime = 1000;
}

void DelayManager::SetDelayTime(int time)
{
	delayTime = time;
}

int DelayManager::GetDelayTime()
{
	return delayTime;
}

void DelayManager::SetStartTime()
{
	startTime = clock();
}

bool DelayManager::CkEndDelay()
{	
	if (((clock() - startTime) > delayTime)) {
		startTime = clock();

		return true;
	}

	return false;
}
