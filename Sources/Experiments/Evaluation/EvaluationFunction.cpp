#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


int main(int argc, char *argv[]){

	if(argc != 7)
		printf("arquivo_Ocorrencia resultado H S V Y\n");

	int h = atoi(argv[3]), s = atoi(argv[4]), v= atoi(argv[5]), y = atoi(argv[6]);
	FILE *arquivo = fopen(argv[1],"rb");
	FILE *arq_result = fopen(argv[2],"w");	

	int aux=0, n=0;
	 int num=0, hist= 0, somatoria=0;

	
	fscanf(arquivo, "%d", &num);
	fscanf(arquivo, "%d", &hist);

	vector<int>Ocorrencia(num-hist);
	for(int i=0;i<num && i<hist;i++){
		fscanf(arquivo, "%d", &aux);	
		Ocorrencia.push_back(aux);
		somatoria+=aux;
	}

	float media  = somatoria/(h*s*v*y);
	float  desvio=0;

	fprintf(arq_result,"media = %.2f\n",media);

	
	for(int i=0;i<Ocorrencia.size();i++){
		desvio += pow((Ocorrencia[i] - media),2);
	}

	float desvio_padrao =sqrt(desvio/Ocorrencia.size());
	fprintf(arq_result,"desvio padrao = %.2f\n",desvio_padrao);

	fclose(arquivo);
	fclose(arq_result);

	return 0;
}
