#pragma once
#include <ctime>

using namespace std;

class DelayManager
{
private:
	clock_t startTime;
	int delayTime;
public:
	DelayManager();

	void SetDelayTime(int time);
	int GetDelayTime();

	void SetStartTime();

	bool CkEndDelay();

};

