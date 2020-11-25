#pragma once
#include "Object.h"

class ShareData
{
private:
	dRECT rect{ 0,0,0,0 };
	HDC mdc{ NULL };
	HBITMAP hbmp{ NULL };
	static ShareData* shareData;
	ShareData() {};

public:
	static ShareData* GetInstance();
	static void ReleaseInstance();

	const dRECT& GetLocation() const;
	void SetLocation(dRECT& dRect);

	HDC GetMemoryDC();
	void SetMemoryDC(HDC mdc);

	void SetHBitMap(HBITMAP hbmp);
	HBITMAP GetHBitMap();
};

