#pragma once
#include "Scene.h"

class InGameScene : public Scene
{
	friend class SceneManager;	//�Ŵ����� ���ؼ��� ������ �� �ְ�
private:
	InGameScene();
	~InGameScene();

public:
	virtual bool Init();


};

