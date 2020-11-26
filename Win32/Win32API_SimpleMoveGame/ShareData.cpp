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

const dRECT& ShareData::GetPlayerRect() const
{
	return playerRect;
}

void ShareData::SetPlayerRect(dRECT& playerRect)
{
	this->playerRect = playerRect;
}

const dRECT& ShareData::GetAIRect() const
{
	return this->aiRect;
}

void ShareData::SetAIRect(dRECT& aiRect)
{
	this->aiRect = aiRect;
}

HDC ShareData::GetMemoryDC() const
{
	return this->mdc;
}

void ShareData::SetMemoryDC(HDC mdc)
{
	this->mdc = mdc;
}

HBITMAP ShareData::GetHBitMap() const
{
	return this->hbmp;
}

void ShareData::SetHBitMap(HBITMAP hbmp)
{
	this->hbmp = hbmp;
}
