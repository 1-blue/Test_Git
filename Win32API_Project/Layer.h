#pragma once
#include "game.h"

class Layer
{
	friend class Scene;
private:
	Layer();	//Scene()에서만 생성
	~Layer();

private:
	class Scene* scene;		//자기자신을 가진scene정보를 가질변수
	string tag;
	int order;				//레이어 출력순서
	list<class Object*> objectList;

public:
	void SetTag(const string& tag);
	void SetOrder(int order);
	int GetOrder() const;
	void SetScene(class Scene* scene);
	class Scene* GetScene() const;

public:
	void Input(float deltaTime);		//입력받기
	void Update(float deltaTime);		//데이터갱신
	void LateUpdate(float deltaTime);	//늦은데이터갱신
	void Collision(float deltaTime);	//갱신된데이터로 충돌처리
	void Render(HDC hdc, float deltaTime);		//그림그리기

};

