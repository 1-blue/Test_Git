#pragma once
#include "game.h"

//화면에 보이게 배치하는 관리자
//움직임이 있는것과 없는것
class Object
{
protected:
	Object();
	virtual ~Object() = 0;

protected:			//레퍼런스카운트.. 참조횟수계산.. 참조수가 0이면 삭제
	int refCount;

public:
	void AddRef();	//객체참조시 참조카운트+1
	int Release();	//참조 -1 참조0되면 삭제

protected:	//float형 x, y가지고 있고, 연산자 오버로딩해둠 (=, +, -, *, /)
	POSITION position;		//위치
	_SIZE size;				//크기
	string tag;

public:
	void SetTag(const string& tag);
	//포지션
	void SetPos(const POSITION& pos);
	void SetPos(const POINT& pos);
	void SetPos(float f1, float f2);
	//사이즈
	void SetSize(const _SIZE& pos);
	void SetSize(const POINT& pos);
	void SetSize(float f1, float f2);

	string GetTag() const;
	POSITION GetPos() const;
	_SIZE GetSize() const;

public:
	virtual bool Init();
	virtual void Input(float deltaTime);		//입력받기
	virtual void Update(float deltaTime);		//데이터갱신
	virtual void LateUpdate(float deltaTime);	//늦은데이터갱신
	virtual void Collision(float deltaTime);	//갱신된데이터로 충돌처리
	virtual void Render(HDC hdc, float deltaTime);		//그림그리기

};