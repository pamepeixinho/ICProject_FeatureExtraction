#ifndef VERTICE_H
#define VERTICE_H

class Vertice{
public:
	int idx = 0;
	virtual int getType() const = 0;
	virtual ~Vertice(){}
	//virtual Vertice * criaVertice(const Vertice &outro) = 0;
	//virtual void imprime()const =0;
	virtual bool operator<(const Vertice& other) const = 0;

};

#endif