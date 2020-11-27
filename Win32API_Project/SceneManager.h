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


};

