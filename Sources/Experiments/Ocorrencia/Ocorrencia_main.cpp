#include <cstdlib>
#include <cstdio>
#include <Experiments/Graph/OcorrenciaGrafo.h>

using namespace std;

int main (int argc, char *argv[]){

	printf("TYPE_OF_OCORRENCIA: 1-Ocorrencia Simples 2-Ocorrencia + indices\n");
	
	if(argc!=5)
		printf("TYPE_OF_OCORRENCIA vertice.bin  grafo.bin ocorrencia(sem extensao)\n");

	if(atoi(argv[1])==1)
		OcorrenciaH_Grafo(argv[2], argv[3], argv[4]);
	else if(atoi(argv[1])==2)
		OcorrenciaVert_Grafo(argv[2], argv[3], argv[4]);


//	char ocorrencia[50];

//	printf("Ok!\n");

	return 0;
}
