#pragma once
#include "game.h"

class Scene
{
	friend class SceneManager;	//�Ŵ����� ���ؼ��� ������ �� �ְ�
protected:
	Scene();
	virtual ~Scene() = 0;

protected:
	list<class Layer*> layerList;

public:
	virtual bool Init();
	class Layer* CreateLayer(const string& tag, int order);

public:	//���̾� ������ ���� �Լ�
	static bool LayerSort(class Layer* layer1, class Layer* layer2);

public:
	virtual void Input(float deltaTime);		//�Է¹ޱ�
	virtual void Update(float deltaTime);		//�����Ͱ���
	virtual void LateUpdate(float deltaTime);	//���������Ͱ���
	virtual void Collision(float deltaTime);	//���ŵȵ����ͷ� �浹ó��
	virtual void Render(HDC hdc, float deltaTime);		//�׸��׸���


};

