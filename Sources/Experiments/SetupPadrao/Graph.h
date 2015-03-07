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


class Graph{
	set<unique_ptr<Vertice>> Vertices;
	vector<Vertice*>indice;
	vector<vector<int> >Matriz_Adjacencia;
public:
	void printVerticesY(const char *);
	void printVerticesD(const char *);
	void printGraphB(const char *);
	void printGraph(const char *);
	void ConstructEdges(Label, Hsv_Dist);
	void ConstructEdges(Label, Hsv_DiscrY);
};

bool operator<(const unique_ptr<Vertice> &, const unique_ptr<Vertice> &);

#endif