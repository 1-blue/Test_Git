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

public:
	virtual void Input(float deltaTime);		//입력받기
	virtual void Update(float deltaTime);		//데이터갱신
	virtual void LateUpdate(float deltaTime);	//늦은데이터갱신
	virtual void Collision(float deltaTime);	//갱신된데이터로 충돌처리
	virtual void Render(HDC hdc, float deltaTime);		//그림그리기
};

