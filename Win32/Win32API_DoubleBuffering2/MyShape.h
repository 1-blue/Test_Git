#pragma once

#include "framework.h"
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class MyShape
{
private:
	HWND hWnd;
	unsigned short timerId{ 0 };	//Ÿ�̸Ӿ��̵�
	unsigned short interval{ 0 };	//�ð�����
	RECT rect{ 0, 0, 0, 0 };		//�׷��� �簢��
	RECT clientRect{ 0, 0, 0, 0 };	//Ŭ���̾�Ʈũ��
	static HDC hdc;
	static HDC mdc;

protected:
	ULONGLONG startTime{ 0 };
	static HBITMAP hbmp;

public:

	MyShape(HWND hWnd, unsigned short timerId, unsigned short interval, const RECT& rect, const RECT& clientRect);
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Destroy() = 0;
	virtual void MyBitBlt() = 0;
	
	HDC GetMainDC() const;
	HDC GetMemoryDC() const;
	HBITMAP GetHBitmap() const;
	HWND GetMyWinodwHendle() const;
	unsigned short GetTimerId() const;
	unsigned short GetInterval() const;
	RECT& GetRect();
	const RECT& GetClientRect() const;		//���� ��ȭ��Ű�������Ŷ� const

	ULONGLONG GetStartTime() const;
	void SetStartTime(ULONGLONG startTime);

};

