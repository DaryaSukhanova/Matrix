#include "Line.h"
#include "Manager.h"

using namespace std;

	void Line::setNextStepTime(int time) {
		nextStepTime = time;
	}
	void Line::setX(int x) {
		X = x;
	}

	void Line::setExplosion(Explosion* elementExp) {
		exp = elementExp;
	}

	void Line::setLengthLine(int length) {
		lengthLine = length;
	}

	Line::Line(int length, int speed, char epilepsy, int probability, int maxRad, int minRad) {
		
		Line::s = Symbol();
		Line::s1 = Symbol();
		Line::s2 = Symbol();

		conSize = s.getConsoleSize();
		Y = conSize.height;
		N = rand() % 2;
		color = rand() % 14 + 1;		

		nextStepTime = clock() + rand() % 1000;
		X = rand() % (getWidth() - 1) + 1;
		lengthLine = length;
		epilepsyMode = epilepsy;
		probabilityExplosion = probability;
		speedLine = speed;
		maxRadius = maxRad;
		minRadius = minRad;
	}

	
	void Line::gotoXY(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hStdOut, coord);
	}


	void Line::currentColor(char epilepsyMode) {

		if (epilepsyMode == 'N' || epilepsyMode == 'n') {
			s.setColor(0, 2);
		}
		else {
			s.setColor(0, color);
		}

	}

	bool Line::rightBorder(int X, int width){
		return X + 1 < width;
	}
	bool Line::leftBorder(int X) {
		return X - 1 >= 0;
	}
	bool Line::heightCheck(int y, int height) {
		return y <= height && y >= 1;
	}

	bool Line::calculationProbability(int probabilityExplosion) {
		if (rand() % 1000 + 1 <= probabilityExplosion) {
			return true;
		}
		else {
			return false;
		}
	}

	bool Line::checkDeletion(int length, int Y) {
		return lengthLine == 0 || Y + lengthLine < 1;
	}

	void Line::mashing() {
		if ((N + lengthLine) % 2 == 0) { //checking for erasure of a single or double character
			if (heightCheck(Y + lengthLine, conSize.height)) { //checking the last double character for a vertical limit
				if (rightBorder(X, conSize.width)) { //checking for going beyond the right border
					gotoXY(X + 1, Y + lengthLine);
					printf("%c", ' ');
				}
				if (leftBorder(X)) { //checking for going beyond the left border
					gotoXY(X - 1, Y + lengthLine);
					printf("%c", ' ');
				}

			}
		}
		else {
			if (heightCheck(Y + lengthLine, conSize.height)) { //checking the last single character for a vertical limit
				gotoXY(X, Y + lengthLine);
				printf("%c", ' ');
			}
		}
	}

	Figure* Line::draw() {
		if (checkDeletion(lengthLine, Y)) {
			flag = 1;
			return NULL;
		}
		
		if (N % 2 == 0) { //checking for the first output of a single or double character
			
			if (heightCheck(Y, conSize.height)) { //checking a double character for a vertical limit
				saveSymbol1 = s1.print();
				saveSymbol2 = s2.print();
				s.setColor(0, 15);
				if (rightBorder(X, conSize.width)) { //checking for going beyond the right border
					gotoXY(X + 1, Y);
					printf("%c", saveSymbol1);
				}
				if (leftBorder(X)) { //checking for going beyond the left border
					gotoXY(X - 1, Y);
					printf("%c", saveSymbol2);
				}
			}

			if (heightCheck(Y+1, conSize.height)) { //checking the previous single character for a vertical limit
				//changing the color of a single character
				gotoXY(X, Y + 1);
				currentColor(epilepsyMode);
				printf("%c", saveSymbol);
			}
		}
		else {
			saveSymbol = s.print();
			if (heightCheck(Y, conSize.height)) { //checking a single character for a vertical limit
				gotoXY(X, Y);
				s.setColor(0, 15);
				printf("%c", saveSymbol);
			}
			if (heightCheck(Y + 1, conSize.height)) { //checking the previous double character for a vertical limit
				currentColor(epilepsyMode);
				if (rightBorder(X, conSize.width)) { //checking for going beyond the right border
					gotoXY(X + 1, Y + 1);
					printf("%c", saveSymbol1);
				}
				if (leftBorder(X)) { //checking for going beyond the left border
					gotoXY(X - 1, Y + 1);
					printf("%c", saveSymbol2);
				}
			}

		}

		mashing();

		Y--;
		N++;
		nextStepTime += 1000 / speedLine;

		if ((calculationProbability(probabilityExplosion) == true) && (Y >= 1)) {
			Figure* exp = new Explosion(maxRadius, minRadius, X, Y);
			mashing();
			lengthLine = lengthLine - 1;
			return exp;
		}
		return NULL;
	}

	bool Line::isForDeletion() {
		return flag;
	}
