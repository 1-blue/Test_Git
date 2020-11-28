#include "Layer.h"
#include "Object.h"

Layer::Layer() : tag(""), order(0), scene(NULL)
{

}

Layer::~Layer()
{
	//for (auto object : objectList)
	//{
	//	while (0 == object->Release());	//refCount가 0이면 object삭제
	//}

	//objectList.clear();
}

void Layer::SetTag(const string& tag)
{
	this->tag = tag;
}

void Layer::SetOrder(int order)
{
	this->order = order;
}

int Layer::GetOrder() const
{
	return this->order;
}

void Layer::SetScene(Scene* scene)
{
	this->scene = scene;
}

Scene* Layer::GetScene() const
{
	return this->scene;
}

void Layer::Input(float deltaTime)
{
	for (auto object : objectList)
	{
		object->Input(deltaTime);
	}
}

void Layer::Update(float deltaTime)
{
	for (auto object : objectList)
	{
		object->Update(deltaTime);
	}
}

void Layer::LateUpdate(float deltaTime)
{
	for (auto object : objectList)
	{
		object->LateUpdate(deltaTime);
	}
}

void Layer::Collision(float deltaTime)
{
	for (auto object : objectList)
	{
		object->Collision(deltaTime);
	}
}

void Layer::Render(HDC hdc, float deltaTime)
{
	for (auto object : objectList)
	{
		object->Render(hdc, deltaTime);
	}

}
