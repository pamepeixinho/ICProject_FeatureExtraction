#include <Utilities/SunDatabaseReader.hpp>
#include <FeatureExtractors/Region.hpp>
#include <Utilities/FeaturesComplexNetwork.hpp>
#include <Utilities/RandomWalk.hpp>
#include <FeatureExtractors/LabelFeatureFactory.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2\core\mat.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv/cxcore.h>
#include <QList>
#include <cstdio>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
#include <opencv2\imgproc\imgproc.hpp>
#include <assert.h>
#include <set>
#include "Vertice.h"
#include "Label.h"
#include "Histograma.h"
#include <memory>
#include "Graph.h"
#include <Experiments\AnaliseGrafo\OcorrenciaGrafo.h>
#include "GraphConstructor.h"

//#define VALOR_COMP 0.25
//#define IND_LABEL 0
//#define IND_HIST_distancia 1
//#define IND_HIST_discretizacao 2

using namespace cv;
using namespace std;

//entrada prompt: (pasta)imagens\imagem (hsv)0 0 0 (K)0 (arquivos) Vertice Grafo
int main(int argc, char* argv[]){

	if (argc!=8){
		printf("\nEntrada de Argumentos:\n(pasta)imagens\imagem (h s v)0 0 0 (k || valor_comp)0 (arquivo_Vertice)Vertice (arquivo_Grafo)Grafo\n");
		return 0;
	}

	char *nomearquivo = argv[1],*arq_vertice = argv[6], *arq_grafo = argv[7];
	int arg_h = atoi(argv[2]), arg_s = atoi(argv[3]), arg_v = atoi(argv[4]), arg_K = atoi(argv[5]);
	
	printf("ARGUMENTOS: h%d s%d v%d k%d\n\n", arg_h, arg_s, arg_v, arg_K);

	SunDatabaseReader reader("/Users/pamela/Documents/IC/Study/project1/SUN2012_COMPLETA/SUN2012");

	GraphConstructor constructor(reader, nomearquivo, arq_vertice, arq_grafo, arg_h, arg_s, arg_v, arg_K);

	constructor.build();
	return 0;
}

