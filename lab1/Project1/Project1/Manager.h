#pragma once

#ifndef LINE_HPP
#define MANAGER_HPP
#include <vector>
#include <ctime>
#include <algorithm> 
#include "Symbol.h"
#include "Line.h"

using namespace std;
class Manager : public Line {
	int frequencyLines = 0;
	int speedLine = 0;
	int lengthLine = 0;
	char epilepsyMode = ' ';


public:
	bool printParam();
	vector<int> randomTime();

	void enteringParam(string text, int& val);
	void enteringParam(string text, char& val);

	void startWorking();
	void linesOutput();
};

#endif
