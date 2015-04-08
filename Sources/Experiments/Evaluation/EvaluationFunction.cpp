#include <set>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Ocorrencia_Label{
public:
	int indice;
	int ocorrencia;
	bool operator < (const Ocorrencia_Label &other)const{
		return (this->ocorrencia < (other.ocorrencia));
	}

	Ocorrencia_Label(int indice, int o):indice(indice), ocorrencia(o){}
};

char * buscaLabel(char *arq, int n){
	
	char aux1, aux3;
	char *label;
	int aux2;

	FILE *arq_vertice = fopen(arq,"r");
	while(!feof(arq_vertice)){
		fscanf(arq_vertice, "%c %d %c", &aux1, &aux2, &aux3);
		if(!feof(arq_vertice)){
			if(aux1=='[' && aux2==n && aux3 == ']'){
				fscanf(arq_vertice, "%s", label);
				return label;
			}
		}
	}
}

int main(int argc, char *argv[]){

	if(argc != 8)
		printf("arquivo_Ocorre arquivo_vertice arquivo_resultado H S V Y\n");

	int h = atoi(argv[4]), s = atoi(argv[5]), v= atoi(argv[6]), y = atoi(argv[7]);
	FILE *arquivo = fopen(argv[1],"rb");
	FILE *arq_result = fopen(argv[3],"w");	
	char *arq = argv[3];
	int aux=0, n=0, aux2=0;
	 int num=0, hist= 0, somatoria=0;

	
	fscanf(arquivo, "%d", &num);
	//fscanf(arquivo, "%d", &hist);

	set<Ocorrencia_Label>Ocorre;
	set <Ocorrencia_Label>::iterator it;

	for(int i=0;i<num;i++){
		fscanf(arquivo, "%d %d", &aux, &aux2);	
		Ocorrencia_Label t(aux2, aux);
		Ocorre.insert(t);
		somatoria+=aux;
	}

	float media  = somatoria/num;
	float  desvio=0;

	fprintf(arq_result,"media = %.2f\n",media);

	
	for (it = Ocorre.begin(); it != Ocorre.end(); it++){
		desvio += pow((it->ocorrencia - media),2);
	}

	float desvio_padrao =sqrt(desvio/Ocorre.size());
	fprintf(arq_result,"desvio padrao = %.2f\n",desvio_padrao);
	int i=0;
	fprintf(arq_result, "TOP 10\n\nMENOS CO-OCORRERAM\n");
	for (it = Ocorre.begin(), i=0; it != Ocorre.end(), i<10; it++, i++){
		//menos co-ocorreram com outro hist
		int n = it->indice;
		printf("%d- %s\n", i, buscaLabel(arq, n));
	}
	printf("\n");


	int nl10 = Ocorre.size() - 10;
	fprintf(arq_result,"MAIS CO-OCORRERAM\n");
	for (it = Ocorre.end(), i=0; it != Ocorre.begin(), i<10; it--, i++){
		int n = it->indice;
		fprintf(arq_result,"%d- %s\n", i, buscaLabel(arq, n));
	
	}

	fclose(arquivo);
	fclose(arq_result);

	return 0;
}
