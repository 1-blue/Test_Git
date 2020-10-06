#include "CommonData.h"

int CommonData::GetMapSizeX()
{
	return mapSizeX;
}

int CommonData::GetMapSizeY()
{
	return mapSizeY;
}

int CommonData::GetCurrentScore()
{
	return currentScore;
}

void CommonData::SetCurrentScore(int score)
{
	currentScore = score;
}

void CommonData::SetBoard(int x, int y, int character)
{
	if (x <= 30 && x >= 0 && y >= 0 && y <= 20)
		board[y][x] = character;
}

int CommonData::GetBoard(int x, int y)
{
	if (x <= 30 && x >= 0 && y >= 0 && y <= 20)
		return board[y][x];
	return -1;		//x나 y가 잘못된값이라는 의미로 -1반환
}

int CommonData::GetLife()
{
	return life;
}

void CommonData::SetLife(int life) 
{
	this->life = life;
}

