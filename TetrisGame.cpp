#include "GameCategory.h"
#include "TetrisGame.h"

void TetrisGame::GoTetrisGame(int GameNum)
{
	system("title  Å×Æ®¸®½º °ÔÀÓ");
	//GameCate.SetConsoleView();

	while (true)
	{
		switch (ReadyTetrisGame(GameNum))
		{
		case START_GAME:
			StartTetrisGame();
			break;
		case QUIT_GAME:
			return;
		}
	}
	return;
}
MENU TetrisGame::ReadyTetrisGame(int GameNum)
{
	int input = 0;
	int y = 0;
	while (true)
	{
		DrawTetrisGameReady();
		GameCate.DrawIngameCursor(y);
		input = _getch();
		if (input == MAGIC_KEY)
		{
			switch (_getch())
			{
			case UP:
				--y;
				break;
			case DOWN:
				++y;
				break;
			}
		}
		else if (input == SPACE)
		{
			switch (y)
			{
			case 0:
				return START_GAME;
			case 1:
				return QUIT_GAME;
			}
		}
		else if (input == ESC)
		{
			return QUIT_GAME;
		}
	}
}

void TetrisGame::DrawTetrisGameReady()
{
	system("cls");
	GameCate.gotoxy(0, 0);
	cout << "\t"; cout << "@@@@@@@@@@@@  @@@@@@@@@   @@@@@@@@@@@  @@@@@@@@   @   @@@@@@@@@@@\n";
	cout << "\t"; cout << "      @       @                @       @      @   @   @          \n";
	cout << "\t"; cout << "      @       @                @       @      @   @   @          \n";
	cout << "\t"; cout << "      @       @@@@@@@@@        @       @     @    @   @@@@@@@@@@@\n";
	cout << "\t"; cout << "      @       @                @       @ @ @      @             @\n";
	cout << "\t"; cout << "      @       @                @       @     @    @             @\n";
	cout << "\t"; cout << "      @       @@@@@@@@@        @       @      @   @   @@@@@@@@@@@\n";

	GameCate.gotoxy(5, 8);
	cout << "GameStart";
	GameCate.gotoxy(5, 9);
	cout << "Quit" << endl;

}

void TetrisGame::DrawTetrisIngameCursor(int& y)
{
	if (y <= 0)
		y = 0;
	else if (y >= 1)
		y = 1;
	GameCate.gotoxy(4, 8 + y);
	cout << ">";
}

void TetrisGame::DrawTetrisGame()
{
	system("cls");
	vector<vector<int> > table;
	for (int i = 0; i < SizeY; i++) {
		vector<int> temp;
		for (int j = 0; j < SizeX; j++) {
			temp.push_back(0);
		}
		table.push_back(temp);
	}
	//°¡Àå ÀÚ¸® »À´ë »öÄ¥
	for (int i = 0; i < SizeX; i++) {
		table[0][i] = 1;
		table[SizeY - 1][i] = 1;
	}
	for (int i = 1; i < SizeY - 1; i++) {
		table[i][0] = 1;
		table[i][SizeX - 1] = 1;
	}
	for (int i = 0; i < SizeY; i++) {
		for (int j = 0; j < SizeX; j++) {
			if (table[i][j] == 1)cout << "¢Ë";
			else cout << "  "; // µÎ Ä­ ¶ç¿ì±â
		}
		cout << "\n";
	}
}

void TetrisGame::TetrisGameOver(int score)
{
	system("cls");
	GameCate.gotoxy(5, 3);
	cout << "************************************";

	GameCate.gotoxy(9, 10);
	cout << "Your Final Score is " << score;
	GameCate.gotoxy(9, 12);
	cout << "Please enter Spacebar!";

	GameCate.gotoxy(5, 17);
	cout << "************************************";

	int input = 0;
	while (true)
	{
		input = _getch();
		if (input == SPACE)
		{
			return;
		}
	}

}

void TetrisGame::StartTetrisGame()
{
	DrawTetrisGame();
}

