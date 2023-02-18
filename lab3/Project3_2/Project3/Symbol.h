#pragma once
#include <iostream>
#include <string>
#include <cstring> 
#include <stdio.h>
#include <Windows.h>
#include <cstdlib>
#include <time.h>


#ifndef SYMBOL_HPP
#define SYMBOL_HPP
using namespace std;
struct cs
{
	int width;
	int height;

};
class Symbol {

public:

	struct cs getConsoleSize();
	void setColor(int background, int text);
	void gotoXY(int x, int y);
	char print();
};

#endif 