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
	string path = "../../../experimentos/RandomWalk/";
	SunDatabaseReader sunreader("/home/pamela/SUN2012/");
	RandomImages a(sunreader);
	a.print(path);
	RandomReader reader(path + "arqHSV_ImagesChoosen.bin");
	
//	char *v = (path+"Vertices").c_str();
//	char *g = (path+"Grafo").c_str();
//	char v[20];
//	char g[20];
	
//	GraphConstructor<Label, Hsv_DiscrY> constructor(reader, v, g, 18, 3,3, 4);

//	constructor.build();


	return 0;
}
