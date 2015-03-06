#ifndef ANALISE_GRAFO
#define ANALISE_GRAFO

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <set>
#include <string.h>
#include <assert.h>

using namespace std;

class Estrutura_Ocorrencia{
public:
	int indice;
	int soma;
	int ocorre;
	Estrutura_Ocorrencia(const int , const int, const int);
};

bool operator < (const Estrutura_Ocorrencia& a, const Estrutura_Ocorrencia& b);
void OcorrenciaH_Grafo(char *, char *, char *);

#endif // !ANALISE_GRAFO