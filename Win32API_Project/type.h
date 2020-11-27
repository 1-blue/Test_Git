#pragma once

//윈도우 크기
typedef struct {
	unsigned int width;
	unsigned int height;
}WINDOWSIZE;

//타이머관련
typedef struct
{
	LARGE_INTEGER allTime;		//총프레임시간
	LARGE_INTEGER currentTime;  //현재프레임
	unsigned int speed;			//이동속도
	float deltaTime;			//프레임간의차이
	float fps;
	float fpsTime;
	int frameMax;
	int frame;
}TimerData, *pTimerData;

