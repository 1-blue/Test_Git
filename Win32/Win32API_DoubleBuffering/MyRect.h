#pragma once
#include "MyShape.h"

class MyRect : public MyShape
{
private:

public:
	MyRect(HWND hWnd, unsigned short timerId, unsigned short interval, const RECT& rect, const RECT& clientRect);
	void Initialize();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();
	virtual void MyBitBlt();
};

