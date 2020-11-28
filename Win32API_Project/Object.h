#pragma once
#include "game.h"

//ȭ�鿡 ���̰� ��ġ�ϴ� ������
//�������� �ִ°Ͱ� ���°�
class Object
{
protected:
	Object();
	virtual ~Object() = 0;

protected:			//���۷���ī��Ʈ.. ����Ƚ�����.. �������� 0�̸� ����
	int refCount;

public:
	void AddRef();	//��ü������ ����ī��Ʈ+1
	int Release();	//���� -1 ����0�Ǹ� ����

protected:	//float�� x, y������ �ְ�, ������ �����ε��ص� (=, +, -, *, /)
	POSITION position;		//��ġ
	_SIZE size;				//ũ��
	string tag;

public:
	void SetTag(const string& tag);
	//������
	void SetPos(const POSITION& pos);
	void SetPos(const POINT& pos);
	void SetPos(float f1, float f2);
	//������
	void SetSize(const _SIZE& pos);
	void SetSize(const POINT& pos);
	void SetSize(float f1, float f2);

	string GetTag() const;
	POSITION GetPos() const;
	_SIZE GetSize() const;

public:
	virtual bool Init();
	virtual void Input(float deltaTime);		//�Է¹ޱ�
	virtual void Update(float deltaTime);		//�����Ͱ���
	virtual void LateUpdate(float deltaTime);	//���������Ͱ���
	virtual void Collision(float deltaTime);	//���ŵȵ����ͷ� �浹ó��
	virtual void Render(HDC hdc, float deltaTime);		//�׸��׸���

};