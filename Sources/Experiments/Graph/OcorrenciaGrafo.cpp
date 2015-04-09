#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <set>
#include <string.h>
#include <assert.h>
#include "OcorrenciaGrafo.h"

using namespace std;

Estrutura_Ocorrencia::Estrutura_Ocorrencia(const int ind, const int type, const int som, const int oco):indice(ind),type(type), soma(som), ocorre(oco){}

bool operator < (const Estrutura_Ocorrencia& a, const Estrutura_Ocorrencia& b){
	return (a.type) < (b.type);
}

void OcorrenciaH_Grafo(char *arquivo_v, char *arquivo_g, char* arquivo_p){

	int n = 0, aux = 0, c = 0, soma = 0, ind = 0, type=0;
	
//	printf("1 - %s \n", arquivo_g);
	multiset<Estrutura_Ocorrencia>Ocorrencia;
	multiset<Estrutura_Ocorrencia>::iterator it;


//	printf("2 - %s \n", arquivo_g);
	char print[150];
	char print_matlab[150];
	strcpy(print, arquivo_p);
	strcpy(print_matlab, arquivo_p);

//	printf("p - %s \n", arquivo_p);	
//	printf("g - %s \n", arquivo_g);
//	printf("v - %s \n", arquivo_v);

	FILE *arq_grafo = fopen(arquivo_g, "rb");
//	printf("%s \n", arquivo_g);
	assert(arq_grafo != NULL);

	FILE *arq_vertices = fopen(arquivo_v, "rb");
//	printf("v - %s \n", arquivo_v);
	assert(arq_vertices != NULL);

	FILE *arq_print = fopen(strcat(print_matlab, "MATLAB.m"), "w");
//	printf("p1 - %s \n",print_matlab);
	assert(arq_print != NULL);

	FILE *arq_print_b = fopen(strcat(print, ".bin"), "wb");	
//	printf("p2 - %s \n",print);
	assert(arq_print_b != NULL);
	
	fscanf(arq_grafo, "%d", &n);
	fprintf(arq_print, "n = %d;", n);

	fprintf(arq_print_b, "%d ", n);
		
	for (int i = 0; i<n; i++){
		fscanf(arq_vertices, "%d", &type);
		for (int j = 0; j<n; j++){
			fscanf(arq_grafo, "%d", &aux);
			if (aux != 0){
				c++;
				soma += aux;

			}
		}
		ind = i;
//		printf("c = %d\n", c);
//		printf("teste = %d %d %d\n", ind, soma, c);
		Estrutura_Ocorrencia aux_i(ind,type,  soma, c);
		Ocorrencia.insert(aux_i);
		ind = 0;
		c = 0;
		soma = 0;
		type=0;
	}

	int v = -1, i = 0;
	fprintf(arq_print, "Ocorre = [");
	for (it = Ocorrencia.begin(), i = 0; it != Ocorrencia.end(); it++, i++){
		if (it->type != 0 && v == -1){
			v=i;
			printf("V = %d\n", v);
		}
		fprintf(arq_print, "%d ", it->ocorre);
//		printf("%d\n ", it->type);
	}
	
	fprintf(arq_print, "];");

	fprintf(arq_print, "indice_Hist = %d;", v);

//	printf("%d\n", v);
	fprintf(arq_print_b, "%d ", v);

	for (it = Ocorrencia.begin(); it != Ocorrencia.end(); it++)
		fprintf(arq_print_b, "%d ", it->ocorre);
	
	Ocorrencia.clear();

	fclose(arq_grafo);
	fclose(arq_vertices);
	fclose(arq_print);
	fclose(arq_print_b);

//	printf("ok\n");
} 


void OcorrenciaVert_Grafo(char *arquivo_v, char *arquivo_g, char* arquivo_p){

	int n = 0, aux = 0, c = 0, soma = 0, ind = 0, type=0;
	
//	printf("1 - %s \n", arquivo_g);
	multiset<Estrutura_Ocorrencia>Ocorrencia;
	multiset<Estrutura_Ocorrencia>::iterator it;


//	printf("2 - %s \n", arquivo_g);
	char print[150];
	char print_matlab[150];
	strcpy(print, arquivo_p);
	strcpy(print_matlab, arquivo_p);

//	printf("p - %s \n", arquivo_p);	
//	printf("g - %s \n", arquivo_g);
//	printf("v - %s \n", arquivo_v);

	FILE *arq_grafo = fopen(arquivo_g, "rb");
//	printf("%s \n", arquivo_g);
	assert(arq_grafo != NULL);

	FILE *arq_vertices = fopen(arquivo_v, "rb");
//	printf("v - %s \n", arquivo_v);
	assert(arq_vertices != NULL);

	FILE *arq_print = fopen(strcat(print_matlab, "MATLAB.m"), "w");
//	printf("p1 - %s \n",print_matlab);
	assert(arq_print != NULL);

	FILE *arq_print_b = fopen(strcat(print, ".bin"), "wb");	
//	printf("p2 - %s \n",print);
	assert(arq_print_b != NULL);
	
	fscanf(arq_grafo, "%d", &n);
	fprintf(arq_print, "n = %d;", n);

//	fprintf(arq_print_b, "%d ", n);
		
	for (int i = 0; i<n; i++){
		fscanf(arq_vertices, "%d", &type);
		for (int j = 0; j<n; j++){
			fscanf(arq_grafo, "%d", &aux);
			if (aux != 0){
				c++;
				soma += aux;

			}
		}
		ind = i;
//		printf("c = %d\n", c);
//		printf("teste = %d %d %d\n", ind, soma, c);
		Estrutura_Ocorrencia aux_i(ind,type,  soma, c);
		Ocorrencia.insert(aux_i);
		ind = 0;
		c = 0;
		soma = 0;
		type=0;
	}

	int v = -1, i = 0;
	fprintf(arq_print, "Ocorre = [");
	for (it = Ocorrencia.begin(), i = 0; it != Ocorrencia.end(); it++, i++){
		if (it->type != 0 && v == -1)
			v= i;
		
		fprintf(arq_print, "%d-%d, ", it->ocorre, it->indice);
		printf("%d-%d\n", it->ocorre, it->indice);
	}
	fprintf(arq_print, "];");

	fprintf(arq_print_b, "%d ", v);

	for (it = Ocorrencia.begin(), i = 0; it != Ocorrencia.end(),i<v; it++, i++)
		fprintf(arq_print_b, "%d %d ", it->ocorre, it->indice);
	
	Ocorrencia.clear();


	fclose(arq_grafo);
	fclose(arq_vertices);
	fclose(arq_print);
	fclose(arq_print_b);

//	printf("ok\n");
} 

