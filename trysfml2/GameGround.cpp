#include "GameGround.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <SFML\Graphics.hpp>
#include <Windows.h>
#include <random>
#include <vector>

GameGround::GameGround()
{
	string s;
	ifstream f("words.txt");
	int i = 0;
	while (!f.eof()) {
		getline(f, s);
		i++;
	}
	word = new string[i];
	opisanie = new string[i];
	f.seekg(0L);
	i = 0;
	do {

		f >> word[i];
		getline(f, opisanie[i]);
		i++;
	}while (!f.eof());

	f.close();

	kolSlov = i - 1;
}

GameGround::~GameGround()
{
	/*alph.~Alphabet();
	wp.~WordPlates();
	numMistakes = 0;
	word = nullptr;
	opisanie = nullptr;*/
}

void GameGround::NewGame()
{
	numMistakes = 7;
	
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<>dis(0, kolSlov);

	choosed = dis(gen);
	alph.Clear();
	wp.SetWord(word[choosed]);
}
void DrawHang(int num, RenderWindow & window) {
	Texture first, second, third, fourth, fifth, sixth, seventh;

	first.loadFromFile("images/bgGame.png");
	second.loadFromFile("images/bgGame1.png");
	third.loadFromFile("images/bgGame2.png");
	fourth.loadFromFile("images/bgGame3.png");
	fifth.loadFromFile("images/bgGame4.png");
	sixth.loadFromFile("images/bgGame5.png");
	seventh.loadFromFile("images/bgGame6.png");

	Sprite n1(first), n2(second), n3(third), n4(fourth), n5(fifth), n6(sixth), n7(seventh);
	
	switch (num) {
	case 7:
		window.draw(n1);
		break;
	case 6:
		window.draw(n2);
		break;
	case 5:
		window.draw(n3);
		break;
	case 4:
		window.draw(n4);
		break;
	case 3:
		window.draw(n5);
		break;
	case 2:
		window.draw(n6);
		break;
	case 1:
		window.draw(n7);
		break;

	}
	
}

void GameGround::Draw(RenderWindow & window)
{
	window.clear(Color(129, 181, 221));
	DrawHang(numMistakes, window);

	Font font;
	font.loadFromFile("shrift.ttf");
	Text opis("", font, 20);
	opis.setColor(Color::Red);
	opis.setStyle(sf::Text::Bold | sf::Text::Underlined);
	
	opis.setString("Description: " + opisanie[choosed]);
	opis.setPosition(50, 50);
	window.draw(opis);
	
	opis.setString("Number of mistakes:");
	opis.setPosition(120, 170);
	window.draw(opis);
	
	std::ostringstream n;
	n << numMistakes;
	opis.setString(n.str());
	opis.setPosition(340, 170);
	window.draw(opis);
		
	alph.Draw(font, window);
	wp.Draw(window, font);

	window.display();
}

void GameGround::GameInfo(RenderWindow & window)
{
	Font font;
	font.loadFromFile("shrift.ttf");
	Text opis("", font, 20); 
	opis.setColor(Color::Black);
	opis.setStyle(sf::Text::Bold | sf::Text::Underlined);

	opis.setString("Description: " + opisanie[choosed]);
	opis.setPosition(400, 50);
	window.draw(opis);

	opis.setString("Word: " + word[choosed]);
	opis.setPosition(400, 100);
	window.draw(opis);

	opis.setString("Number of mistakes:");
	opis.setPosition(400, 150);
	window.draw(opis);
					  

	std::ostringstream n;
	n << numMistakes;
	opis.setString(n.str());
	opis.setPosition(610, 150);
	window.draw(opis);
}
void GameGround::Play(RenderWindow & window)
{
	Texture lose, win;
	lose.loadFromFile("images/lose.png");
	win.loadFromFile("images/win.png");
	Sprite winner(win), loser(lose);
	
		if (Mouse::isButtonPressed(Mouse::Left)) {

			if (wp.chekYach(alph.GetLetterFromGround(window))) {
				alph.SetGreen(window);
			}
			else if (!wp.chekYach(alph.GetLetterFromGround(window)) && alph.CheckCoord(window)) {
				numMistakes--;
			}
			Sleep(50);
		}
		if (numMistakes <= 0) {
			window.clear();
			window.draw(loser);
			GameInfo(window);
			window.display();

		}
		else if (wp.GetNumCells() == wp.GetNumUgad()) {
			window.clear();
			window.draw(winner);
			GameInfo(window);
			window.display();

		}
		else {
			
			Draw(window);
		}
}
