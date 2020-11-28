#include "Scene.h"
#include "Layer.h"	//���漱��

Scene::Scene()
{
	//����Ʈ���̾� ����
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

	tempLayer->SetTag(tag);		//�̸�����
	tempLayer->SetOrder(order);	//��������
	tempLayer->SetScene(this);	//scene����.. ���̾ �������ִ� scene�� ����

	layerList.emplace_back(tempLayer);

	if (layerList.size() >= 2)			//���̾ �ΰ��̻��̸� ����
		layerList.sort(Scene::LayerSort);	//���̾� ���ı����� ������ �Լ������͸� �μ�����

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

