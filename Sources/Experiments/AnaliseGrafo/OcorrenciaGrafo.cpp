#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <set>
#include <string.h>
#include <assert.h>
#include "OcorrenciaGrafo.h"

using namespace std;

Estrutura_Ocorrencia::Estrutura_Ocorrencia(const int ind, const int som, const int oco):indice(ind), soma(som), ocorre(oco){}

bool operator < (const Estrutura_Ocorrencia& a, const Estrutura_Ocorrencia& b){
	return (a.indice) < (b.indice);
}

void OcorrenciaH_Grafo(char *arquivo_g, char *arquivo_v, char* arquivo_p){

	multiset<Estrutura_Ocorrencia>Ocorrencia;
	multiset<Estrutura_Ocorrencia>::iterator it;

	//char *arquivo_g = argv[1], *arquivo_v = argv[2], *arquivo_p = argv[3];
	int n = 0, aux = 0, c = 0, soma = 0, ind = 0;
	printf("%s \n", arquivo_g);
	FILE *arq_grafo = fopen(strcat(arquivo_g, ".bin"), "rb");
	assert(arq_grafo != NULL);

	FILE *arq_vertices = fopen(strcat(arquivo_v, ".bin"), "rb");
	assert(arq_vertices != NULL);

	FILE *arq_print = fopen(strcat(arquivo_p, ".m"), "rb");
	assert(arq_print != NULL);

	fscanf(arq_grafo, "%d", &n);
	fprintf(arq_print, "n = %d;", n);

	for (int i = 0; i<n; i++){
		fscanf(arq_vertices, "%d", &ind);
		for (int j = 0; j<n; j++){
			fscanf(arq_grafo, "%d", &aux);
			if (aux != 0){
				c++;
				soma += aux;

			}
		}
		//printf("c = %d\n", c);
		//printf("teste = %d %d %d\n", ind, soma, c);
		Estrutura_Ocorrencia aux_i(ind, soma, c);
		Ocorrencia.insert(aux_i);
		c = 0;
		soma = 0;
	}

	int v = 0, i = 0;
	fprintf(arq_print, "Ocorre = [");
	for (it = Ocorrencia.begin(), i = 0; it != Ocorrencia.end(); it++, i++){
		if (it->indice != 0 && v != 0)
			v = i;
		fprintf(arq_print, "%d ", it->ocorre);
	}
	fprintf(arq_print, "];");

	fprintf(arq_print, "indice_Hist = %d;", v);

	fclose(arq_grafo);
	fclose(arq_vertices);
	fclose(arq_print);

}
