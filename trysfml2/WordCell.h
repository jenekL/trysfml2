#pragma once
#include <iostream>

class WordCell {
private:
	char letter;
	bool opened;
	float x, y;

public:
	WordCell();
	~WordCell();

	void SetLetter(char);
	char GetLetter();
	bool GetOpened();
	void SetOpened(bool);
	void SetX(float);
	float GetX();
	void SetY(float);
	float GetY();

};
