#pragma once
#include "game.h"

class Scene
{
	friend class SceneManager;	//매니저를 통해서만 생성할 수 있게
protected:
	Scene();
	virtual ~Scene() = 0;

protected:
	list<class Layer*> layerList;

public:
	virtual bool Init();
	class Layer* CreateLayer(const string& tag, int order);

public:	//레이어 정렬을 위한 함수
	static bool LayerSort(class Layer* layer1, class Layer* layer2);

public:
	virtual void Input(float deltaTime);		//입력받기
	virtual void Update(float deltaTime);		//데이터갱신
	virtual void LateUpdate(float deltaTime);	//늦은데이터갱신
	virtual void Collision(float deltaTime);	//갱신된데이터로 충돌처리
	virtual void Render(HDC hdc, float deltaTime);		//그림그리기


};

