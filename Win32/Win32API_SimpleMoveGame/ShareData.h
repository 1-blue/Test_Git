#pragma once
#include "Object.h"

class ShareData
{
private:
	dRECT playerRect{ 0,0,0,0 };
	dRECT aiRect{ 0,0,0,0 };
	HDC mdc{ NULL };
	HBITMAP hbmp{ NULL };
	static ShareData* shareData;
	ShareData() {};

public:
	static ShareData* GetInstance();
	static void ReleaseInstance();

	const dRECT& GetPlayerRect() const;
	void SetPlayerRect(dRECT& playerRect);

	const dRECT& GetAIRect() const;
	void SetAIRect(dRECT& aiRect);

	HDC GetMemoryDC() const;
	void SetMemoryDC(HDC mdc);

	HBITMAP GetHBitMap() const;
	void SetHBitMap(HBITMAP hbmp);

};

namespace CHARACTER
{
	enum
	{
		PLAYER,
		AI
	};
}

namespace CHARACTERDIRECTION
{
	enum dir
	{
		LEFT = -1,
		TOP,
		RIGTH,
		BOTTOM
	};
}