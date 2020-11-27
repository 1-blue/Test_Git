#pragma once
#include "Scene.h"

class InGameScene : public Scene
{
	friend class SceneManager;	//매니저를 통해서만 생성할 수 있게
private:
	InGameScene();
	~InGameScene();

public:
	virtual bool Init();


};

