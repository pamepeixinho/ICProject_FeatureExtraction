//#include <stdlib.h>
//#include <stdio.h>
//#include <iostream>
//#include <set>
//#include <string.h>
//#include <assert.h>
//
//using namespace std;
//
//class Estrutura_Ocorrencia{
//public:
//	int indice;
//	int soma;
//	int ocorre;
//	Estrutura_Ocorrencia(const int ind, const int som, const int oco):indice(ind), soma(som), ocorre(oco){}
//};
//
//bool operator < (const Estrutura_Ocorrencia& a, const Estrutura_Ocorrencia& b){
//	return (a.indice) < (b.indice);
//}
//
//int main(int argc, char *argv[]){
//
//	multiset<Estrutura_Ocorrencia>Ocorrencia;
//	multiset<Estrutura_Ocorrencia>::iterator it;
//
//	if (argc != 4)
//		printf("Entrada Comando:\n(Arquivo Vertice) (Arquivo Grafo) (Arquivo Saida)\n");
//
//	char *arquivo_g = argv[2], *arquivo_v = argv[1], *arquivo_p = argv[3], printar[20];
//	int n = 0, aux = 0, c = 0, soma = 0, ind = 0;
//	
//	printf("%s\n", arquivo_p);
//	strcpy(printar, strcat(arquivo_p, ".m"));
//	printf("%s\n", printar);
//	//FILE *arq_print = fopen("SAIDA.m", "w");
//	//FILE *arq_print = fopen(strcat(arquivo_p, ".m"), "w");
//	FILE *arq_print = fopen(printar, "w");
//	
//	FILE *arq_grafo = fopen(strcat(arquivo_g, ".bin"), "rb");
//	assert(arq_grafo != NULL);
//
//	FILE *arq_vertices = fopen(strcat(arquivo_v, "_ordem.bin"), "rb");
//	assert(arq_vertices != NULL);
//	
//
//	//FILE *arq_print = fopen(strcat(arquivo_p, ".m"), "w");
//
//	fscanf(arq_grafo, "%d", &n);
//	fprintf(arq_print, "n = %d;\n", n);
//
//	for (int i = 0; i<n; i++){
//		fscanf(arq_vertices, "%d", &ind);
//		for (int j = 0; j<n; j++){
//			fscanf(arq_grafo, "%d", &aux);
//			if (aux != 0){
//				c++;
//				soma += aux;
//
//			}
//		}
//		//printf("c = %d\n", c);
//		//printf("teste = %d %d %d\n", ind, soma, c);
//		Estrutura_Ocorrencia aux_i(ind, soma, c);
//		Ocorrencia.insert(aux_i);
//		c = 0;
//		soma = 0;
//	}
//
//	int v = 0, i = 0;
//	fprintf(arq_print, "Ocorre = [");
//	for (it = Ocorrencia.begin(), i = 0; it != Ocorrencia.end(); it++, i++){
//		if (it->indice != 0 && v == 0)
//			v = i;
//		fprintf(arq_print, "%d ", it->ocorre);
//	}
//	fprintf(arq_print, "];\n");
//
//	fprintf(arq_print, "indice_Hist = %d;\n", v);
//
//	fclose(arq_grafo);
//	fclose(arq_vertices);
//	fclose(arq_print);
//
//	return 0;
//}


//#include "AnaliseGrafo.h"

int main(){
//	OcorrenciaH_Grafo("teste", "teste2", "teste3");
	return 0;
}