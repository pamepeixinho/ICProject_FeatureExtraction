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
#include "Validation.h"

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
	
	if (argc == 1){
		printf("TYPE (HSV, Area, Orientacao)\n");
		return 0;
	}
	char *type  = argv[1];

	if (strcmp(type,"HSV")==0){
		if (argc != 11){
			printf("path_SUN path nomeVertice nomeGrafo nomeSaida.txt (H)0 (S)0 (V)0 (Y)0\n");
			return 0;
		}
	}

//C:/Users/pamela/Documents/IC/Study/project1/SUN2012_COMPLETA/SUN2012_TESTE/
//C:/Users/pamela/Dropbox/IC-Pamela1/Projeto/ICProject_FeatureExtraction/experimentos/AvaliacaoRandom/HSV/

	string path(argv[3]);
	char *pathc = argv[3];
	
	QString path_SUN(argv[2]);

	int H = atoi(argv[7]);
	int S = atoi(argv[8]);
	int V = atoi(argv[9]);
	int Y = atoi(argv[10]);
	printf("%d %d %d %d\n", H, S, V, Y);

	SunDatabaseReader sunreader(path_SUN);

	RandomImages a(sunreader);
	a.print(path);

	vector<string>image_path;
	vector<string>sup;
	a.getReaderChoosen(image_path, sup);

	vector<string>imageC;
	vector<string>supC;
	a.getReader(imageC, supC);


	printf("Img.size = %d e Sup.size() = %d\n", image_path.size(), sup.size());
	printf("ImgC.size = %d e SupC.size() = %d\n", imageC.size(), supC.size());

	string Sgrafo = path + string(argv[5]);
	string Svertice = path + string(argv[4]);

	char *v = new char[Svertice.length() + 1];
	memcpy(v, Svertice.c_str(), Svertice.length() + 1);
	char *g = new char[Sgrafo.length() + 1];
	memcpy(g, Sgrafo.c_str(), Svertice.length() + 1);

	printf("Vertice = %s e Grafo = %s\n", v, g);

	RandomReader reader(image_path,sup);
	printf(reader.hasNext() ? "reader has next\n" : "reader Doesnt have next\n");

	Graph<Label, Hsv_DiscrY> Grafo;
	GraphConstructor<Label, Hsv_DiscrY> constructor(reader, v, g, H, S, V, Y);
	constructor.build_g(Grafo);
	printf("graph constructor\n");

	RandomRegionReader regions(imageC, supC);
	printf(regions.hasNextRegion() ? "regions has next\n" : "regions Doesnt have next\n");

	int tipo = 0;

	if (strcmp(type, "HSV") == 0)
		tipo = 1;

	Validation<Hsv_DiscrY> validation(Grafo, regions, tipo, H, S, V, Y);
	validation.build();
	printf("VALIDATION - BUILD\n");
	validation.print(strcat(pathc,argv[6]));
	printf("FPRINTF\n");
	validation.print();
	printf("PRINTF\n");

	return 0;
}
