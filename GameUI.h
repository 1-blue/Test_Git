#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <codecvt>
#include <io.h>
#include <fcntl.h>
#include "CommonData.h"
#include "GameManager.h"

using namespace std;

class GameUI
{
	CommonData* commonData;
	GameManager* gameManager;
	wifstream wfcin;
	wstring decoration[5];
	int index;

public:
	GameUI(CommonData* commonData);
	void show();
};