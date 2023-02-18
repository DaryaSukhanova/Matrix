#include "Symbol.h"

using namespace std;

struct cs Symbol::getConsoleSize()
{
	struct cs tmp;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	tmp.width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	tmp.height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	return tmp;
}
	void Symbol::setColor(int background, int text) {
		HANDLE console_color;
		console_color = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console_color, (((background << 4) | text)));
	}

	void Symbol::gotoXY(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hStdOut, coord);
	}



	char Symbol::print() {
		char symbol;
		symbol = rand() % 25 + 65;
		return symbol;
	}