#include "MyCircle.h"

MyCircle::MyCircle(HWND hWnd, unsigned short timerId, unsigned short interval, const RECT& rect, const RECT& clientRect)
	: MyShape(hWnd, timerId, interval, rect, clientRect)
{

}

void MyCircle::Initialize()
{
	SetStartTime(GetTickCount64());
}

void MyCircle::Update()
{
	RECT& rect = this->GetRect();
	const RECT& clientRect = this->GetClientRect();

	rect.left += 10;
	rect.right += 10;

	if (clientRect.right <= rect.right)
	{
		rect.left = 0;
		rect.right = 100;
	}

	if (GetAsyncKeyState(VK_UP))
	{
		rect.top--;
		rect.bottom--;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		rect.top++;
		rect.bottom++;
	}
}

void MyCircle::Render()
{
	HWND hWnd = this->GetMyWinodwHendle();
	RECT& rect = this->GetRect();
	const RECT& clientRect = this->GetClientRect();
	HDC hdc = this->GetMainDC();
	HDC mdc = this->GetMemoryDC();
	HBITMAP hbmp = this->GetHBitmap();

	SelectObject(mdc, hbmp);
	//이거 첫시도때만 실행해야하는데...
	//FillRect(mdc, &clientRect, (HBRUSH)GetStockObject(WHITE_BRUSH)); //도화지 색 변경
	Ellipse(mdc, rect.left, rect.top, rect.right, rect.bottom);
}

void MyCircle::Destroy()
{
	DeleteDC(this->GetMemoryDC());
	ReleaseDC(this->GetMyWinodwHendle(), this->GetMainDC());
	DeleteObject(this->GetHBitmap());
}

void MyCircle::MyBitBlt()
{
	const RECT& clientRect = this->GetClientRect();
	HDC hdc = this->GetMainDC();
	HDC mdc = this->GetMemoryDC();

	BitBlt(hdc, 0, 0, clientRect.right, clientRect.bottom, mdc, 0, 0, SRCCOPY);
	DeleteObject(hbmp);
	hbmp = CreateCompatibleBitmap(mdc, clientRect.right, clientRect.bottom);
}