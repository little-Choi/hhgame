#ifndef DINOSAURGAME_H
#define DINOSAURGAME_H

class DinosaurGame
{
private:
	GameCategory GameCate;
public:
	void GoDinoGame(int GameNum);
	void StartDinoGame();
	void InitDinoGame();
	void DrawDino(int DinoY);

};



#endif /*DINOSAURGAME_H*/
