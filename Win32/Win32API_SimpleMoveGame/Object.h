#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

//물체위치좌표구조체.. 더 자세하게표현하기위해 double형으로
typedef struct
{
	double left, top, right, bottom;
}dRECT, *pDRECT;

//속도계산관련
typedef struct
{
	LARGE_INTEGER allTime;		//총프레임시간
	LARGE_INTEGER currentTime;  //현재프레임
	unsigned int speed;			//이동속도
	double DeltaTime;			//프레임간의차이
	double timeScale;			//1초에 이동속도 300.. 증가하면 3초에 300 이런식으로
	double PreviousTimeScale;	//정지시 이동속도저장해둘변수
	double speedIncrease;		//속도증가량 %로
	double miniumSpeed;			//최저이동속도
	double maximumSpeed;		//최고이동속도
	bool isStop;
}SpeedStructure, *pSpeedStructure;

class Object
{
protected:		// get | set timeScale|speedIncrease필요하면 만들기
	HWND hWnd{ NULL };
	HDC hdc{ NULL };
	HDC mdc{ NULL };
	BITMAP bmp{ '\0' };		//구조체는 뭘로초기화하나..? 이거맞는지?
	HBITMAP hbmp{ NULL };
	RECT clientRect{ 0, 0, 0, 0 };
	dRECT objectRect{ 0, 0, 0, 0 };

	//속도계산관련
	SpeedStructure speedValue;

public:
	Object(HWND hWnd, RECT characterRect, unsigned int speed);
	double SpeedCalculation();		//이속계산
	virtual void Move() = 0;		//이속을 이용해서 좌표수정
	virtual void Render() = 0;		//화면 갱신
	void Pause();
	bool IsPause();
	void PauseRelease();

	virtual ~Object();
};

