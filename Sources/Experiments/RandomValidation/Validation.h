#ifndef VALIDATION_H
#define VALIDATION_H

#include <Utilities/SunDatabaseReader.hpp>
#include <Utilities/DatabaseReader.hpp>
#include <Utilities/SupervisedImage.hpp>
#include <FeatureExtractors/Region.hpp>
#include <Utilities/FeaturesComplexNetwork.hpp>
#include <Utilities/RandomWalk.hpp>
#include <FeatureExtractors/LabelFeatureFactory.hpp>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv/cxcore.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <string.h>
#include <vector>
#include <time.h>
#include <assert.h>
#include "RandomImages.h"
#include "RandomReader.h"
#include "RandomRegionReader.h"
#include <Experiments/Graph/Vertice.h>
#include <Experiments/Graph/Label.h>
#include <Experiments/Graph/Histograma.h>
#include <Experiments/Graph/Graph.h>
#include <Experiments/Graph/OcorrenciaGrafo.h>
#include <Experiments/Graph/GraphConstructor.h>

//histograma 1
//area 2
//orientacao 3

using namespace std;

//type 1 -> characteristics (HSV,AREA, ORIENTACAO)
template<typename type1>
class Validation{
public:
	class Vert{
	public:
		int ocorre;
		string label;
		bool operator < (const Vert &other)const;
		Vert(string, int);
	};
private:
	vector<Vert> adj;
	vector<int>notas;
	Graph<Label, type1> &Grafo;
	RandomRegionReader &regions;
	int type;
	int H, S, V, Y;
public:
	int daNota(vector<Vert>, string);
	Validation(Graph<Label, type1> &, RandomRegionReader &, int, int, int, int, int);
	void print(string);
	void print();
	void build();
};

template<typename type1>
bool Validation<type1>::Vert:: operator < (const Vert &other)const{
	return (this->ocorre > other.ocorre);
}

template<typename type1>
Validation<type1>::Vert::Vert(string label, int o) :label(label), ocorre(o){
}

template<typename type1>
int Validation<type1>::daNota(vector<Vert>adj, string rLabel){
	for (int i = 0; i < adj.size(); i++){
		//printf("%s == %s\n", adj[i].label.c_str(), rLabel.c_str());
		if (adj[i].label == rLabel)
			return i + 1;
	}
	return -1;
}

template<typename type1>
Validation<type1>::Validation(Graph<Label, type1> &Grafo, RandomRegionReader &regions, int type, int H, int S, int V, int Y):Grafo(Grafo),regions(regions), type(type), H(H),S(S),V(V),Y(Y){
}

template<typename type1>
void Validation<type1>::build(){
	vector<Vertice*> indice = Grafo.getIndice();
	vector <vector<int> > matriz = Grafo.getMatriz();
	printf("matriz.size() = %d\n", matriz.size());
	printf(this->regions.hasNextRegion() ? "has next\n" : "Doesnt have next\n");

	while (regions.hasNextRegion()){
		ChoosedRegion r = regions.readNextRegion();
		SupervisedImage img = r.readNextSupervisedImage();
		int rc = r.regionChoosed;
		printf("rc = %d\n", rc);
		
		Mat image = imread(img.getImagePath().toStdString());
		cvtColor(image, image, CV_BGR2HSV_FULL);
		Mat mask = img.getRegions()[rc].getMask();

		string label = img.getRegions()[rc].getLabel().toStdString();
		
		type1 crt;
		if (this->type == 1)
			crt = type1(image, mask, H, S, V, rc, label, Y);
		
		printf("Procura\n");
		int in = Grafo.finding(crt);
		printf("in = %d\n", in);
		
		if (in > 0){
			for (int i = 0; i < matriz[in].size(); i++){
				if (matriz[in][i] != 0){
					int oco = matriz[in][i];
					string l = ((Label*)indice[i])->getLabel();
					adj.push_back(Vert(l, oco));
				}
			}
			sort(adj.begin(), adj.end());
			printf("adj = \n");
			for (int i = 0; i < adj.size(); i++)
				printf("Ocorre: %d - Label:%s\n", adj[i].ocorre, adj[i].label.c_str());
			notas.push_back(daNota(adj, label));
			printf("Nota = %d\n", daNota(adj, label));
		}
		else
			notas.push_back(-1);
	}
}

template<typename type1>
void Validation<type1>::print(string p_arq){
	FILE *arquivo = fopen(p_arq.c_str(), "w");
	
	for (int i = 0; i < this->notas.size(); i++)
		fprintf(arquivo, "%d\n", notas[i]);

	fclose(arquivo);
}

template<typename type1>
void Validation<type1>::print(){
	for (int i = 0; i < this->notas.size(); i++)
		printf("%d\n", notas[i]);

}

#endif
