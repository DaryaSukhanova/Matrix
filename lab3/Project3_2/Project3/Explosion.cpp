#include "Figure.h"
#include "Explosion.h"



	Explosion::Explosion(int maxRadius, int minRadius, int x, int y) {
		explosionRadius = rand() % (maxRadius-minRadius) + minRadius;
		X = x;
		Y = y;
		currentRadius = 1;
		nextStepTimeExp = clock() + 500;
		Explosion::s = Symbol();
		conSize = s.getConsoleSize();
	};


	Figure* Explosion::draw() {
		if (currentRadius <= explosionRadius) {
			drawingDiamond(currentRadius, X, Y, true);
		}
		
		if (currentRadius > 1) {
			drawingDiamond(currentRadius-1, X, Y, false);
		}

		nextStepTimeExp += 500;

		if (explosionRadius == currentRadius-1) {
			flag = 1;
			return NULL;
		}
		else {
			currentRadius++;
			return NULL;
		}	
	}

	bool Explosion::isForDeletion() {
		return flag;
	}

	bool Explosion::checkY(int Y, int dev, int height) {
		return ((Y - dev) >= 1) && ((Y - dev) <= height);
	}

	bool Explosion::checkLeftX(int X, int dev, int radius) {
		return X - (radius - abs(dev)) >= 0;
	}

	bool Explosion::checkRightX(int X, int dev, int radius, int width) {
		return X + (radius - abs(dev)) < (width - 1);
	}

	bool Explosion::checkTopY(int Y, int radius) {
		return (Y - radius) >= 1;
	}

	bool Explosion::checkBottomY(int Y, int radius, int height) {
		return (Y + radius) <= height;
	}


	void Explosion::printOrMash(bool flag) {
		s.setColor(0, rand() % 14 + 1);
		if (flag == true) {
			printf("%c", s.print());
		}
		else {
			printf("%c", ' ');
		}
	}

	void Explosion::drawingDiamond(int radius, int X, int Y, bool flag) {
		if (checkTopY(Y, radius)) {
			s.gotoXY(X, Y - radius);
			printOrMash(flag);
		}
		int	dev = radius - 1;
		for (int i = 0; i < 2 * radius - 1; i++) {
			if (checkY(Y, dev, conSize.height) && checkLeftX(X, dev, radius)) {
				s.gotoXY(X - (radius - abs(dev)), Y - dev);
				printOrMash(flag);
			}

			if (checkY(Y, dev, conSize.height) && checkRightX(X, dev, radius, conSize.width)) {
				s.gotoXY(X + (radius - abs(dev)), Y - dev);
				printOrMash(flag);
			}
			dev--;
		}

		if (checkBottomY(Y, radius, conSize.height)) {
			s.gotoXY(X, Y + radius);
			printOrMash(flag);
		}
	}

