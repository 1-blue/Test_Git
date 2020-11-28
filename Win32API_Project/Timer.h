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

//���ֵ��� ��Ÿ�̸Ӹ� �����ؼ� �� Ÿ�̸Ӱ� ����� ����ŭ �̵�