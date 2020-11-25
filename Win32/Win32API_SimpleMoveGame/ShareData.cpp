#include "ShareData.h"

ShareData* ShareData::shareData = NULL;

ShareData* ShareData::GetInstance()
{
	if (NULL == shareData)
		shareData = new ShareData();
	return shareData;
}

void ShareData::ReleaseInstance()
{
	delete shareData;
	shareData = NULL;
}

const dRECT& ShareData::GetLocation() const
{
	return rect;
}

void ShareData::SetLocation(dRECT& dRect)
{
	this->rect = dRect;
}

HDC ShareData::GetMemoryDC()
{
	return this->mdc;
}

void ShareData::SetMemoryDC(HDC mdc)
{
	this->mdc = mdc;
}

void ShareData::SetHBitMap(HBITMAP hbmp)
{
	this->hbmp = hbmp;
}

HBITMAP ShareData::GetHBitMap()
{
	return this->hbmp;
}
