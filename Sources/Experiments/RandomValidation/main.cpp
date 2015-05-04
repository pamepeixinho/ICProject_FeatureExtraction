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

using namespace std;

class Vert{
public:
	int ocorre;
	string label;
	bool operator < (const Vert &other){
		return (this->ocorre > other.ocorre);
	}
	Vert(string label, int o):label(label), ocorre(o){
	}
};

int daNota(vector<Vert>adj,string rLabel){
	for (int i = 0; i < adj.size();i++)
		if (adj[i].label == rLabel)
			return i+1;
}

int main(int argc, char *argv[])
{
	
	if (argc != 2){
		printf("TYPE (HSV, Area, Orientacao)\n");
		return 0;
	}

	char *type  = argv[1];
	string type_path(type);
	//string path = "../../../experimentos/AvaliacaoRandom/"+ type_path + "/";
	string path = "../../AvaliacaoRandom/" + type_path + "/";
	printf("sun\n");

	SunDatabaseReader sunreader("/home/pamela/SUN2012/");
	//SunDatabaseReader sunreader("C:/Users/pamela/Documents/IC/Study/project1/SUN2012_COMPLETA/SUN2012/");

	printf("random image\n");
	RandomImages a(sunreader);
	printf("leu-printa\n");
	a.print(path);

	vector<string>img;
	vector<string>sup;
	a.getReaderChoosen(img, sup);

	printf("Img.size = %d e Sup.size() = %d\n", img.size(), sup.size());
	
	//system("pause");

	//RandomReader reader(path + "ImagesChoosen.bin");
	RandomReader reader(img,sup);

	printf("ok!\n");

	printf(reader.hasNext() ? "has next\n" : "Doesnt have next\n");

	//system("pause");

	string v_s(path+"Vertices");
	string g_s(path+"Grafo");
	printf("%s %s\n",v_s.c_str(), g_s.c_str());

	char *v;
	strcpy(v, v_s.c_str());

	char *g; 
	strcpy(g, g_s.c_str());
	printf("%s %s\n", v, g);
		
	//GraphConstructor<Label, Hsv_DiscrY> constructor(reader, v, g, 18, 3,3, 4);
	//printf("graph\n");
	//Graph<Label, Hsv_DiscrY> Grafo;
	//constructor.build_g(Grafo);
	//set<unique_ptr<Vertice>> Vertices = Grafo.getVertices();
	//vector<Vertice*> indice = Grafo.getIndice();
	//vector <vector<int> > matriz = Grafo.getMatriz();
	//RandomRegionReader regions(path+"Others.bin");
	//vector<Vert> adj;
	//vector<int>notas;
	//while (regions.hasNextRegion()){
	//	ChoosedRegion r = regions.readNextRegion();
	//	SupervisedImage img  = r.readNextSupervisedImage();
	//	int rc = r.regionChoosed;
	//	Mat image = imread(img.getImagePath().toStdString());
	//		cvtColor(image, image, CV_BGR2HSV_FULL);
	//	Mat mask = img.getRegions()[rc].getMask();
	//	string label = img.getRegions()[rc].getLabel().toStdString();
	//	Hsv_DiscrY hsv = Hsv_DiscrY(image, mask, 18, 3, 3, 1, "", 4);
	//	set<unique_ptr<Vertice>>::iterator it_h = Vertices.find(unique_ptr<Vertice>(new Hsv_DiscrY(hsv)));
	//	printf(it_h != Vertices.end() ? "achou H\n" : "nao achou H\n");
	//	int in = it_h->get()->idx;
	//	for (int i = 0; i < matriz[in].size(); i++){
	//		if (matriz[in][i] != 0){
	//			int oco = matriz[in][i];
	//			string l = ((Label*) indice[i])->getLabel();
	//			adj.push_back(Vert(l, oco));
	//			notas.push_back(daNota(adj, label));
	//			printf("Nota = %d\n", daNota(adj, label));
	//		}
	//	}
	//}

	return 0;
}
