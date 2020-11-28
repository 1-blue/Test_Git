#pragma once
#include "game.h"

class Layer
{
	friend class Scene;
private:
	Layer();	//Scene()������ ����
	~Layer();

private:
	class Scene* scene;		//�ڱ��ڽ��� ����scene������ ��������
	string tag;
	int order;				//���̾� ��¼���
	list<class Object*> objectList;

public:
	void SetTag(const string& tag);
	void SetOrder(int order);
	int GetOrder() const;
	void SetScene(class Scene* scene);
	class Scene* GetScene() const;

public:
	void Input(float deltaTime);		//�Է¹ޱ�
	void Update(float deltaTime);		//�����Ͱ���
	void LateUpdate(float deltaTime);	//���������Ͱ���
	void Collision(float deltaTime);	//���ŵȵ����ͷ� �浹ó��
	void Render(HDC hdc, float deltaTime);		//�׸��׸���

};

