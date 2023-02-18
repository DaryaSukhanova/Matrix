#pragma once

#ifndef EXPLOSION_HPP
#define EXPLOSION_HPP

#include "Figure.h"
#include "Symbol.h"
using namespace std;

class Explosion : public Figure {
	Symbol s;
	struct cs conSize;
public:
	Explosion(int maxRadius, int minRadius, int x, int y);
	int X;
	int Y;
	int currentRadius;
	int explosionRadius = 0;
	int nextStepTimeExp = 0;
	int getNextStepTime() const { return nextStepTimeExp; }

	void drawingDiamond(int radius, int X, int Y, bool flag);

	bool checkY(int Y, int dev, int height);
	bool checkLeftX(int X, int dev, int radius);
	bool checkRightX(int X, int dev, int radius, int width);
	bool checkBottomY(int Y, int radius, int height);
	bool checkTopY(int Y, int radius);

	void printOrMash(bool flag);

	Figure* draw();
	bool isForDeletion();
	bool flag = 0;

};

#endif
