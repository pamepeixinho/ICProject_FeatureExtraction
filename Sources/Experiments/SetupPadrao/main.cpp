#include <Utilities/SunDatabaseReader.hpp>
#include <FeatureExtractors/Region.hpp>
#include <Utilities/FeaturesComplexNetwork.hpp>
#include <Utilities/RandomWalk.hpp>
#include <FeatureExtractors/LabelFeatureFactory.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/core/mat.hpp>
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
#include <opencv2/imgproc/imgproc.hpp>
#include <assert.h>
#include <set>
#include <memory>
#include <Experiments/Graph/Vertice.h>
#include <Experiments/Graph/Label.h>
#include <Experiments/Graph/Histograma.h>
#include <Experiments/Graph/Graph.h>
#include <Experiments/Graph/OcorrenciaGrafo.h>
#include <Experiments/Graph/GraphConstructor.h>


//#define VALOR_COMP 0.25

//#define IND_LABEL 0

//#define IND_HIST_distancia 1

//#define IND_HIST_discretizacao 2


using namespace cv;
using namespace std;


//entrada prompt: (pasta)imagens\imagem (hsv)0 0 0 (K)0 (arquivos) Vertice Grafo

int main(int argc, char* argv[]){


	if (argc!=8){

		printf("\nEntrada de Argumentos:\n(h s v)0 0 0 (k || valor_comp)0 (pasta/arquivo_Vertice)Vertice (pasta/arquivo_Grafo)Grafo (pasta/arquivo_Ocorrencia)Ocorrencia\n");

		return 0;

	}


	char *arq_vertice = argv[5], *arq_grafo = argv[6], *arq_ocorrencia = argv[7];
	int arg_h = atoi(argv[1]), arg_s = atoi(argv[2]), arg_v = atoi(argv[3]);
	float arg_K = atoi(argv[4]);

	
	printf("ARGUMENTOS: h%d s%d v%d k%.2f %s %s %s\n\n", arg_h, arg_s, arg_v, arg_K, arq_vertice, arq_grafo, arq_ocorrencia);
//	system("pause");
	SunDatabaseReader reader("/home/pamela/SUN2012/");



	//Graph<Label, Hsv_DiscrY>Grafo;

	/*GraphConstructor<Label,Hsv_DiscrY> constructor(reader, nomearquivo, arq_vertice, arq_grafo, arg_h, arg_s, arg_v, arg_K);*/

	GraphConstructor<Label, Hsv_DiscrY> constructor(reader, arq_vertice, arq_grafo, arg_h, arg_s, arg_v, arg_K);

	constructor.build();

//	OcorrenciaH_Grafo(arq_vertice, arq_grafo, arq_ocorrencia);
	char ocorre[100];
	strcpy(ocorre, arq_ocorrencia);
	strcat(ocorre, "_indices");
	strcat(arq_ocorrencia, "_simples");
	OcorrenciaH_Grafo(arq_vertice, arq_grafo, arq_ocorrencia);
	OcorrenciaVert_Grafo(arq_vertice, arq_grafo, ocorre);




	return 0;

}
