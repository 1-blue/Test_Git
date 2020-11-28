#include "Scene.h"
#include "Layer.h"	//전방선언

Scene::Scene()
{
	//디폴트레이어 생성
	Layer* layer = CreateLayer("Default", 0);
	layer = CreateLayer("UI", INT_MAX);

}

Scene::~Scene()
{
	for (auto layer : layerList)
		delete layer;

	layerList.clear();
}

bool Scene::Init()
{
	return true;
}

Layer* Scene::CreateLayer(const string& tag, int order)
{
	Layer* tempLayer = new Layer();

	tempLayer->SetTag(tag);		//이름설정
	tempLayer->SetOrder(order);	//순서설정
	tempLayer->SetScene(this);	//scene설정.. 레이어를 가지고있는 scene을 설정

	layerList.emplace_back(tempLayer);

	if (layerList.size() >= 2)			//레이어가 두개이상이면 정렬
		layerList.sort(Scene::LayerSort);	//레이어 정렬기준을 지정한 함수포인터를 인수로줌

	return nullptr;
}

bool Scene::LayerSort(Layer* layer1, Layer* layer2)
{
	return layer1->GetOrder() < layer2->GetOrder();
}

void Scene::Input(float deltaTime)
{
	for (auto layer : layerList)
	{
		layer->Input(deltaTime);
	}
}

void Scene::Update(float deltaTime)
{
	for (auto layer : layerList)
	{
		layer->Update(deltaTime);
	}
}

void Scene::LateUpdate(float deltaTime)
{
	for (auto layer : layerList)
	{
		layer->LateUpdate(deltaTime);
	}
}

void Scene::Collision(float deltaTime)
{
	for (auto layer : layerList)
	{
		layer->Collision(deltaTime);
	}
}

void Scene::Render(HDC hdc, float deltaTime)
{
	for (auto layer : layerList)
	{
		layer->Render(hdc, deltaTime);
	}
}

