#include "WordCell.h"

WordCell::WordCell()
{
	letter = ' ';
	opened = false;
}

WordCell::~WordCell()
{
	letter = ' ';
	opened = false;
	
}

void WordCell::SetLetter(char s)
{
	letter = s;
}

char WordCell::GetLetter()
{
	return letter;
}

bool WordCell::GetOpened()
{
	return opened;
}

void WordCell::SetOpened(bool b)
{
	opened = b;
}

void WordCell::SetX(float x)
{
	this->x = x;
}

float WordCell::GetX()
{
	return x;
}

void WordCell::SetY(float y)
{
	this->y = y;
}

float WordCell::GetY()
{
	return y;
}
