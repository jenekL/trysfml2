#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
class Alphabet {
private:
	char* letter;
	int kol = 26;
	float *y, *x;
	float color[27][3];
	

public:
	Alphabet();
	~Alphabet();

	void Clear();
	void Draw(sf::Font, RenderWindow & window);
	char GetLetterFromGround( RenderWindow & window);
	bool CheckCoord(RenderWindow & window);
	void SetGreen(RenderWindow & window);
};