#include <iostream>
#include <string>
#include <cstring> 
#include <stdio.h>
#include <Windows.h>
#include "Manager.h"
#include "Line.h"
#include "Explosion.h"


using namespace std;

void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdOut, coord);
}
void hideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	Manager m = Manager();
	
	hideCursor();
	m.startWorking();
	//Explosion exp = Explosion(5, 2, 10, 10);
	//exp.moveExplosion();
	//Explosion exp = Explosion(5, 4, 10, 10);
	//Explosion* expPtr = &exp;
	//int stopExp;
	//exp.nextStepTimeExp = clock() + 500;
	//while (true) {
		//if (exp.nextStepTimeExp <= clock()) {
			//stopExp = exp.moveExplosion();
			//exp.nextStepTimeExp += 500;
			//cout << exp.nextStepTimeExp << endl;
			//cout << clock() << endl;
		//}
		
	//}
	system("pause");
	return 0;
}