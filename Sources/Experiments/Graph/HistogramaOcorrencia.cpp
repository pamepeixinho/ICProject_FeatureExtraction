#include "HistogramaOcorrencia.h"
//#include <HistogramaOcorrencia.h>

Ocorrencia_Label::Ocorrencia_Label(const int indice, const vector<int> c, const float media):indice(indice), c(c),media(media){
}


int HistogramaOcorrencia::grau(int v){
	int grau = 0;
	for (int i = 0; i < Matriz[v].size(); i++)
		if (Matriz[v][i] != 0)
			grau++;
	return grau;
}

vector<int> HistogramaOcorrencia::grau_v(int v){
	int grau = 0;
	vector<int>ind_grau;
	for (int i = 0; i < Matriz[v].size(); i++)
		if (Matriz[v][i] != 0)
			ind_grau.push_back(i);
		
	return ind_grau;
}

bool HistogramaOcorrencia::compara(Ocorrencia_Label a, Ocorrencia_Label b){
	return (a.media < b.media);
}

char *  HistogramaOcorrencia::buscaLabel(char *arq, int n){
	int aux2 = 0;
	FILE *arq_vertice = fopen(arq, "r");
	char linha[400];
	char label[100];
	while (!feof(arq_vertice)){
		fgets(linha, 400, arq_vertice);
		sscanf(linha, "[%d] = ", &aux2);
		if (!feof(arq_vertice)){
			if (aux2 == n){
				printf("%s\n\n", linha);
				char *ch = strchr(linha, '=');
				strcpy(label, ch + 2);
				return label;
			}
		}


	}
}

HistogramaOcorrencia::HistogramaOcorrencia(char *vertice, char *vertice_b, char *grafo, char *arquivo_p){
	char print[150];
	char top1[150];
	strcpy(top1, arquivo_p);
	strcpy(print, arquivo_p);

	FILE *arq_grafo = fopen(grafo, "rb");
	//	printf("%s \n", arquivo_g);
	assert(arq_grafo != NULL);

	FILE *arq_vertices = fopen(vertice, "rb");
	//	printf("v - %s \n", arquivo_v);
	assert(arq_vertices != NULL);

	FILE *arq_print_b = fopen(strcat(print, "_MEDIA.txt"), "w");
	//	printf("p2 - %s \n",print);
	assert(arq_print_b != NULL);

	FILE *arq_print_t = fopen(strcat(top1, "_TOP.txt"), "w");
	//	printf("p2 - %s \n",print);
	assert(arq_print_b != NULL);

	int aux = 0, n = 0, type = 0;

	fscanf(arq_grafo, "%d", &n);

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			fscanf(arq_grafo, "%d", &aux);
			this->Matriz[i][j] = aux;
		}
	}

	vector<int> vi;
	int soma = 0, gl=0;
	float media = 0;
	for (int i = 0; i < n; i++){
		fscanf(arq_vertices, "%d", &type);
		if (type == 0){
			vi = grau_v(i);
			gl = vi.size();
			for (int j = 0; j < vi.size(); j++)
				soma += grau(vi[i]);
		}
		media = soma / (gl*1.0);
		Oco.push_back(Ocorrencia_Label(i, vi, media));
		vi.clear();
		soma = 0;
		media = 0;
	}

	for (int i = 0; i < Oco.size(); i++)
		fprintf(arq_print_b, "%d", Oco[i].media);

//	sort(Oco.begin(), Oco.end(), compara);

	for (int i = 0; i < 10; i++)
		top.push_back(buscaLabel(vertice_b, Oco[i].indice));

	for (int i = Oco.size() - 1; i > Oco.size() - 11;i--)
		down.push_back(buscaLabel(vertice_b, Oco[i].indice));

	fprintf(arq_print_b, "Top 10\n\nTop Menos CoOcorreram\n");

	for (int i = 0; i < top.size();i++)
		fprintf(arq_print_b, "%s", top[i]);

	fprintf(arq_print_b, "\n\nTop Mais CoOcorreram\n");
	for (int i = 0; i < top.size(); i++)
		fprintf(arq_print_b, "%s", down[i]);

	fclose(arq_grafo);
	fclose(arq_vertices);
	fclose(arq_print_t);
	fclose(arq_print_b);
}
