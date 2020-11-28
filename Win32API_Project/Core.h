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
	HDC hdc{ NULL };
	WINDOWSIZE ws{1200, 1080};

private:
	ATOM MyRegisterClass();		//기본윈도우생성
	bool Create();				//
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

public:
	int Run();
	BOOL Init(HINSTANCE hInstance);

public:
	void Logic();						//하나의 반복
	void Input(float deltaTime);		//입력받기
	void Update(float deltaTime);		//데이터갱신
	void LateUpdate(float deltaTime);	//늦은데이터갱신
	void Collision(float deltaTime);	//갱신된데이터로 충돌처리
	void Render(float deltaTime);		//그림그리기

};

