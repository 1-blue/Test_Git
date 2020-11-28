#include "Ref.h"

Ref::Ref() : refCount(1)
{
}

void Ref::AddRef()
{
	refCount++;
}

int Ref::Release()
{
	refCount--;
	if (0 == refCount)
	{
		delete this;
		return 0;
	}
	return refCount;
}
