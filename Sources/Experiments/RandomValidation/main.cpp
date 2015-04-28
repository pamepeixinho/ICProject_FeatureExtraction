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
#include <Experiments/Graph/Vertice.h>
#include <Experiments/Graph/Label.h>
#include <Experiments/Graph/Histograma.h>
#include <Experiments/Graph/Graph.h>
#include <Experiments/Graph/OcorrenciaGrafo.h>
#include <Experiments/Graph/GraphConstructor.h>

using namespace std;

int main(int argc, char *argv[])
{
	printf("Lets Start\n");
	char *type  = argv[1];
	string type_path(type);
	string path = "../../experimentos/AvaliacaoRandom/"+ type_path + "/";
	printf("sun\n");
	SunDatabaseReader sunreader("/home/pamela/SUN2012/");
	printf("random image\n");
	RandomImages a(sunreader);
	printf("leu-printa\n");
	a.print(path);
	printf("path = %s", path.c_str());
	printf("printou\nreader\n");
	printf("path = %s", path.c_str());
	RandomReader reader(path + "ImagesChoosen.bin");
	printf("ok!\n");
	string v_s(path+"Vertices");
	string g_s(path+"Grafo");
//	printf("%s %s\n",v_s.c_str(), g_s.c_str());
	char *v;
	strcpy(v, v_s.c_str());
	char *g; 
	strcpy(g, g_s.c_str());
//	printf("%s %s\n", v, g);
//	char v[20];
//	char g[20];
	Graph<Label, Hsv_DiscrY> Grafo;	
	GraphConstructor<Label, Hsv_DiscrY> constructor(reader, v, g, 18, 3,3, 4);
	printf("graph\n");
	Grafo =	constructor.build_g();

//	RandomRegionReader regions(path+"Others.bin");
			

	return 0;
}
