#pragma once

//������ ũ��
typedef struct {
	unsigned int width;
	unsigned int height;
}WINDOWSIZE;

//Ÿ�̸Ӱ���
typedef struct
{
	LARGE_INTEGER allTime;		//�������ӽð�
	LARGE_INTEGER currentTime;  //����������
	unsigned int speed;			//�̵��ӵ�
	float deltaTime;			//�����Ӱ�������
	float fps;
	float fpsTime;
	int frameMax;
	int frame;
}TimerData, *pTimerData;

