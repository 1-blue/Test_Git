#include "Timer.h"

Timer* Timer::timer = NULL;

Timer::Timer()
{

}

Timer* Timer::GetInst()
{
	if (NULL == timer)
		timer = new Timer();

	return timer;
}

void Timer::ReleaseInst()
{
	delete timer;
	timer = NULL;
}

bool Timer::Init()
{
	QueryPerformanceFrequency(&timerData.allTime);    //전체 초당 프레임수
	QueryPerformanceCounter(&timerData.currentTime);  //현재 프레임수

	timerData.deltaTime = 0.f;
	timerData.fps = 0.f;
	timerData.frameMax = 60;
	timerData.frame = 0;


	return true;
}

void Timer::Update()
{
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);

	timerData.deltaTime = (time.QuadPart - timerData.currentTime.QuadPart) / static_cast<float>(timerData.allTime.QuadPart);
}

float Timer::GetDeltaTime() const
{
	return timerData.deltaTime;
}

float Timer::GetFPS() const
{
	return timerData.fps;
}
