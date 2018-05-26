#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "GameGround.h"

using namespace sf;

void printAllWords(RenderWindow & window, GameGround gra) {
	Font font; 
	font.loadFromFile("shrift.ttf");
	Text opis("", font, 30);
	opis.setColor(Color::Blue);
	opis.setStyle(sf::Text::Bold | sf::Text::Underlined);

	int y = 50;
	for (int i = 0; i <= gra.GetKolWords(); i++) {
		opis.setString(gra.GetOpis(i));
		opis.setPosition(420, y + i * 30);
		window.draw(opis);

		opis.setString(gra.GetWord(i));
		opis.setPosition(20, y + i * 30);
		window.draw(opis);
	}
}

void menu(RenderWindow & window, GameGround gra) {
	Texture menuTexture1, menuTexture2, menuTexture3, menuTexture4, aboutTexture, menuBackground, menu1vib, menu2vib,
		menu3vib, menu4vib, wordlist;
	menuTexture1.loadFromFile("images/punkt1.png");
	menuTexture2.loadFromFile("images/punkt2.png");
	menuTexture3.loadFromFile("images/punkt3.png");
	menuTexture4.loadFromFile("images/punkt4.png");
	menu1vib.loadFromFile("images/vibpunkt1.png");
	menu2vib.loadFromFile("images/vibpunkt2.png");
	menu3vib.loadFromFile("images/vibpunkt3.png");
	menu4vib.loadFromFile("images/vibpunkt4.png");
	aboutTexture.loadFromFile("images/about.png");
	menuBackground.loadFromFile("images/bg.png");
	wordlist.loadFromFile("images/opis.png");

	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menu4(menuTexture4),
		vmenu1(menu1vib), vmenu2(menu2vib), vmenu3(menu3vib), vmenu4(menu4vib), 
		about(aboutTexture), menuBg(menuBackground), wlist(wordlist);

	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(38, 7);
	menu2.setPosition(38, 212);
	menu3.setPosition(38, 339);
	menu4.setPosition(38, 453);
	menuBg.setPosition(0, 0);

	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));
		menu1.setTexture(menuTexture1);
		menu2.setTexture(menuTexture2);
		menu3.setTexture(menuTexture3);
		menu4.setTexture(menuTexture4);
		if (IntRect(38, 7, 389, 203).contains(Mouse::getPosition(window))) { menu1.setTexture(menu1vib); menuNum = 1; }
		if (IntRect(38, 212, 389, 128).contains(Mouse::getPosition(window))) { menu2.setTexture(menu2vib); menuNum = 2; }
		if (IntRect(38, 339, 389, 112).contains(Mouse::getPosition(window))) { menu3.setTexture(menu3vib); menuNum = 3; }
		if (IntRect(38, 453, 389, 262).contains(Mouse::getPosition(window))) { menu4.setTexture(menu4vib); menuNum = 4; }
		bool a = false;
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) {	isMenu = false;	}
			if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) {
				window.draw(wlist);
				printAllWords(window, gra);
				window.display(); 
				while (!Keyboard::isKeyPressed(Keyboard::Escape));
			}
			if (menuNum == 4) { window.close(); exit(0); isMenu = false; }

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}

}

void Hide()
{
	HWND Hide;
	AllocConsole();
	Hide = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Hide, 0);
}

int main()
{
	Hide();
	GameGround gra;
	gra.NewGame();
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hangman");
	
	bool a = true;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		menu(window, gra);
		gra.NewGame();
		while (!Keyboard::isKeyPressed(Keyboard::Escape))
		{
			gra.Play(window);
		}
	}
	return 0;
}