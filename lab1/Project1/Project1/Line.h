#pragma once
#ifndef LINE_HPP
#define LINE_HPP

#include "Symbol.h"
#include <iostream>
#include <string>
#include <cstring> 
#include <stdio.h>
#include <Windows.h>
#include <cstdlib>
#include <time.h>
using namespace std;
struct cs
{
	int width;
	int height;

};

class Line : public Symbol {
	struct cs conSize;

	int Y;
	int N;
	int X = 0;
	int timeAppearance = 0;

	char saveSymbol;
	char saveSymbol1;
	char saveSymbol2;
	int color;

public:
	struct cs getConsoleSize();
	Line();
	
	int getHeight() const { return conSize.height; }
	int getWidth() const { return conSize.width; }
	int getTimeAppearance() const { return timeAppearance; }

	void setTimeAppearance(int);
	void setX(int);

	void GotoXY(int x, int y);

	void currentColor(char epilepsyMode);

	Symbol s;
	Symbol s1;
	Symbol s2;

	bool rightBorder(int X, int width);
	bool leftBorder(int X);
	bool heightCheck(int y, int height);

	int paintLine(int lengthLine, char epilepsyMode);

};


#endif
