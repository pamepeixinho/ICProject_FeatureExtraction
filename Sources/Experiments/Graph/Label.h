#ifndef LABEL_H
#define LABEL_H

#include "Vertice.h"
#include <iostream>
using namespace std;

class Label : public Vertice{
	string s;
public:

	Label(const string&);
	int getType() const;
	void setLabel(const string &);
	string getLabel();
	bool operator<(const Vertice& other) const;
	~Label(){}

};

#endif 
