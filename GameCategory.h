#ifndef GAMECATEGORY_H
#define GAMECATEGORY_H
#include <Windows.h>
#include <iostream>
#include <vector>
#include <conio.h>
#include <time.h>

using namespace std;

#define GAME_COUNT 3

#define MAGIC_KEY 224
#define ESC 27
#define SPACE 32
#define KEY_NUM 4
#define START_LIFE 3
#define MAX_LEVEL 11
#define CLOCK_PER_SECOND ((clock_t)1000)

enum GAME_MENU
{
	ARROW_GAME = 1,
	DINO_GAME,
	TETRIS_GAME,
	QUIT
};

enum KEYBOARD
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80
};

enum MENU
{
	START_GAME = 0,
	QUIT_GAME = 1
};

class GameCategory
{
public :
	vector<string> GameVec = { "화살표 맞추기 게임","공룡 게임","테트리스","프로그램 종료" };

	void gotoxy(int x, int y);
	void DrawGameCategory();
	void DrawGameCategoryCursor(int& y);
	int SelectGame();
	void SetConsoleView();
	void DrawReadyGame(int GameNum);
	void DrawIngameCursor(int& y);
	MENU ReadyGame(int GameNum);
};


#endif /*GAMECATEGORY_H*/