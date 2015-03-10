#ifndef GRAPH_H
#define GRAPH_H

#include "Label.h"
#include "Histograma.h"
#include <vector>
#include <iostream>
#include <memory>
#include <cstdlib>
#include <string.h>
#include <set>

using namespace std;

template<typename type1, typename type2>
class Graph{
	set<unique_ptr<Vertice>> Vertices;
	vector<Vertice*>indice;
	vector<vector<int> >Matriz_Adjacencia;
public:
	void printVertices(const char *);
	void printGraph(const char *);
	void ConstructEdges(type1, type2);
	//void ConstructEdges(Label, Hsv_DiscrY);
};

bool operator<(const unique_ptr<Vertice> &, const unique_ptr<Vertice> &);

#endif