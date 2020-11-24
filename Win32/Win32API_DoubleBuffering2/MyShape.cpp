#include "MyShape.h"

HDC MyShape::hdc = NULL;
HDC MyShape::mdc = NULL;
HBITMAP MyShape::hbmp = NULL;

MyShape::MyShape(HWND hWnd, unsigned short timerId, unsigned short interval, const RECT& rect, const RECT& clientRect)
{
	this->hWnd = hWnd;
	this->timerId = timerId;
	this->interval = interval;
	this->rect = rect;
	this->clientRect = clientRect;
	hdc = GetDC(hWnd);
	mdc = CreateCompatibleDC(hdc);
	hbmp = CreateCompatibleBitmap(mdc, clientRect.right, clientRect.bottom);
}

HDC MyShape::GetMainDC() const
{
	return this->hdc;
}

HDC MyShape::GetMemoryDC() const
{
	return this->mdc;
}

HBITMAP MyShape::GetHBitmap() const
{
	return this->hbmp;
}

HWND MyShape::GetMyWinodwHendle() const
{
	return this->hWnd;
}

unsigned short MyShape::GetTimerId() const
{
	return this->timerId;
}

unsigned short MyShape::GetInterval() const
{
	return this->interval;
}

RECT& MyShape::GetRect()
{
	return this->rect;
}

const RECT& MyShape::GetClientRect() const
{
	return this->clientRect;
}

ULONGLONG MyShape::GetStartTime() const
{
	return this->startTime;
}

void MyShape::SetStartTime(ULONGLONG startTime)
{
	this->startTime = startTime;
}
