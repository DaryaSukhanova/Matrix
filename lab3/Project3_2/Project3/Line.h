#pragma once
#ifndef LINE_HPP
#define LINE_HPP 

#include "Figure.h"
#include "Explosion.h"
#include <iostream>
#include <string>
#include <cstring> 
#include <stdio.h>
#include <Windows.h>
#include <cstdlib> 
#include <time.h>
using namespace std;


class Line : public Figure {
	struct cs conSize;

	int N;
	
	int nextStepTime = 0;

	char saveSymbol = ' ';
	char saveSymbol1 = ' ';
	char saveSymbol2 = ' ';
	int color;
	Explosion* exp = 0;
	int lengthLine = 0;

	char epilepsyMode = ' ';
	int probabilityExplosion = 0;
	int maxRadius = 0;
	int minRadius = 0;
	int speedLine = 0;

public:
	//struct cs getConsoleSize();
	Line(int length, int speed, char epilepsy, int probability, int maxRadius, int minRadius);

	int getHeight() const { return conSize.height; }
	int getWidth() const { return conSize.width; }
	int getNextStepTime() const { return nextStepTime; }
	Explosion* getExplosion() { return Line::exp; }
	void setExplosion(Explosion* elementExp);
	void setLengthLine(int length);
	void setNextStepTime(int);
	void setX(int);
	void mashing();
	void gotoXY(int x, int y);
	void currentColor(char epilepsyMode);

	Symbol s;
	Symbol s1;
	Symbol s2;

	int X = 0;
	int Y;
	bool rightBorder(int X, int width);
	bool leftBorder(int X);
	bool heightCheck(int y, int height);
	bool calculationProbability(int probabilityExplosion);
	bool deleteLine(int length, int Y);
	//int moveLine(char epilepsyMode, int probabilityExplosion, int maxRadius, int minRadius);
	Figure* draw();
	bool isForDeletion();
	bool flag = 0;
};


#endif
