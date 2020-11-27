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
	template <typename T>		//Scene의 종류를 결정할 템플릿
	T* CreateScene(SCENE sc);	//현재Scene인지 다음Scene인지 결정
	bool Init();				//맨처음장면생성


};

