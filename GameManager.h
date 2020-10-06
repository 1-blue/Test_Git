#pragma once
#include "CommonData.h"
#include <iostream>
#include <Windows.h>
#include <fstream>

using namespace std;

class GameManager
{
private:
	CommonData* commonData;
	wifstream wfcin;

	bool nextStage = false;
public:
	GameManager(CommonData* commonData);
	void GotoXY(int x, int y);			
	void InitBoard();						
	void Show();
	bool CheckGameOver();

};

