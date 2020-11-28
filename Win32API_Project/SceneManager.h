#pragma once
#include "game.h"
#include "Scene.h"

class SceneManager
{
private:
	static SceneManager* sceneManager;
	SceneManager();
	~SceneManager();

public:
	static SceneManager* GetInst();
	static void ReleaseInst();

private:
	class Scene* scene;
	class Scene* nextScene;

public:
	template <typename T>		//Scene�� ������ ������ ���ø�
	T* CreateScene(SCENE sc);	//����Scene���� ����Scene���� ����
	bool Init();				//��ó��������

public:
	virtual void Input(float deltaTime);		//�Է¹ޱ�
	virtual void Update(float deltaTime);		//�����Ͱ���
	virtual void LateUpdate(float deltaTime);	//���������Ͱ���
	virtual void Collision(float deltaTime);	//���ŵȵ����ͷ� �浹ó��
	virtual void Render(HDC hdc, float deltaTime);		//�׸��׸���
};

