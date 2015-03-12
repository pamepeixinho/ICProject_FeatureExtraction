#ifndef GRAPHCONSTRUCTOR_H
#define GRAPHCONSTRUCTOR_H

#include <Utilities/SunDatabaseReader.hpp>
#include <FeatureExtractors/Region.hpp>
#include <Utilities/FeaturesComplexNetwork.hpp>
//#include <Utilities/RandomWalk.hpp>
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
#include <Experiments/Graph/Vertice.h>
#include <Experiments/Graph/Label.h>
#include <Experiments/Graph/Histograma.h>
#include <memory>
#include <Experiments/Graph/Graph.h>
//#include <Experiments/AnaliseGrafo/OcorrenciaGrafo.h>

template <typename Label_type, typename Histograma_type>
class GraphConstructor{
	//Graph *Grafo;
	SunDatabaseReader &reader;
	char *arq_hsvimages;
	char *arq_vertice;
	char *arq_grafo;
	int arg_h;
	int arg_s;
	int arg_v;
	int arg_K;
	int quantidade;

public:
	GraphConstructor(SunDatabaseReader &, char*, char *, char *, int, int, int, int, int quantidade=0);
	void build();
};


template <typename Label_type, typename Histograma_type>
GraphConstructor<Label_type, Histograma_type>::GraphConstructor(SunDatabaseReader &Reader, char* arq_hsvimages, char *arq_vertice, char *arq_grafo, int h, int s, int v, int k, int q) :reader(Reader),
arq_hsvimages(arq_hsvimages), arq_vertice(arq_vertice),
arq_grafo(arq_grafo), arg_h(h), arg_s(s), arg_v(v), arg_K(k), quantidade(q)
{
}

template <typename Label_type, typename Histograma_type>
void GraphConstructor<Label_type, Histograma_type>::build(){

	Graph<Label_type, Histograma_type> Grafo;
	char nomearquivo_temp[100];
	while (reader.hasNext()){

		SupervisedImage i = reader.readNext();

		char num[10];
		itoa(quantidade, num, 10);

		strcpy(nomearquivo_temp, arq_hsvimages);
		strcat(nomearquivo_temp, num);
		strcat(nomearquivo_temp, ".txt");

		String path_image = i.getImagePath().toStdString();
		Mat image = imread(path_image), image_show;

		printf("\n\n %d -", quantidade);
		printf("%s\n", path_image.c_str());
		//printf("Tamanho Image: %d %d\n", image.cols,image.rows);

		//resize(image, image_show, Size(image.cols / 4, image.rows / 4));
		//imshow("image_show", image_show);

		for (int n = 0; n < i.getRegions().size(); n++){
			printf("regiao: %s\n", i.getRegions()[n].getLabel().toStdString().c_str());

			string label = i.getRegions()[n].getLabel().toStdString();
			Label_type LABEL(label);

			Mat mask = i.getRegions()[n].getMask(), mask_show;

			//resize(mask, mask_show, Size(mask.cols / 4, mask.rows / 4));
			//imshow("mask_show", mask_show);
			//waitKey(0);

			Histograma_type HSV;
			//Hsv_Dist HSV(arg_K);
			if ((mask.cols != 0 && mask.rows != 0) && (image.rows != 0 && image.cols != 0)){
				HSV = Histograma_type(nomearquivo_temp, image, mask, arg_h, arg_s, arg_v, n, label, arg_K);
				//HSV = Hsv_Dist(nomearquivo_temp, image, mask, arg_h, arg_s, arg_v, n, label);
				Grafo.ConstructEdges(LABEL, HSV);
			}

			Grafo.printVertices(arq_vertice);
			Grafo.printGraph(arq_grafo);
		}

		quantidade++;
		printf("\n");

		image.release();

	}
}


#endif