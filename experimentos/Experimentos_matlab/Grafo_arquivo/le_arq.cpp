#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	char *arquivo = argv[1];
	int n=0, aux=0, c=0;
	

	FILE *arq_grafo = fopen(arquivo, "rb");
	fscanf(arq_grafo, "%d ", &n);
	
	int Ocorrencia[n];

	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			fscanf(teste, "%d ", &aux);
			if (aux != 0)
				c++;
		}
		Ocorrencia[i] = c;
	}

	fclose(arq_grafo);

	return 0;
}