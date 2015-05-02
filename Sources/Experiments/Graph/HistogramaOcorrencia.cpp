#include "HistogramaOcorrencia.h"
//#include <HistogramaOcorrencia.h>

Ocorrencia_Label::Ocorrencia_Label(int indice, vector<int> c,float media):indice(indice), c(c){
	this->media = media;
	//cout << "media construtor = " << this->media << endl;
}

bool Ocorrencia_Label::operator < (const Ocorrencia_Label &other)const{
	return (this->media < other.media);
}

int HistogramaOcorrencia::grau(int v){
	return ocorre[v];
}

vector<int> HistogramaOcorrencia::grau_v(int v){
	int grau = 0;
	vector<int>ind_grau;
	for (int i = 0; i < Matriz[v].size(); i++)
		if (Matriz[v][i] != 0)
			ind_grau.push_back(i);
	//printf("grau_v.size() = %d\n", ind_grau.size());
	return ind_grau;
}

char *  HistogramaOcorrencia::buscaLabel(char *arq, int n){
	int aux2 = 0;
	FILE *arq_vertice = fopen(arq, "r");

	//printf("arq = %s\n", arq);
	char linha[400];
	char label[100];

	//for(int i=0;i<=ordem;i++){
	while (!feof(arq_vertice)){
		fgets(linha, 400, arq_vertice);
			sscanf(linha, "[%d] = ", &aux2);
			//printf("linha = %s e aux2 = %d e n = %d\n", linha, aux2, n);
			//printf("linha = %s\n", linha);
			if (!feof(arq_vertice) && aux2 == n){
				//printf("entrou\n aux==n\n");
				printf("linha certa = %s\n\n", linha);
				char *ch = strchr(linha, '=');
				strcpy(label, ch + 2);
				return label;
			}
	}

	fclose(arq_vertice);
	//return linha;
}

HistogramaOcorrencia::HistogramaOcorrencia(char *vertice, char *vertice_b, char *grafo, char *arquivo_p){
	char print[150];
	char top1[150];
	strcpy(top1, arquivo_p);
	strcpy(print, arquivo_p);

	FILE *arq_grafo = fopen(grafo, "rb");
	assert(arq_grafo != NULL);

	FILE *arq_vertices = fopen(vertice_b, "rb");
	assert(arq_vertices != NULL);

	FILE *arq_print_b = fopen(strcat(print, "_MEDIA.txt"), "w");
	assert(arq_print_b != NULL);

	FILE *arq_print_t = fopen(strcat(top1, "_TOP.txt"), "w");
	assert(arq_print_b != NULL);

	int aux = 0, n = 0, type = 0;

	printf("leu arquivos\n%s %s %s %s %s\n", grafo, vertice_b, print, top1, vertice);

	fscanf(arq_grafo, "%d", &n);
	cout <<n<< endl;
	
	Matriz.resize(n);
	ocorre.resize(n);
	int o=0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			fscanf(arq_grafo, "%d", &aux);
			this->Matriz[i].push_back(aux);
			if (aux != 0)
				o++;
		}
		ocorre[i] = o;
		o = 0;
	}
	printf("terminou matriz\n");
	vector<int> vi;
	int soma = 0, gl=0;
	float media = 0;

	for (int i = 0; i < n; i++){
		if (!feof(arq_vertices))
			fscanf(arq_vertices, "%d", &type);
		if (type == 0){
			vi = grau_v(i);
			gl = vi.size();
	
			for (int j = 0; j < vi.size(); j++){
				//printf("ocorre = %d\n", ocorre[vi[j]]);
				soma += ocorre[vi[j]];
			}

			media = soma /gl;
			//Ocorrencia_Label a = Ocorrencia_Label(i, vi, media);
			//Ocorrencia_Label *a = new Ocorrencia_Label(i, vi, media);
			float valor1 = media;
			Oco.push_back(Ocorrencia_Label(i, vi, valor1));
		}
		vi.clear();
		soma = 0;
		media = 0;
	}
	
	printf("alimentou o ocorrencias\n");
	//printf("oco size  = %d\n", Oco.size());

	/*for (int i = 0; i < Oco.size(); i++)
		printf("%d - %f\n", Oco[i].indice, Oco[i].media);*/

	for (int i = 0; i < Oco.size(); i++)
		fprintf(arq_print_b, "%.2f ", Oco[i].media);

	sort(Oco.begin(), Oco.end());

	//printf("-----------------sort----------------\n");

	//for (int i = 0; i < Oco.size(); i++)
	//	printf("%.2f\n", Oco[i].media);
	

	fprintf(arq_print_t, "--Top 10--\n\nTop Menor Media:\n");
	for (int i = 0; i < 10; i++){
		char *label = buscaLabel(vertice, Oco[i].indice);
		fprintf(arq_print_t, "%d) %s\n",i+1, label);
		top.push_back(label);
	}

	fprintf(arq_print_t, "Top Maior Media:\n");
	for (int i = Oco.size()-1,j=0; i > Oco.size()-11; i--, j++){
		char *label = buscaLabel(vertice, Oco[i].indice);
		fprintf(arq_print_t, "%d) %s\n", j+1, label);
		down.push_back(label);
	}


	fclose(arq_grafo);
	fclose(arq_vertices);
	fclose(arq_print_t);
	fclose(arq_print_b);
}
