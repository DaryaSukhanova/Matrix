#include <iostream>
#include <string>
#include <cstring> 
#include <stdio.h>
#include <Windows.h>
#include "Manager.h"
#include "Line.h"
#include "Explosion.h"
#include "Vector.h"


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

	//Vector<int> vector;
	//vector.pushBack(42);
	//cout << vector[0] << endl;
	//cout << "size " << vector.sizeVector() << endl;
	//cout << "capacity " << vector.capacityVector() << endl;

	//vector.pushBack(67);
	//cout << vector[1] << endl;
	//cout << "size "  << vector.sizeVector() << endl;
	//cout << "capacity " << vector.capacityVector() << endl;

	//vector.insert(1, 100);
	//cout << vector[0] << " " << vector[1] << " " << vector[2]  << " " << endl;
	//cout << "size " << vector.sizeVector() << endl;
	//cout << "capacity " << vector.capacityVector() << endl;

	//vector.pushFront(3);
	//cout << vector[0] << " " << vector[1] << " " << vector[2] << " " << endl;
	//cout << "size " << vector.sizeVector() << endl;
	//vector.insert(7, 10);
	//vector.resize(6, 9);
	//cout << "size " << vector.sizeVector() << endl;
	//for (int i = 0; i < 6; i++) {
	//	cout << vector[i] << " ";
	//}
	//vector.resize(3);
	//for (int i = 0; i < 6; i++) {
	//	cout << vector[i] << " ";
	//}
	//cout << vector[5] << " ";

	system("pause");
	return 0;
}