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
#include <opencv2/imgproc/imgproc.hpp>
#include <QList>
#include <cstdio>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
#include <assert.h>
#include <set>
#include <memory>
#include <Experiments/Graph/Vertice.h>
#include <Experiments/Graph/Label.h>
#include <Experiments/Graph/Histograma.h>
#include <Experiments/Graph/Graph.h>
#include <Experiments/Graph/OcorrenciaGrafo.h>
#include <Experiments/Graph/GraphConstructor.h>
#include <Experiments/Graph/HistogramaOcorrencia.h>
#include <Experiments/Graph/Orientacao.h>


//#define VALOR_COMP 0.25

//#define IND_LABEL 0

//#define IND_HIST_distancia 1

//#define IND_HIST_discretizacao 2


using namespace cv;
using namespace std;


//entrada prompt: (pasta)imagens\imagem (hsv)0 0 0 (K)0 (arquivos) Vertice Grafo

int main(int argc, char* argv[]){


	if (argc == 1){
		printf("TYPE (HSV, Area, Orientacao)\n");
		return 0;
	}
	
	if (strcmp(argv[1], "HSV")==0 && argc!=10){
		printf("\nEntrada de Argumentos:\nTYPE pathSUN (h s v)0 0 0 (k || valor_comp)0 (pasta/arquivo_Vertice)Vertice (pasta/arquivo_Grafo)Grafo (pasta/arquivo_Ocorrencia)Ocorrencia\n");
		return 0;
	}
	else if (strcmp(argv[1], "Area") == 0 && argc!=7){
		printf("\nEntrada de Argumentos:\nTYPE pathSUN (Discr Area)0 (pasta/arquivo_Vertice)Vertice (pasta/arquivo_Grafo)Grafo (pasta/arquivo_Ocorrencia)Ocorrencia\n");
		return 0;
	}
	else if (strcmp(argv[1], "Orientacao") == 0 && argc != 7){
		printf("\nEntrada de Argumentos:\nTYPE pathSUN (Discr Orientacao)0 (pasta/arquivo_Vertice)Vertice (pasta/arquivo_Grafo)Grafo (pasta/arquivo_Ocorrencia)Ocorrencia\n");
		return 0;
	}
	
	char *arq_vertice ,*arq_grafo ,*arq_ocorrencia;
	int arg_h,arg_s, arg_v, arg_d;
	float arg_K;
	int type = 0;

	if (strcmp(argv[1], "HSV") == 0){
		arg_h = atoi(argv[3]);
		arg_s = atoi(argv[4]);
		arg_v = atoi(argv[5]);
		arg_K = atoi(argv[6]);
		arq_vertice = argv[7];
		arq_grafo = argv[8];
		arq_ocorrencia = argv[9];
		type = 1;
		printf("ARGUMENTOS: h%d s%d v%d k%.2f %s %s %s\n\n", arg_h, arg_s, arg_v, arg_K, arq_vertice, arq_grafo, arq_ocorrencia);
	}
	else if (strcmp(argv[1], "Area") == 0){
		arg_d = atoi(argv[3]);
		arq_vertice = argv[4];
		arq_grafo = argv[5];
		arq_ocorrencia = argv[6];
		type = 2;
		printf("ARGUMENTOS: D%d %s %s %s\n\n", arg_d, arq_vertice, arq_grafo, arq_ocorrencia);
	}
	else if (strcmp(argv[1], "Orientacao") == 0){
		arg_d = atoi(argv[3]);
		arq_vertice = argv[4];
		arq_grafo = argv[5];
		arq_ocorrencia = argv[6];
		type = 3;
		printf("ARGUMENTOS: D%d %s %s %s\n\n", arg_d, arq_vertice, arq_grafo, arq_ocorrencia);
	}

	SunDatabaseReader reader(argv[2]);
	
	if (type == 1){
		GraphConstructor<Label, Hsv_DiscrY> constructor(reader, arq_vertice, arq_grafo, arg_h, arg_s, arg_v, arg_K);
		constructor.build();
	}
	else if (type == 2){
		GraphConstructor<Label, Area> constructor(reader, arq_vertice, arq_grafo, arg_d,2);
		constructor.build();
	}
	else if (type == 3){
		GraphConstructor<Label,Orientacao> constructor(reader, arq_vertice, arq_grafo, arg_d,3);
		constructor.build();
	}

	char ocorre[100], grafo[100], vert1[100];
	strcpy(grafo, arq_grafo);
	strcpy(vert1, arq_vertice);

	strcat(vert1, ".txt");
	strcat(arq_vertice, "_ordem.bin");
	strcat(grafo, ".bin");

	printf("%s\n %s\n %s\n %s\n", ocorre, vert1, arq_vertice, grafo);


	HistogramaOcorrencia Evaluation = HistogramaOcorrencia(vert1, arq_vertice, grafo, arq_ocorrencia);

	/*char ocorre[100], grafo[100];
	strcpy(grafo, arq_grafo);
	strcpy(ocorre, arq_ocorrencia);
	strcpy(arq_ocorrencia, ocorre);

	
	strcat(ocorre, "_indices");
	strcat(arq_ocorrencia, "_simples");

	strcat(arq_vertice, "_ordem.bin");
	strcat(grafo, ".bin");

	printf("%s\n %s\n %s\n %s\n", ocorre, arq_ocorrencia, arq_vertice, grafo);
	
	OcorrenciaH_Grafo(arq_vertice, grafo, arq_ocorrencia);
	OcorrenciaVert_Grafo(arq_vertice,grafo, ocorre);*/


	return 0;

}
