#pragma once

//윈도우 크기
typedef struct 
{
	unsigned int width;
	unsigned int height;
}WINDOWSIZE;

//타이머관련
typedef struct
{
	LARGE_INTEGER allTime;		//총프레임시간
	LARGE_INTEGER currentTime;  //현재프레임
	unsigned int speed;			//이동속도
	float deltaTime;			//프레임간의차이
	float timeScale;
	float fps;
	float fpsTime;
	int frameMax;
	int frame;
}TimerData, *pTimerData;

//캐릭터의 화면출력좌표와 크기를 정할 구조체
typedef struct Posi
{
	float x, y;		//좌표
	//생성자들 지정
	Posi() : x(0.f), y(0.f) {};
	Posi(float x, float y) : x(x), y(y) {};
	Posi(const Posi& pos)
	{
		x = pos.x;
		y = pos.y;
	}
	//포인터구조체 오버로딩
	Posi(const POINT& point)
	{
		x = static_cast<float>(point.x);
		y = static_cast<float>(point.y);
	}
	//연산자오버로딩.. POINT와 내가만든구조체간의 연산자들 오버로딩
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

	//더하기
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

	//빼기
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

	//곱하기
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

	//나누기
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

