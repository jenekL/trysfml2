#pragma once
#include "Alphabet.h"
#include "WordPlates.h"
#include <iostream>
#include <SFML\Graphics.hpp>

using namespace sf;
class GameGround {
private:
	Alphabet alph;
	WordPlates wp;
	int numMistakes = 7;
	int kolSlov = 0;
	int choosed = 0;
	string *word;
	string *opisanie;


	GameGround();
	~GameGround();
		
	GameGround(GameGround const&); 
	GameGround& operator= (GameGround const&);  

public:
	static GameGround& Instance()
	{
		static GameGround s;
		return s;
	}

	int GetNumMist() { return numMistakes; }
	int GetKolWords() { return kolSlov; }
	string GetOpis(int i) { return opisanie[i]; }
	string GetWord(int i) { return word[i]; }
	void GameInfo(RenderWindow & window);
	void NewGame();
	void Draw(RenderWindow & );
	void DrawHang(int, RenderWindow &);
	void Play(RenderWindow &);


};
