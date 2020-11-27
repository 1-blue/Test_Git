#pragma once
#include "game.h"

class Scene
{
	friend class SceneManager;	//매니저를 통해서만 생성할 수 있게
protected:
	Scene();
	virtual ~Scene() = 0;

public:
	virtual bool Init();
};

