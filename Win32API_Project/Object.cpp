#include "Object.h"

Object::Object() : refCount(1)
{
}

void Object::AddRef()
{
	refCount++;
}

int Object::Release()
{
	refCount--;
	if (refCount == 0)
	{
		delete this;		//자기자신삭제
		return 0;
	}

	return refCount;
}

void Object::SetTag(const string& tag)
{
	this->tag = tag;
}

void Object::SetPos(const POSITION& pos)
{
	position = pos;
}

void Object::SetPos(const POINT& pos)
{
	position = pos;
}

void Object::SetPos(float f1, float f2)
{
	position.x = f1;
	position.y = f2;
}

void Object::SetSize(const _SIZE& pos)
{
	size = pos;
}

void Object::SetSize(const POINT& pos)
{
	size = pos;
}

void Object::SetSize(float f1, float f2)
{
	size.x = f1;
	size.y = f2;
}

string Object::GetTag() const
{
	return this->tag;
}

POSITION Object::GetPos() const
{
	return this->position;
}

_SIZE Object::GetSize() const
{
	return this->size;
}

bool Object::Init()
{
	return false;
}

void Object::Input(float deltaTime)
{
}

void Object::Update(float deltaTime)
{
}

void Object::LateUpdate(float deltaTime)
{
}

void Object::Collision(float deltaTime)
{
}

void Object::Render(HDC hdc, float deltaTime)
{
}
