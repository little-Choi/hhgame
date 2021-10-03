#include "GameCategory.h"
#include "ArrowGame.h"
#include "DinosaurGame.h"
#include "TetrisGame.h"

void GameCategory::gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void GameCategory::DrawGameCategory()
{
	system("cls");
	gotoxy(0, 0);
	cout << "Game Menu";

	for (int i = 0; i <= GAME_COUNT; i++)
	{
		gotoxy(1, i + 1);
		cout << i + 1 << ". " << GameVec[i];
	}
}

void GameCategory::DrawGameCategoryCursor(int& y)
{
	if (y <= 1)
	{
		y = 1;
	}
	else if (y > GAME_COUNT)
	{
		y = GAME_COUNT + 1;
	}
	gotoxy(0, y);
	cout << ">";
}

int GameCategory::SelectGame()
{
	int input = 0;
	int y = 1;
	while (true)
	{
		DrawGameCategory();
		DrawGameCategoryCursor(y);
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
			return y;
		else if (input == ESC)
			return QUIT;
	}
}

void GameCategory::SetConsoleView()
{
	system("cls");
	system("mode con:cols=150 lines=50");
	system("title HH Games!");
	return;
}

void GameCategory::DrawReadyGame(int GameNum)
{
	system("cls");
	gotoxy(5, 2);
	cout << "*****************************";
	gotoxy(5, 3);
	cout << GameVec[GameNum-1];
	gotoxy(5, 4);
	cout << "*****************************";
	gotoxy(5, 8);
	cout << "GameStart";
	gotoxy(5, 9);
	cout << "Quit" << endl;

}

void GameCategory::DrawIngameCursor(int& y)
{
	if (y <= 0)
		y = 0;
	else if (y >= 1)
		y = 1;
	gotoxy(4, 8 + y);
	cout << ">";
}

MENU GameCategory::ReadyGame(int GameNum)
{
	int input = 0;
	int y = 0;
	while (true)
	{
		DrawReadyGame(GameNum);
		DrawIngameCursor(y);
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


int main(void)
{
	GameCategory GameCate;
	ArrowGame GameArrow;
	DinosaurGame GameDino;
	TetrisGame GameTetris;
	

	GameCate.SetConsoleView();
	while (true)
	{
		switch (GameCate.SelectGame())
		{
		case ARROW_GAME:
			GameArrow.GoArrowGame(ARROW_GAME);
			break;
		case DINO_GAME:
			GameDino.GoDinoGame(DINO_GAME);
			break;
		case TETRIS_GAME:
			GameTetris.GoTetrisGame(TETRIS_GAME);
			break;
		case QUIT:
			return 0;
		}
	}
	return 0;
}