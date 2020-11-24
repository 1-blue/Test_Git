#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

class Player
{
private:
	HWND hWnd{ NULL };
	HDC hdc{ NULL };
	HDC mdc{ NULL };
	BITMAP bmp;
	HBITMAP hbmp{ NULL };
	RECT clientRect{ 0, 0, 0, 0 };
	RECT playerRect{ 0, 0, 0, 0 };
	ULONGLONG speed;
	int idx = -1;
	ULONGLONG startTime = 0;

public:
	Player(HWND hWnd, RECT r, ULONGLONG speed);
	void Move();
	void Jump();

};

