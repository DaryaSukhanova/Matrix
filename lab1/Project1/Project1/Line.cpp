
#include "Line.h"

using namespace std;

	void Line::setTimeAppearance(int time) {
		timeAppearance = time;
	}
	void Line::setX(int x) {
		X = x;
	}

	struct cs Line::getConsoleSize()
	{
		struct cs tmp;
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(hStdOut, &csbi);
		tmp.width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		tmp.height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
		return tmp;
	}
	Line::Line() {
		conSize = getConsoleSize();
		Y = conSize.height;
		N = rand() % 2;
		Line::s = Symbol();
		Line::s1 = Symbol();
		Line::s2 = Symbol();
		color = rand() % 14 + 1;
	}

	
	void Line::GotoXY(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hStdOut, coord);
	}


	void Line::currentColor(char epilepsyMode) {

		if (epilepsyMode == 'N' || epilepsyMode == 'n') {
			setColor(0, 2);
		}
		else {
			setColor(0, color);
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

	int Line::paintLine(int lengthLine, char epilepsyMode) {

		if (Y + lengthLine < 1) {
			return 1;
		}

		if (N % 2 == 0) { //checking for the first output of a single or double character
			
			if (heightCheck(Y, conSize.height)) { //checking a double character for a vertical limit
				saveSymbol1 = s1.print();
				saveSymbol2 = s2.print();
				setColor(0, 15);
				if (rightBorder(X, conSize.width)) { //checking for going beyond the right border
					GotoXY(X + 1, Y);
					printf("%c", saveSymbol1);
				}
				if (leftBorder(X)) { //checking for going beyond the left border
					GotoXY(X - 1, Y);
					printf("%c", saveSymbol2);
				}
			}

			if (heightCheck(Y+1, conSize.height)) { //checking the previous single character for a vertical limit
				//changing the color of a single character
				GotoXY(X, Y + 1);
				currentColor(epilepsyMode);
				printf("%c", saveSymbol);
			}
		}
		else {
			saveSymbol = s.print();
			if (heightCheck(Y, conSize.height)) { //checking a single character for a vertical limit
				GotoXY(X, Y);
				setColor(0, 15);
				printf("%c", saveSymbol);
			}
			if (heightCheck(Y + 1, conSize.height)) { //checking the previous double character for a vertical limit
				currentColor(epilepsyMode);
				if (rightBorder(X, conSize.width)) { //checking for going beyond the right border
					GotoXY(X + 1, Y + 1);
					printf("%c", saveSymbol1);
				}
				if (leftBorder(X)) { //checking for going beyond the left border
					GotoXY(X - 1, Y + 1);
					printf("%c", saveSymbol2);
				}
			}


		}

		if ((N+lengthLine) % 2 == 0) { //checking for erasure of a single or double character
			if (heightCheck(Y + lengthLine, conSize.height)) { //checking the last double character for a vertical limit
				if (rightBorder(X, conSize.width)) { //checking for going beyond the right border
					GotoXY(X + 1, Y + lengthLine);
					printf("%c", ' ');
				}
				if (leftBorder(X)) { //checking for going beyond the left border
					GotoXY(X - 1, Y + lengthLine);
					printf("%c", ' ');
				}

			}
		}
		else  {
			if (heightCheck(Y + lengthLine, conSize.height)) { //checking the last single character for a vertical limit
				GotoXY(X, Y + lengthLine);
				printf("%c", ' ');
			}
		}
	
		Y--;
		N++;

		return 0;
	}
