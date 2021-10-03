#include "GameCategory.h"
#include "DinosaurGame.h"

#define DINO_BOTTOM_Y 12

void DinosaurGame::GoDinoGame(int GameNum)
{

	system("title °ø·æ °ÔÀÓ");
	//GameCate.SetConsoleView();
	while (true)
	{
		switch (GameCate.ReadyGame(GameNum))
		{
		case START_GAME:
			StartDinoGame();
			break;
		case QUIT_GAME:
			return;
		}
	}
	return;
}

void DinosaurGame::StartDinoGame()
{
	while (true)
	{
		InitDinoGame();
		break;
	}
	return;
}

void DinosaurGame::InitDinoGame()
{
	int Input = 0;
	while (true)
	{
		DrawDino(DINO_BOTTOM_Y);
		Input = _getch();
		if (Input == SPACE)
		{
			while (true)
			{

			}
		}
	}
	return;
}

void DinosaurGame::DrawDino(int DinoY)
{
	GameCate.gotoxy(0, DinoY);
	printf("        $$$$$$$ \n");
	printf("       $$ $$$$$$\n");
	printf("       $$$$$$$$$\n");
	printf("$      $$$      \n");
	printf("$$     $$$$$$$  \n");
	printf("$$$   $$$$$     \n");
	printf(" $$  $$$$$$$$$$ \n");
	printf(" $$$$$$$$$$$    \n");
	printf("  $$$$$$$$$$    \n");
	printf("    $$$$$$$$    \n");
	printf("     $$$$$$     \n");
	printf("     $    $     \n");
	printf("     $$   $$      ");
}