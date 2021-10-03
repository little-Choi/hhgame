#include "GameCategory.h"
#include "ArrowGame.h"


void ArrowGame::GoArrowGame(int GameNum)
{
	system("title 화살표 맞추기 게임");
	//GameCate.SetConsoleView();

	while (true)
	{
		switch (GameCate.ReadyGame(GameNum))
		{
		case START_GAME:
			StartArrowGame();
			break;
		case QUIT_GAME:
			return ;
		}
	}
	return;
}


void ArrowGame::DrawArrowGame(int life, int score, string q, string a, clock_t limit_time)
{
	system("cls");
	GameCate.gotoxy(5, 3);
	cout << "************************************";
	GameCate.gotoxy(7, 5);
	cout << "Time Limit : " << limit_time;
	GameCate.gotoxy(7, 7);
	cout << "Life : " << life;
	GameCate.gotoxy(7, 9);
	cout << "Score : " << score;

	GameCate.gotoxy(7, 12);
	cout << "Q : " << q;
	GameCate.gotoxy(7, 14);
	cout << "A : " << a;
	GameCate.gotoxy(7, 16);
	cout << "Space를 눌러야 답이 제출이 됩니다!";

	GameCate.gotoxy(5, 19);
	cout << "************************************";
}

void ArrowGame::SetQuestion(vector<int>& questionVec, int level)
{
	if (level > MAX_LEVEL)
	{
		level = MAX_LEVEL;
	}

	int num = 0;
	for (int i = 0; i < level; i++)
	{
		num = rand() % KEY_NUM;
		switch (num)
		{
		case 0:
			questionVec.push_back(UP);
			break;
		case 1:
			questionVec.push_back(DOWN);
			break;
		case 2:
			questionVec.push_back(LEFT);
			break;
		case 3:
			questionVec.push_back(RIGHT);
			break;
		}
	}
}

void ArrowGame::VectorToString(vector<int> v, string& str)
{
	for (int i = 0; i < static_cast<int>(v.size()); i++)
	{
		switch (v[i])
		{
		case UP:
			str += "↑ ";
			break;
		case DOWN:
			str += "↓ ";
			break;
		case LEFT:
			str += "← ";
			break;
		case RIGHT:
			str += "→ ";
			break;
		}
	}
}

bool ArrowGame::CheckAnswer(vector<int> q, vector<int> a)
{
	if (q.size() != a.size())
	{
		return false;
	}
	for (int i = 0; i < static_cast<int>(q.size()); i++)
	{
		if (q[i] != a[i])
		{
			return false;
		}
	}
	return true;
}

void ArrowGame::ArrowGameOver(int score)
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
void ArrowGame::StartArrowGame()
{
	int life = START_LIFE;
	int score = 0;
	int level = 1;

	vector<int> questionVec;
	string questionStr = "";
	vector<int> answerVec;
	string answerStr = "";
	clock_t start_time, end_time, limit_time = TIME_LIMIT, before_time = TIME_LIMIT + 1;

	int firstInput = 0;
	int secondInput = 0;
	while (true)
	{
		level = score / 30 + 1;
		before_time = TIME_LIMIT + 1;
		SetQuestion(questionVec, level);
		VectorToString(questionVec, questionStr);
		start_time = clock();
		while (true)
		{
			if (life == 0)
			{
				ArrowGameOver(score);
				return;
			}

			if (_kbhit())
			{
				firstInput = _getch();
				if (firstInput == MAGIC_KEY)
				{
					secondInput = _getch();
					answerVec.push_back(secondInput);
					switch (secondInput)
					{
					case UP:
						answerStr += "↑ ";
						DrawArrowGame(life, score, questionStr, answerStr, limit_time);
						break;
					case DOWN:
						answerStr += "↓ ";
						DrawArrowGame(life, score, questionStr, answerStr, limit_time);
						break;
					case LEFT:
						answerStr += "← ";
						DrawArrowGame(life, score, questionStr, answerStr, limit_time);
						break;
					case RIGHT:
						answerStr += "→ ";
						DrawArrowGame(life, score, questionStr, answerStr, limit_time);
						break;
					}
				}
				else if (firstInput == SPACE)
				{
					if (CheckAnswer(questionVec, answerVec))
					{
						score += 10;
					}
					else
					{
						--life;
						score -= 5;
					}
					questionVec.clear();
					questionStr = "";
					answerVec.clear();
					answerStr = "";
					break;
				}
				else if (firstInput == ESC)
				{
					life = 0;
					questionVec.clear();
					questionStr = "";
					answerVec.clear();
					answerStr = "";
					break;
				}
			}
			else
			{
				end_time = clock();
				limit_time = ((TIME_LIMIT+1)*1000 - 1 - end_time + start_time) / CLOCK_PER_SECOND;
				if (limit_time > 0 && limit_time < before_time)
				{
					DrawArrowGame(life, score, questionStr, answerStr, limit_time);
					before_time = limit_time;
				}
				else if (limit_time <= 0)
				{
					--life;
					score -= 5;
					questionVec.clear();
					questionStr = "";
					answerVec.clear();
					answerStr = "";
					break;
				}
			}
		}
	}
}
