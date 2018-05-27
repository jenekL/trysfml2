#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "GameGround.h"
#include "Menuh.h"

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
	GameGround& gra = GameGround::Instance();
	gra.NewGame();
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hangman");
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		Menu::menu(window, gra);
		gra.NewGame();
		while (!Keyboard::isKeyPressed(Keyboard::Escape))
		{
			gra.Play(window);
			
		}
	}
	return 0;
}