#ifndef GRAPH_H
#define GRAPH_H

#include "Label.h"
#include "Histograma.h"
#include <vector>
#include <iostream>
#include <memory>
#include <cstdlib>
#include <set>

using namespace std;


class Grafo{
	set<unique_ptr<Vertice>> Vertices;
	vector<Vertice*>indice;
	vector<vector<int> >Matriz_Adjacencia;
public:
	void printVerticesY(const char *);
	void printVerticesD(const char *);
	void printGrafoB(const char *);
	void printGrafo(const char *);
	void MontaGrafo(Label, Hsv_Dist);
	void MontaGrafo(Label l, Hsv_DiscrY h);
};

bool operator<(const unique_ptr<Vertice> &, const unique_ptr<Vertice> &);

#endif