#ifndef NEIGHBOOR_H
#define NEIGHBOOR_H

#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Neighboor{
public:
	string label;
	int qt;
	Neighboor();
};

class NeighboorsRegion{
public:
	int getNota();	
	string correct_label;
	vector<Neighboor>vizinhos;
	NeighboorsRegion();
	
};

#endif
