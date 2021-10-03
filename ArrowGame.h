#ifndef ARROWGAME_H
#define ARROWGAME_H

#include "GameCategory.h"

#define TIME_LIMIT 5

class ArrowGame
{
private :
	GameCategory GameCate;
public :
	void GoArrowGame(int GameNum);
	void DrawArrowGame(int life, int score, string q, string a, clock_t limit_time);
	void SetQuestion(vector<int>& questionVec, int level);
	void VectorToString(vector<int> v, string& str);
	bool CheckAnswer(vector<int> q, vector<int> a);
	void ArrowGameOver(int score);
	void StartArrowGame();
};

#endif /*ARROWGAME_H*/