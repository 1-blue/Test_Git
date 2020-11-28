#pragma once
#include "game.h"

//레퍼런스카운트
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

