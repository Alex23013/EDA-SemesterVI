#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <vector>
#include <math.h>

#include "dot.h"

class Array{
public:
	vector<Dot> arrayContent;
	double minDistance;
	double maxDistance;
	double promDistance;

Array(int numOfDots, int numOfDim);
void print();
double caldistance();

};

#endif
