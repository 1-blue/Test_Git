#include "MyRect.h"

MyRect::MyRect(HWND hWnd, unsigned short timerId, unsigned short interval, const RECT& rect, const RECT& clientRect)
	: MyShape(hWnd, timerId, interval, rect, clientRect)
{

}

void MyRect::Initialize()
{
	//SetTimer(this->GetMyWinodwHendle(), this->GetTimerId(), this->GetInterval(), NULL);	//타이머설정
}

void MyRect::Update()
{
	RECT& rect = this->GetRect();
	const RECT& clientRect = this->GetClientRect();

	rect.left += 1;
	rect.right += 1;

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

void MyRect::Render()
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
	Rectangle(mdc, rect.left, rect.top, rect.right, rect.bottom);
}

void MyRect::Destroy()
{
	//KillTimer(this->GetMyWinodwHendle(), this->GetTimerId());
	DeleteDC(this->GetMemoryDC());
	ReleaseDC(this->GetMyWinodwHendle(), this->GetMainDC());
	DeleteObject(this->GetHBitmap());
}

void MyRect::MyBitBlt()
{
	const RECT& clientRect = this->GetClientRect();
	HDC hdc = this->GetMainDC();
	HDC mdc = this->GetMemoryDC();

	BitBlt(hdc, 0, 0, clientRect.right, clientRect.bottom, mdc, 0, 0, SRCCOPY);
}
