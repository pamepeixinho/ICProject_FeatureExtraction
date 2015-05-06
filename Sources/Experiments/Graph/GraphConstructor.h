#ifndef GRAPH_CONSTRUCTOR_H
#define GRAPH_CONSTRUCTOR_H

#include <Utilities/DatabaseReader.hpp>
#include <Utilities/SunDatabaseReader.hpp>
#include <opencv2/imgproc/imgproc.hpp>
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
#include <time.h>
#include <vector>
#include <math.h>
#include <assert.h>
#include <set>
#include <Experiments/Graph/Vertice.h>
#include <Experiments/Graph/Label.h>
#include <Experiments/Graph/Histograma.h>
#include <Experiments/Graph/Area.h>
#include <Experiments/Graph/Orientacao.h>
#include <memory>
#include <Experiments/Graph/Graph.h>

// TYPE
// HISTOGRAMA 1
// AREA 2

template <typename Label_type, typename feature_type>
class GraphConstructor{
	//Graph *Grafo;
	DatabaseReader &reader;
//	char *arq_hsvimages;
	char *arq_vertice;
	char *arq_grafo;
	int arg_h;
	int arg_s;
	int arg_v;
	float arg_K;
	int Discr;
	int type;
	int quantidade;

public:
	GraphConstructor(DatabaseReader &, char*, char *, int, int, int, int,int quantidade=0);
	GraphConstructor(DatabaseReader &, char*, char *, int, int, int quantidade = 0);
	void build();
	//Graph<Label_type, feature_type> build_g();
	void build_g(Graph<Label_type, feature_type>&);
	void recover(char*, char*,char *,int);
};


template <typename Label_type, typename feature_type>
GraphConstructor<Label_type, feature_type>::GraphConstructor(DatabaseReader &Reader, char *arq_vertice, char *arq_grafo, int h, int s, int v, int k, int q) :reader(Reader), arq_vertice(arq_vertice),
arq_grafo(arq_grafo), arg_h(h), arg_s(s), arg_v(v), arg_K(k), quantidade(q)
{
	this->type = 1;
	this->Discr = -1;
}

template <typename Label_type, typename feature_type>
GraphConstructor<Label_type, feature_type>::GraphConstructor(DatabaseReader &Reader, char *arq_vertice, char *arq_grafo, int Discr, int t, int q) :reader(Reader), arq_vertice(arq_vertice),
arq_grafo(arq_grafo), Discr(Discr), quantidade(q)
{
	this->type = t;
	this->arg_h = -1;
	this->arg_s = -1;
	this->arg_v = -1;
	this->arg_K = -1;

}

template <typename Label_type, typename feature_type>
void GraphConstructor<Label_type, feature_type>::build(){

	time_t timer = time(NULL);
	
	Graph<Label_type, feature_type> Grafo;
//	char nomearquivo_temp[100];
	while (reader.hasNext()){

		SupervisedImage i = reader.readNext();

//		char num[10];
//		sprintf(num, "%d", quantidade);
//		strcpy(nomearquivo_temp, arq_hsvimages);
//		strcat(nomearquivo_temp, num);
//		strcat(nomearquivo_temp, ".txt");

		String path_image = i.getImagePath().toStdString();
		Mat image = imread(path_image), image_show;

		if((image.rows!=0 && image.cols !=0) && type==1)
			cvtColor(image, image, CV_BGR2HSV_FULL);
		
		printf("\n\n %d -", quantidade);
		printf("%s\n", path_image.c_str());

		for (int n = 0; n < i.getRegions().size(); n++){
			printf("regiao: %s\n", i.getRegions()[n].getLabel().toStdString().c_str());

			string label = i.getRegions()[n].getLabel().toStdString();
			Label_type LABEL(label);

			Mat mask = i.getRegions()[n].getMask(), mask_show;

			//resize(mask, mask_show, Size(mask.cols / 4, mask.rows / 4));
			//imshow("mask_show", mask_show);
			//waitKey(0);

			feature_type FEATURE;
	
			if ((mask.cols != 0 && mask.rows != 0) && (image.rows != 0 && image.cols != 0)){
				if (type == 1) //histograma
					FEATURE = feature_type(image, mask, arg_h, arg_s, arg_v, n, label, arg_K);
				else if (type == 2) //area
					FEATURE = feature_type(i.getRegions()[n], Discr, image.cols, image.rows);
				//else if (type == 3) //Orientacao
				//	FEATURE = feature_type(i.getRegions()[n], Discr);

				Grafo.ConstructEdges(LABEL,FEATURE);
			}	
		}

		if (this->quantidade % 100 == 0){
			time_t tempo = time(NULL);
			printf("TIME\t%d\t%.2f\n", this->quantidade, difftime(tempo, timer)/60);
		}
		if (this->quantidade % 500 == 0){
			Grafo.printVertices(arq_vertice);
			Grafo.printGraph(arq_grafo);
		}

		quantidade++;
		printf("\n");

		image.release();

	}
	Grafo.printVertices(arq_vertice);
	Grafo.printGraph(arq_grafo);
}

//complete
template <typename Label_type, typename feature_type>
void GraphConstructor<Label_type, feature_type>::recover(char *v, char *vb, char *g,int qt){
	
/*	Graph<Label_type, feature_type> Grafo;
	Grafo.loadGraph(v,vb, g);
	
	this->quantidade = qt;
	int cont=0;
	while (reader.hasNext()){

		SupervisedImage i = reader.readNext();

//		char num[10];
//		sprintf(num, "%d", quantidade);

//		strcpy(nomearquivo_temp, arq_hsvimages);
//		strcat(nomearquivo_temp, num);
//		strcat(nomearquivo_temp, ".txt");

		if(cont>quantidade){

			String path_image = i.getImagePath().toStdString();
			Mat image = imread(path_image), image_show;

			if(image.rows!=0 && image.cols !=0)
				cvtColor(image, image, CV_BGR2HSV_FULL);
		
			printf("\n\n %d -", quantidade);
			printf("%s\n", path_image.c_str());

			for (int n = 0; n < i.getRegions().size(); n++){
				printf("regiao: %s\n", i.getRegions()[n].getLabel().toStdString().c_str());

				string label = i.getRegions()[n].getLabel().toStdString();
				Label_type LABEL(label);

				Mat mask = i.getRegions()[n].getMask(), mask_show;

			//resize(mask, mask_show, Size(mask.cols / 4, mask.rows / 4));
			//imshow("mask_show", mask_show);
			//waitKey(0);

				feature_type HSV;
			//Hsv_Dist HSV(arg_K);
				if ((mask.cols != 0 && mask.rows != 0) && (image.rows != 0 && image.cols != 0)){
					HSV = feature_type(image, mask, arg_h, arg_s, arg_v, n, label, arg_K);
					//HSV = feature_type(nomearquivo_temp, image, mask, arg_h, arg_s, arg_v, n, label, arg_K);
					Grafo.ConstructEdges(LABEL, HSV);
				}

			}
			Grafo.printVertices(arq_vertice);
			Grafo.printGraph(arq_grafo);

			quantidade++;
			printf("\n");

			image.release();

		}
		cont++;
	}*/
}

template <typename Label_type, typename feature_type>
void GraphConstructor<Label_type, feature_type>::build_g(Graph<Label_type, feature_type>& Grafo)
{
	this->quantidade = 0;
	time_t timer = time(NULL);

	while (reader.hasNext()){

		SupervisedImage i = reader.readNext();

		String path_image = i.getImagePath().toStdString();
		Mat image = imread(path_image), image_show;

		if ((image.rows != 0 && image.cols != 0) && type == 1)
			cvtColor(image, image, CV_BGR2HSV_FULL);

		printf("\n\n %d -", quantidade);
		printf("%s\n", path_image.c_str());

		for (int n = 0; n < i.getRegions().size(); n++){
			printf("regiao: %s\n", i.getRegions()[n].getLabel().toStdString().c_str());

			string label = i.getRegions()[n].getLabel().toStdString();
			Label_type LABEL(label);

			Mat mask = i.getRegions()[n].getMask(), mask_show;

			feature_type FEATURE;
			if ((mask.cols != 0 && mask.rows != 0) && (image.rows != 0 && image.cols != 0)){
				if (type == 1) //histograma
					FEATURE = feature_type(image, mask, arg_h, arg_s, arg_v, n, label, arg_K);
				else if (type == 2) //area
					FEATURE = feature_type(i.getRegions()[n], Discr, image.cols, image.rows);
				else if (type == 3) //Orientacao
					FEATURE = feature_type(i.getRegions()[n], Discr);
				Grafo.ConstructEdges(LABEL, FEATURE);
			}
		
		}

		if (this->quantidade % 100 == 0){
			time_t tempo = time(NULL);
			printf("TIME\t%d\t%.2f\n", this->quantidade, difftime(tempo, timer) / 60);
		}
		if (this->quantidade % 500 == 0){
			printf("printar1 - quantidade = %d -> %f\n",this->quantidade, quantidade%500);
			Grafo.printVertices(this->arq_vertice);
			Grafo.printGraph(this->arq_grafo);
		}

		this->quantidade++;
		printf("\n");

		image.release();

	}
	
	printf("printar2\n");
	Grafo.printVertices(arq_vertice);
	Grafo.printGraph(arq_grafo);

	//return Grafo;
}

#endif
