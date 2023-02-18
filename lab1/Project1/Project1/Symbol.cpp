#include "Symbol.h"

using namespace std;
	void Symbol::setColor(int background, int text) {
		HANDLE console_color;
		console_color = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console_color, (((background << 4) | text)));
	}

	char Symbol::print() {
		char symbol;
		symbol = rand() % 25 + 65;
		return symbol;
	}