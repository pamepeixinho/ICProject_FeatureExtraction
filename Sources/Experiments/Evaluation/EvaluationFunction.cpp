//EVALUATION OF LABEL
//media e top 10 de LABEL

#include <set>
#include <cstdlib>
#include <string.h>
#include <cstdio>
#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>

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

char *  buscaLabel(char *arq, int n){
	int aux2=0; 	
	FILE *arq_vertice = fopen(arq,"r");
	char linha[400];
	 char label[100];
	while(!feof(arq_vertice)){
		fgets(linha,400,arq_vertice );
		sscanf(linha, "[%d] = ", &aux2); 
		if(!feof(arq_vertice)){
			if(aux2==n){
				printf("%s\n\n",linha);
				char *ch = strchr(linha, '=');
				strcpy(label, ch+2);
				return label;
			}
		}		
				
	
	}
}

void MediaSimples(char *oc, char *res ){

	FILE *arquivo = fopen(oc,"rb");
	FILE *arq_result = fopen(res,"w");	
	int num=0, hist=0, aux=0, somatoria = 0;
	fscanf (arquivo, "%d %d", &num, &hist);
//	printf("%d %d\n", num, hist);	
	for(int i=0;i<hist;i++){
		fscanf(arquivo, "%d", &aux);		
		somatoria+=aux;
//		printf("i=%d, aux=%d, somatoria=%d\n", i, aux, somatoria);
	}

	double media = somatoria/(hist-1);
	double media2 = somatoria/(num-hist);
	printf("media1 = %.2lf\n\n", media);
	fprintf(arq_result,"media1 = %.2lf\n",media);
	printf("media2 = %.2lf\n\n", media2);
	fprintf(arq_result,"media2 = %.2lf\n",media2);
	fclose (arquivo);
	fclose(arq_result);

}

void Media_Top10(char *oc, char *res, char *arq){

	FILE *arquivo = fopen(oc,"rb");
	FILE *arq_result = fopen(res,"w");	
//	char *arq = argv[3];
	int aux=0, n=0, aux2=0;
	 int num=0, hist= 0, somatoria=0;


	fscanf(arquivo, "%d", &num);
	//fscanf(arquivo, "%d", &hist);

	set<Ocorrencia_Label>Ocorre;
	set <Ocorrencia_Label>::iterator it;

	printf("%d\n", num);

	for(int i=0;i<num;i++){
		fscanf(arquivo, "%d %d", &aux, &aux2);	
		Ocorrencia_Label t(aux2, aux);
		Ocorre.insert(t);
		somatoria+=aux;
		if(aux2==248)
			printf("aqui\n");
	}

	float media  = somatoria/num;
	float  desvio=0;

	fprintf(arq_result,"media = %.2f\n",media);

	for (it = Ocorre.begin(); it != Ocorre.end(); it++){
		desvio += pow((it->ocorrencia - media),2);
//		printf("ind %d  - oco %d\n", it->indice, it->ocorrencia);
	}

	float desvio_padrao =sqrt(desvio/Ocorre.size());
	fprintf(arq_result,"desvio padrao = %.2f\n",desvio_padrao);
	int i=0;
	fprintf(arq_result, "\n\tTOP 10\nMENOS CO-OCORRERAM\n");
	for (it = Ocorre.begin(), i=0; it != Ocorre.end(), i<10; it++, i++){
		//menos co-ocorreram com outro hist
		n  = it->indice;
		fprintf(arq_result, "%d- %s\n", i+1, buscaLabel(arq, n));
	}
	printf("\n");


//	int nl10 = Ocorre.size() - 10;
	fprintf(arq_result,"MAIS CO-OCORRERAM\n");
	for (it = Ocorre.end()--, i=0; it != Ocorre.begin(), i<11; it--, i++){
		int n = it->indice;
		if(i!=0){	
			printf("%d %d\n", i, n);
			fprintf(arq_result,"%d- %s %d\n", i, buscaLabel(arq, n), it->ocorrencia);
		}
	
	}

	fclose(arquivo);
	fclose(arq_result);



}

int main(int argc, char *argv[]){

	printf("TYPE_OF_EVALUATION: 1-Media Simples 2-Media,Desvio P., Top10\n");

	if(atoi(argv[1])==2 && argc != 5){
		printf("TYPE_OF_EVALUATION arquivo_Ocorre.extensao  arquivo_vertice.extensao arquivo_resultado.extensao\n");
		return 0;
	}
	else if(atoi(argv[1])==1 && argc != 4){
		printf("TYPE_OF_EVALUATION arquivo_Ocorre.extensao  arquivo_resultado.extensao\n");
		return 0;
	}	

	if(atoi(argv[1])==1)
		MediaSimples(argv[2], argv[3]);
	else if(atoi(argv[1])==2){
		Media_Top10(argv[2], argv[4], argv[3]);
	}

	return 0;
}
