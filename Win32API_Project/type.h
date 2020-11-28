#pragma once

//������ ũ��
typedef struct 
{
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
	float timeScale;
	float fps;
	float fpsTime;
	int frameMax;
	int frame;
}TimerData, *pTimerData;

//ĳ������ ȭ�������ǥ�� ũ�⸦ ���� ����ü
typedef struct Posi
{
	float x, y;		//��ǥ
	//�����ڵ� ����
	Posi() : x(0.f), y(0.f) {};
	Posi(float x, float y) : x(x), y(y) {};
	Posi(const Posi& pos)
	{
		x = pos.x;
		y = pos.y;
	}
	//�����ͱ���ü �����ε�
	Posi(const POINT& point)
	{
		x = static_cast<float>(point.x);
		y = static_cast<float>(point.y);
	}
	//�����ڿ����ε�.. POINT�� �������籸��ü���� �����ڵ� �����ε�
	void operator=(const Posi& pos)
	{
		this->x = pos.x;
		this->y = pos.y;
	}
	void operator=(const POINT& pos)
	{
		this->x = static_cast<float>(pos.x);
		this->y = static_cast<float>(pos.y);
	}

	//���ϱ�
	Posi operator+(const Posi& pos)
	{
		POSITION position;
		position.x = this->x + pos.x;
		position.y = this->y + pos.y;

		return position;
	}
	Posi operator+(const POINT& pos)
	{
		POSITION position;
		position.x = this->x + static_cast<float>(pos.x);
		position.y = this->y + static_cast<float>(pos.y);

		return position;
	}
	Posi operator+(float f)
	{
		POSITION position;
		position.x = this->x + f;
		position.y = this->y + f;

		return position;
	}

	//����
	Posi operator-(const Posi& pos)
	{
		POSITION position;
		position.x = this->x - pos.x;
		position.y = this->y - pos.y;

		return position;
	}
	Posi operator-(const POINT& pos)
	{
		POSITION position;
		position.x = this->x - static_cast<float>(pos.x);
		position.y = this->y - static_cast<float>(pos.y);

		return position;
	}
	Posi operator-(float f)
	{
		POSITION position;
		position.x = this->x - f;
		position.y = this->y - f;

		return position;
	}

	//���ϱ�
	Posi operator*(const Posi& pos)
	{
		POSITION position;
		position.x = this->x * pos.x;
		position.y = this->y * pos.y;

		return position;
	}
	Posi operator*(const POINT& pos)
	{
		POSITION position;
		position.x = this->x * static_cast<float>(pos.x);
		position.y = this->y * static_cast<float>(pos.y);

		return position;
	}
	Posi operator*(float f)
	{
		POSITION position;
		position.x = this->x * f;
		position.y = this->y * f;

		return position;
	}

	//������
	Posi operator/(const Posi& pos)
	{
		POSITION position;
		position.x = this->x / pos.x;
		position.y = this->y / pos.y;

		return position;
	}
	Posi operator/(const POINT& pos)
	{
		POSITION position;
		position.x = this->x / static_cast<float>(pos.x);
		position.y = this->y / static_cast<float>(pos.y);

		return position;
	}
	Posi operator/(float f)
	{
		POSITION position;
		position.x = this->x / f;
		position.y = this->y / f;

		return position;
	}

}POSITION, *pPOSITION, _SIZE, *_pSIZE;

