#pragma once
#include "game.h"

//���۷���ī��Ʈ
class Ref
{
protected:
	Ref();
	virtual ~Ref() = 0;

protected:
	int refCount;

public:
	void AddRef();
	int Release();

};

