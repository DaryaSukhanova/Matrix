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

class Symbol {

public:
	void setColor(int background, int text);
	char print();
};

#endif 