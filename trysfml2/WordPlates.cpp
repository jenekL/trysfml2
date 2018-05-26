#include "WordPlates.h"
using namespace sf;
WordPlates::WordPlates()
{
}

WordPlates::WordPlates(string s)
{
	float x = -200.0f, y = 0.0f;
	float rad = 25;

	numCells = s.length();
	wc = new WordCell[numCells];
	for (int i = 0; i < numCells; i++) {
		wc[i].SetLetter(s[i]);

		if (x > 200.0f) {
			x = -200.0f;
			y = -30.0f;
		}
		wc[i].SetX(x);
		wc[i].SetY(y);
		x += rad*2.5;
	}

	

}

WordPlates::~WordPlates()
{
	/*wc->~WordCell();
	numCells = 0;
	numUgad = 0;*/
}

void WordPlates::Clear()
{

}

void WordPlates::SetWord(string s)
{
	numUgad = 0;
	numCells = 0;

	float x = 30.0f, y = 285.0f;
	float rad = 25;

	numCells = s.length();
	wc = new WordCell[numCells];
	for (int i = 0; i < numCells; i++) {
		wc[i].SetLetter(s[i]);

		if (x > 350.0f) {
			x = 10.0f;
			y += 100.0f;
		}
		wc[i].SetX(x);
		wc[i].SetY(y);
		x += rad*2.5;
	}
}

int WordPlates::GetNumUgad()
{
	return numUgad;
}

int WordPlates::GetNumCells()
{
	return numCells;
}

bool WordPlates::chekYach(char s)
{
	bool b = false;
	for (int i = 0; i < numCells; i++) {
		if (wc[i].GetOpened()) {
			
			continue;
		}
		else if (wc[i].GetLetter() == s) {
			wc[i].SetOpened(true);
			numUgad++;
			b = true;
		}
	}


	return b;
}

void WordPlates::printYach()
{
}

void WordPlates::Draw(RenderWindow & window, Font font)
{
	RectangleShape rect;
	Text lett("", font, 30);
	lett.setColor(Color::Red);
	lett.setStyle(sf::Text::Bold | sf::Text::Underlined); 

	

	float rad = 40;
	for (int i = 0; i < numCells; i++) {
		
		rect.setPosition(wc[i].GetX(), wc[i].GetY());
	
		rect.setSize(Vector2f(rad, rad));
		rect.setOutlineThickness(10);
		
		rect.setOutlineColor(sf::Color(147, 112, 219)); //106, 90, 205
		
		window.draw(rect);


		lett.setPosition(wc[i].GetX() + 10, wc[i].GetY() + 5);
		
		if (wc[i].GetOpened()) {
			lett.setString(wc[i].GetLetter());
		}
		else {
			lett.setString("*");
		}
		window.draw(lett);


	}
}
