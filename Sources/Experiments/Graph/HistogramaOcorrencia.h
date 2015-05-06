#ifndef OCORRENCIA_LABEL_H
#define OCORRENCIA_LABEL_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <set>
#include <string.h>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

class Ocorrencia_Label{
public:
	int indice;
	vector<int>c;
	float media;
	Ocorrencia_Label(int, vector<int>, float);
	bool operator < (const Ocorrencia_Label &other)const;
};

bool ordenaGrau(const Ocorrencia_Label &, const Ocorrencia_Label &);

class HistogramaOcorrencia{
	vector<Ocorrencia_Label>Oco;
	vector<vector<int> > Matriz;
	vector<int>ocorre;
	vector<char*> top;
	vector<char*> down;
public:
	HistogramaOcorrencia(char *, char *, char*, char *);
	int grau(int);
	vector<int> grau_v(int);
	char * buscaLabel(char *, int);
	bool compara(const Ocorrencia_Label& ,const Ocorrencia_Label&);
};

#endif
