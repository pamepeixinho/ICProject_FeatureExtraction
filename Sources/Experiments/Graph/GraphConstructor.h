#ifndef GRAPHCONSTRUCTOR_H
#define GRAPHCONSTRUCTOR_H

#include <Utilities/SunDatabaseReader.hpp>
#include <FeatureExtractors/Region.hpp>
#include <Utilities/FeaturesComplexNetwork.hpp>
//#include <Utilities/RandomWalk.hpp>
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
//#include <Experiments\AnaliseGrafo\OcorrenciaGrafo.h>

class GraphConstructor{
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

#endif