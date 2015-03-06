
#include "Vertice.h"
#include "Label.h"
#include <iostream>
#include <memory>

using namespace std;

Label::Label(const string & s):s(s){}

int Label::getType() const{
	return 0;
}

void Label::setLabel(const string &other) {
	s = other;
}

string Label::getLabel(){
	return s;
}

bool Label::operator<(const Vertice& other) const{
	if (this->getType() != other.getType())
		return this->getType() < other.getType();
	//cout << "entrou < Label\n";
	//cout << "comparando " << this->s.c_str() << " com " << dynamic_cast<const Label*>(&other)->s.c_str() << "\n";
	return  dynamic_cast<const Label*>(&other)->s.compare(this->s) < 0;
}