#pragma once
#include <iostream>
#include "WordCell.h"
#include <SFML\Graphics.hpp>

using namespace std;

class WordPlates {
private:
	WordCell * wc;
	int numCells = 0;
	int numUgad = 0;

public:
	WordPlates();
	WordPlates(string);
	~WordPlates();

	void Clear();
	void SetWord(string);
	int GetNumUgad();
	int GetNumCells();
	bool chekYach(char);
	void printYach();
	void Draw(sf::RenderWindow & window, sf::Font);

};
