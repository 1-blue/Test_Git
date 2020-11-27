#pragma once
#include "game.h"

class Scene
{
	friend class SceneManager;	//�Ŵ����� ���ؼ��� ������ �� �ְ�
protected:
	Scene();
	virtual ~Scene() = 0;

public:
	virtual bool Init();
};

