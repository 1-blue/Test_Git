#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

//��ü��ġ��ǥ����ü.. �� �ڼ��ϰ�ǥ���ϱ����� double������
typedef struct
{
	double left, top, right, bottom;
}dRECT, *pDRECT;

//�ӵ�������
typedef struct
{
	LARGE_INTEGER allTime;		//�������ӽð�
	LARGE_INTEGER currentTime;  //����������
	unsigned int speed;			//�̵��ӵ�
	double DeltaTime;			//�����Ӱ�������
	double timeScale;			//1�ʿ� �̵��ӵ� 300.. �����ϸ� 3�ʿ� 300 �̷�������
	double PreviousTimeScale;	//������ �̵��ӵ������صѺ���
	double speedIncrease;		//�ӵ������� %��
	double miniumSpeed;			//�����̵��ӵ�
	double maximumSpeed;		//�ְ��̵��ӵ�
	bool isStop;
}SpeedStructure, *pSpeedStructure;

class Object
{
protected:		// get | set timeScale|speedIncrease�ʿ��ϸ� �����
	HWND hWnd{ NULL };
	HDC hdc{ NULL };
	HDC mdc{ NULL };
	BITMAP bmp{ '\0' };		//����ü�� �����ʱ�ȭ�ϳ�..? �̰Ÿ´���?
	HBITMAP hbmp{ NULL };
	RECT clientRect{ 0, 0, 0, 0 };
	dRECT objectRect{ 0, 0, 0, 0 };

	//�ӵ�������
	SpeedStructure speedValue;

public:
	Object(HWND hWnd, RECT characterRect, unsigned int speed);
	double SpeedCalculation();		//�̼Ӱ��
	virtual void Move() = 0;		//�̼��� �̿��ؼ� ��ǥ����
	virtual void Render() = 0;		//ȭ�� ����
	void Pause();
	bool IsPause();
	void PauseRelease();

	virtual ~Object();
};

