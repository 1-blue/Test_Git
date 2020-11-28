#pragma once
#include "game.h"	//�����߰���������ϵ��� ��Ƶ���������� �����
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
	ATOM MyRegisterClass();		//�⺻���������
	bool Create();				//
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

public:
	int Run();
	BOOL Init(HINSTANCE hInstance);

public:
	void Logic();						//�ϳ��� �ݺ�
	void Input(float deltaTime);		//�Է¹ޱ�
	void Update(float deltaTime);		//�����Ͱ���
	void LateUpdate(float deltaTime);	//���������Ͱ���
	void Collision(float deltaTime);	//���ŵȵ����ͷ� �浹ó��
	void Render(float deltaTime);		//�׸��׸���

};

