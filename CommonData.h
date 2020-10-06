#pragma once

class CommonData {
private:
	static constexpr int mapSizeX = 31;
	static constexpr int mapSizeY = 21;
	int currentScore = 0;
	int board[mapSizeY][mapSizeX] = { 0 };
	int life; 

public:
	int GetMapSizeX();
	int GetMapSizeY();
	int GetCurrentScore();
	void SetCurrentScore(int score);
	void SetBoard(int x, int y, int character);
	int GetBoard(int x, int y);
	int GetLife();
	void SetLife(int life);

};	

enum BoardInfo {	//55마리
	BLANK,
	WALL,
	PLAYER,
	BULLET,
	SHIELD,
	HIT,
	OCTOPUS = 10,
	CRAB = 20,
	SQUID = 30,
	UFO
};