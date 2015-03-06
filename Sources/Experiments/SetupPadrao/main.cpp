#include "Vertice.h"
#include "Label.h"
#include "Funcoes_Vector_hist.h"
//#include "Histograma_distancia.h" !PROBLEMA HISTOGRAMA_DISTANCIA.H

int main(){
	return 0;
}

//#include <Utilities/SunDatabaseReader.hpp>
//#include <FeatureExtractors/Region.hpp>
//#include <Utilities/FeaturesComplexNetwork.hpp>
//#include <Utilities/RandomWalk.hpp>
//#include <FeatureExtractors/LabelFeatureFactory.hpp>
//#include <opencv2/core/core.hpp>
//#include <opencv2\core\mat.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv/cv.h>
//#include <opencv/highgui.h>
//#include <opencv/cxcore.h>
//#include <QList>
//#include <cstdio>
//#include <stdlib.h>
//#include <cstdlib>
//#include <iostream>
//#include <string.h>
//#include <vector>
//#include <math.h>
//#include <opencv2\imgproc\imgproc.hpp>
//#include <assert.h>
//#include <set>
//#include "Vertice.h"
//#include "Label.h"
//#include "Histograma.h"
//#include <memory>
//#include "Graph.h"
//
//#define VALOR_COMP 0.25
//#define IND_LABEL 0
//#define IND_HIST_distancia 1
//#define IND_HIST_discretizacao 2
//
//using namespace cv;
//using namespace std;
//
//
////entrada prompt: (pasta)imagens\imagem (hsv)0 0 0 (K)0 (arquivos) Vertice Grafo
//int main(int argc, char* argv[]){
//
//	if (argc!=8){
//		printf("\nEntrada de Argumentos:\n(pasta)imagens\imagem (h s v)0 0 0 (k || valor_comp)0 (arquivo_Vertice)Vertice (arquivo_Grafo)Grafo\n");
//		return 0;
//	}
//
//
//	char *nomearquivo = argv[1], nomearquivo_temp[500];
//	char *arq_vertice = argv[6], *arq_grafo = argv[7];
//	int arg_h = atoi(argv[2]), arg_s = atoi(argv[3]), arg_v = atoi(argv[4]), arg_K = atoi(argv[5]);
//	
//	printf("ARGUMENTOS: h%d s%d v%d k%d\n\n", arg_h, arg_s, arg_v, arg_K);
//
//	SunDatabaseReader reader("/Users/pamela/Documents/IC/Study/project1/SUN2012_COMPLETA/SUN2012");
//
//	long long int qt = 0;
//
//	Grafo Grafo_Hist_Label;
//
//	while (reader.hasNext() && qt<5){
//
//		SupervisedImage i = reader.readNext();
//
//		char num[3];
//		itoa(qt, num, 10);
//
//		strcpy(nomearquivo_temp, nomearquivo);
//		strcat(nomearquivo_temp, num);
//		strcat(nomearquivo_temp, ".txt");
//
//		String path_image = i.getImagePath().toStdString();
//		Mat image = imread(path_image), image_show;
//
//		printf("\n\n %d -", qt);
//		printf("%s\n", path_image.c_str());
//		//printf("Tamanho Image: %d %d\n", image.cols,image.rows);
//
//		//resize(image, image_show, Size(image.cols / 4, image.rows / 4));
//		//imshow("image_show", image_show);
//
//		for (int n = 0; n < i.getRegions().size(); n++){
//			printf("regiao: %s\n", i.getRegions()[n].getLabel().toStdString().c_str());
//
//			string label = i.getRegions()[n].getLabel().toStdString();
//			Label LABEL(label);
//
//			Mat mask = i.getRegions()[n].getMask(), mask_show;
//
//			//resize(mask, mask_show, Size(mask.cols / 4, mask.rows / 4));
//			//imshow("mask_show", mask_show);
//			//waitKey(0);
//
//			Hsv_DiscrY HSV;
//			//Hsv_Dist HSV;
//			if ((mask.cols != 0 && mask.rows != 0) && (image.rows != 0 && image.cols != 0)){
//				HSV = Hsv_DiscrY(nomearquivo_temp, image, mask, arg_h, arg_s, arg_v, n, label, arg_K);
//				//HSV = Hsv_Dist(nomearquivo_temp, image, mask, arg_h, arg_s, arg_v, n, label);
//				Grafo_Hist_Label.MontaGrafo(LABEL, HSV);
//			}
//
//			Grafo_Hist_Label.printVerticesY(arq_vertice);
//			Grafo_Hist_Label.printGrafoB(arq_grafo);
//			Grafo_Hist_Label.printGrafo(arq_grafo);
//		}
//
//		qt++;
//		printf("\n");
//
//		//cout << path_image << endl;
//		//fprintf(arq, "path image: %s\n",path_image);
//		image.release();
//	}
//
//	return 0;
//
//}

