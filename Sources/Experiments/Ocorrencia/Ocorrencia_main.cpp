#include <cstdlib>
#include <cstdio>
#include <Experiments/Graph/OcorrenciaGrafo.h>

using namespace std;

int main (int argc, char *argv[]){

	if(argc!=4)
		printf("(arquivos) vertice grafo ocorrencia\n");

//	char ocorrencia[50];
//	OcorrenciaH_Grafo(argv[1], argv[2], argv[3]);
	OcorrenciaVert_Grafo(argv[1], argv[2], argv[3]);

//	printf("Ok!\n");

	return 0;
}
