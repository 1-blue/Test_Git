#pragma once
#include "game.h"	//공통추가할헤더파일들을 모아둔헤더파일을 만들기
#include "SceneManager.h"
#include "Timer.h"

class Core
{
private:
	static Core* core;
	Core();
	~Core();

public:
	static Core* GetInst();
	static void ReleaseInst();

private:
	static bool run;

private:
	HINSTANCE hInst{ NULL };
	HWND hWnd{ NULL };
	WINDOWSIZE ws{1200, 1080};

public:
	int Run();
	void TimerUpdate();
	BOOL Init(HINSTANCE hInstance);

private:
	ATOM MyRegisterClass();		//기본윈도우생성
	bool Create();				//
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);




};

