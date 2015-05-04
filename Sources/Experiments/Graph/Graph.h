#ifndef GRAPH_H
#define GRAPH_H

//#include <Experiments/Graph/Vertice.h>
#include <Experiments/Graph/Label.h>
#include <Experiments/Graph/Histograma.h>
#include <vector>
#include <iostream>
#include <memory>
#include <cstdlib>
#include <string.h>
#include <set>
#include <assert.h>

using namespace std;

template<typename type1, typename type2>
class Graph{
	set<unique_ptr<Vertice>> Vertices;
	vector<Vertice*>indice;
	vector<vector<int> >Matriz_Adjacencia;
public:
	set<unique_ptr<Vertice>> getVertices(){
		return this->Vertices;
	}
	vector<Vertice*> getIndice(){
		return this->indice;
	}
	vector<vector<int> > getMatriz(){
		return this->Matriz_Adjacencia;
	}
	void printVertices(char *);
	void printGraph(char *);
	void ConstructEdges(type1, type2);
	void loadGraph(char *,char*,char*);
	int finding(type2 h);
	//void ConstructEdges(Label, Hsv_DiscrY);
};

bool operator<(const unique_ptr<Vertice> &a, const unique_ptr<Vertice> &b){
	return *a < *b;
}

char v[60];
char aux[60];

template<typename type1, typename type2>
int Graph<type1, type2>::finding(type2 h){
	set<unique_ptr<Vertice>>::iterator it_h = Vertices.find(unique_ptr<Vertice>(new type2(h)));
	return it_h->get()->idx;
}

template<typename type1, typename type2>
void Graph<type1, type2>::printVertices(char *arquivo_vertices){
	strcpy(v, arquivo_vertices);
	strcpy(aux, arquivo_vertices);

	FILE *arq_g = fopen(strcat(v, ".txt"), "w"), *arq_gb = fopen(strcat(aux, "_ordem.bin"), "wb");

	vector<int>HistogramaI;
	vector<float>HistogramaF;

	for (int i = 0; i < indice.size(); i++){
		fprintf(arq_g, "[%d] = ", i);
		if (indice[i]->getType() == 2){
			fprintf(arq_gb, "1 ");
			HistogramaI = ((Hsv_DiscrY*)indice[i])->getHist_y();
			for (int j = 0; j < HistogramaI.size(); j++)
				fprintf(arq_g, "%d ", HistogramaI[j]);
		}
		else if (indice[i]->getType() == 1){
			fprintf(arq_gb, "1 ");
			HistogramaF = ((Hsv_Dist*)indice[i])->getHistDist();
			for (int j = 0; j < HistogramaF.size(); j++)
				fprintf(arq_g, "%.2f ", HistogramaF[j]);
		}
		else {
			fprintf(arq_gb, "0 ");
			fprintf(arq_g, "%s", ((Label*)indice[i])->getLabel().c_str());
		}

		fprintf(arq_g, "\n");
	}

	fclose(arq_g);
	fclose(arq_gb);
}

template<typename type1, typename type2>
void Graph<type1, type2>::printGraph( char *arquivo_grafo){
	char L = 'L';
	char H = 'H';

	strcpy(v, arquivo_grafo);
	strcpy(aux, arquivo_grafo);

	FILE *arq_g = fopen(strcat(aux, ".txt"), "w");
	FILE *arq_gb = fopen(strcat(v, ".bin"), "wb");


	fprintf(arq_g, "Matriz: %d\n\n", Matriz_Adjacencia.size());
	fprintf(arq_gb, "%d ", Matriz_Adjacencia.size());

	for (int i = 0; i < Matriz_Adjacencia.size(); i++){
		fprintf(arq_g, "%d-%c\t", i, indice[i]->getType() == 1 ? H : L);
		for (int j = 0; j < Matriz_Adjacencia.size(); j++){
			fprintf(arq_g, " %d ", Matriz_Adjacencia[i][j]);
			fprintf(arq_gb, "%d ", Matriz_Adjacencia[i][j]);
		}
		fprintf(arq_g, "\n");
		fprintf(arq_gb, "\n");
	}

	fclose(arq_g);
	fclose(arq_gb);
}

template<typename type1, typename type2>
void Graph<type1, type2>::ConstructEdges(type1 label, type2 hist){

	bool it_b;
	set<unique_ptr<Vertice>>::iterator it_l = Vertices.find(unique_ptr<Vertice>(new type1(label)));
	printf("passou find label\n");
	printf(it_l != Vertices.end() ? "achou L\n" : "nao achou L\n");

	//set<unique_ptr<Vertice>>::iterator it_h = Vertices.find(unique_ptr<Vertice>(new Hsv_DiscrY(h)));
	set<unique_ptr<Vertice>>::iterator it_h = Vertices.find(unique_ptr<Vertice>(new type2(hist)));
	printf("passou find Hist\n");
	printf(it_h != Vertices.end() ? "achou H\n" : "nao achou H\n");

	std::pair<std::set<unique_ptr<Vertice>>::iterator, bool> insert_result;

	if (it_l == Vertices.end()){
		printf("Entrei para criar Label\n");
		unique_ptr<Vertice> new_l(new type1(label));
		new_l->idx = indice.size();
		insert_result = Vertices.insert(move(new_l));
		it_l = insert_result.first;
		it_b = insert_result.second;
		indice.push_back(it_l->get());
		printf(it_b ? "cria vertice L\n" : "Erro ao criar\n");

		Matriz_Adjacencia.resize(Matriz_Adjacencia.size() + 1);
		for (int i = 0; i < Matriz_Adjacencia.size(); i++)
			Matriz_Adjacencia[i].resize(Matriz_Adjacencia.size(), 0);
	}


	if (it_h == Vertices.end()){
		printf("Entrei para criar Hist**************\n");
		unique_ptr<Vertice> new_h(new type2(hist));
		//unique_ptr<Vertice> new_h(new Hsv_DiscrY(h));
		new_h->idx = indice.size();
		insert_result = Vertices.insert(move(new_h));
		it_h = insert_result.first;
		it_b = insert_result.second;
		indice.push_back(it_h->get());
		printf(it_b ? "cria vertice H\n" : "Erro ao criar\n");

		Matriz_Adjacencia.resize(Matriz_Adjacencia.size() + 1);
		for (int i = 0; i < Matriz_Adjacencia.size(); i++)
			Matriz_Adjacencia[i].resize(Matriz_Adjacencia.size(), 0);
	}

	//cout << Matriz_Adjacencia.size() << endl;
	printf("iH =%d   iL = %d\n\n", it_h->get()->idx, it_l->get()->idx);
	Matriz_Adjacencia[it_h->get()->idx][it_l->get()->idx] += 1;
	Matriz_Adjacencia[it_l->get()->idx][it_h->get()->idx] += 1;
}


//label 0
//histograma 1
template<typename type1, typename type2>
void Graph<type1, type2>::loadGraph(char *vert, char *vertb,char * grafo){
//vert.txt && vert_ordem.bin
//grafo.bin

	std::pair<std::set<unique_ptr<Vertice>>::iterator, bool> insert_result;
	bool it_b;
	int aux2,ordem;
	int type;
	char linha[200];
	char aux[400];
	FILE *arq_vert = fopen(vert, "r");
	assert(arq_vert!=NULL);
	FILE *arq_vert_ordem = fopen(vertb, "rb");
	assert(arq_vert_ordem!=NULL);
	FILE *arq_grafo = fopen(grafo,"rb");
	assert(arq_grafo!=NULL);

	
	set<unique_ptr<Vertice>>::iterator it_l;
	set<unique_ptr<Vertice>>::iterator it_h;
//alimenta vertices
	while(!feof(arq_vert)){
		fscanf(arq_vert_ordem, "%d", &type);
		fgets(linha,400,arq_vert);
		sscanf(linha, "[%d] = ", &aux2);	 
		if(!feof(arq_vert)){
				char *ch = strchr(linha, '=');
				strcpy(aux, ch+2);
			printf("aux = %s\n", aux);
			if(type==0){
				unique_ptr<Vertice> new_l(new type1(aux));
				new_l->idx = indice.size();
				insert_result = Vertices.insert(move(new_l));
				it_l = insert_result.first;
				it_b = insert_result.second;
				indice.push_back(it_l->get());
			}
			else if(type==1){
				vector<int>hist;
				for(int i=0;aux[i]!='\0';i++){
					hist.push_back(atoi((char*)aux[i]));
				}

				printf("Hist = ");
				for(int i=0;i<hist.size();i++)
					printf("%d ", hist[i]);
				printf("\n");

				unique_ptr<Vertice> new_h(new type2(hist));
				new_h->idx = indice.size();
				insert_result = Vertices.insert(move(new_h));
				it_h = insert_result.first;
				it_b = insert_result.second;
				indice.push_back(it_h->get());
			}
			
		}	
	}
//alimenta Grafo
	fscanf(arq_grafo,"%d",&ordem);
	int aux_matriz;
	Matriz_Adjacencia.resize(ordem);
	for(int i=0;i<ordem;i++){
		for(int j=0;j<ordem;j++){
			fscanf(arq_grafo, "%d",&aux_matriz); 
			Matriz_Adjacencia[i][j]=aux_matriz;
		}
	}

	fclose(arq_vert);
	fclose(arq_vert_ordem);
	fclose(arq_grafo);
}

#endif
