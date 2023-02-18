#pragma once
#ifndef FIGURE_HPP 
#define FIGURE_HPP 

#include <cmath>

class Figure {
public:
	virtual bool isForDeletion() = 0;
	virtual Figure* draw() = 0;
	virtual int getNextStepTime() const = 0;
};
#endif 