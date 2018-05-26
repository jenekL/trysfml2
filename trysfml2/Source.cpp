#include <SFML/Graphics.hpp>
#include <Windows.h>

using namespace sf;

void menu(RenderWindow & window) {
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground, menu1vib;
	menuTexture1.loadFromFile("images/punktnevib1.png");
	menuTexture2.loadFromFile("images/punktnevib2.png");
	menuTexture3.loadFromFile("images/punktnevib3.png");
	menu1vib.loadFromFile("images/punkt1.png");
	aboutTexture.loadFromFile("images/2.png");
	menuBackground.loadFromFile("images/bg.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(100, 30);
	menu2.setPosition(100, 180);
	menu3.setPosition(100, 330);
	menuBg.setPosition(0, 0);

	//////////////////////////////МЕНЮ///////////////////
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

		if (IntRect(100, 30, 300, 150).contains(Mouse::getPosition(window))) { menu1.setTexture(menu1vib); menuNum = 1; }
		if (IntRect(100, 180, 300, 150).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		if (IntRect(100, 330, 300, 150).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) { isMenu = false; while (!Keyboard::isKeyPressed(Keyboard::Escape)); }//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { window.close(); isMenu = false; }

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
	////////////////////////////////////////////////////

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
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(shape);
		window.display();
		menu(window);

	}

	return 0;
}