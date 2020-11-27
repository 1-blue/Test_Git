#include "SceneManager.h"
#include "InGameScene.h"   //���漱��.. Scene�� ����� ����ϱ����ؼ�

SceneManager* SceneManager::sceneManager = NULL;

SceneManager::SceneManager(): scene(NULL), nextScene(NULL)
{

}

SceneManager::~SceneManager()
{
    delete scene;
}

SceneManager* SceneManager::GetInst()
{
    if (NULL == sceneManager)
        sceneManager = new SceneManager();

    return sceneManager;
}

void SceneManager::ReleaseInst()
{
    delete sceneManager;
    sceneManager = NULL;
}

template<typename T>
inline T* SceneManager::CreateScene(SCENE sc)
{
    T* tempScene = new T();

    if (!tempScene->Init())
    {
        delete tempScene;
        return NULL;
    }

    switch (sc)
    {
    case SCENE::SC_CURRENT:
        delete scene;
        scene = tempScene;
        break;
    case SCENE::SC_NEXT:
        delete nextScene;
        nextScene = tempScene;
        break;
    }

    return tempScene;
}

bool SceneManager::Init()
{
    CreateScene<InGameScene>(SCENE::SC_CURRENT);

    return true;
}
