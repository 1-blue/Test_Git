#pragma once
#include "game.h"

class Timer
{
private:
	static Timer* timer;
	Timer();
	~Timer() {};

public:
	static Timer* GetInst();
	static void ReleaseInst();

private:
	TimerData timerData;

public:
	bool Init();
	void Update();
	float GetDeltaTime() const;
	float GetFPS() const;
	float GetTimeScale() const;
	void SetTimeScale(float timeSacle);

};

//모든애들이 이타이머를 공유해서 이 타이머가 계산한 값만큼 이동