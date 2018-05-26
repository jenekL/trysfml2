#include "Alphabet.h"

using namespace sf;

Alphabet::Alphabet()
{
	letter = new char[kol];
	x = new float[kol];
	y = new float[kol];
	

	int num = 97;
	int j = 0;
	float x = 20.0f, y = 400.0f;


	for (int i = 0; i < kol; i++) {
	
		letter[i] = num++;
		color[i][0] = 0.0f;
		color[i][1] = 0.0f;
		color[i][2] = 1.0f;

		if (x > 390.0f) {
			x = 20.0f;
			y += 30.0f;
		}
		x += 30;
		this->x[i] = x;
		this->y[i] = y;
	}


}

Alphabet::~Alphabet()
{
	/*for (int i = 0; i < kol; i++) {

		letter[i] = ' ';
		color[i][0] = 0.0f;
		color[i][1] = 0.0f;
		color[i][2] = 0.0f;
	}
	kol = 0;*/
}

void Alphabet::Clear()
{
	for (int i = 0; i < kol; i++) {

		color[i][0] = 0.0f;
		color[i][1] = 0.0f;
		color[i][2] = 0.0f;
	}
}

void Alphabet::Draw(Font font,RenderWindow & window)
{

	RectangleShape rect;
	for (int i = 0; i < kol; i++) {
		rect.setPosition(x[i], y[i]);
		rect.setFillColor(Color(color[i][0], color[i][1], color[i][2], 255));
		rect.setSize(Vector2f(25,25));
		window.draw(rect);

		Text opis("", font, 20);
		opis.setColor(Color::Magenta);
		opis.setStyle(sf::Text::Bold | sf::Text::Underlined);

		opis.setString(letter[i]);
		opis.setPosition(x[i] + 5, y[i]);
		window.draw(opis);

	}
}

char Alphabet::GetLetterFromGround(RenderWindow & window)
{
	
	char ret = ' ';
	for (int i = 0; i < kol; i++) {
		if (IntRect(x[i], y[i], 25, 25).contains(Mouse::getPosition(window))) {

				ret = letter[i];
				color[i][0] = 255;
				color[i][1] = 0.0f;
				color[i][2] = 0.0f;

				Font font;
				font.loadFromFile("shrift.ttf");
				Text opis("", font, 20);
				opis.setColor(Color::Cyan);
				opis.setStyle(sf::Text::Bold | sf::Text::Underlined);

				opis.setString(letter[i]);
				opis.setPosition(20, 20);
				window.draw(opis);
		}


	}

	return ret;
}

bool Alphabet::CheckCoord(RenderWindow & window)
{
	bool c = false;
	for (int i = 0; i < kol; i++) {
		if (IntRect(x[i], y[i], 25, 25).contains(Mouse::getPosition(window))) {
				c = true;
		}
	}
	return c;
}

void Alphabet::SetGreen(RenderWindow & window)
{
	for (int i = 0; i < kol; i++) {
		if (IntRect(x[i], y[i], 25, 25).contains(Mouse::getPosition(window))) {
			color[i][0] = 0.0f;
			color[i][1] = 255;
			color[i][2] = 0.0f;
		}
	}
}
