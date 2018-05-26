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

public:
	GameGround();
	~GameGround();

	int GetNumMist() { return numMistakes; }
	int GetKolWords() { return kolSlov; }
	string GetOpis(int i) { return opisanie[i]; }
	string GetWord(int i) { return word[i]; }
	void GameInfo(RenderWindow & window);
	void NewGame();
	void Draw(RenderWindow & );
	void Play(RenderWindow &);


};
