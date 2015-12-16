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
#include <Experiments/Graph/LBP.h>

using namespace cv;
using namespace std;

int main(int argc, char *argv[]){

    if(argc != 5){
        printf("Parametros: arqVertice.txt arqVertice_ordem.bin arqGrafo.bin arqOcorrencia(sem extensao)\n");
        return 0;
    }


    HistogramaOcorrencia Evaluation = HistogramaOcorrencia(argv[1], argv[2], argv[3], argv[4]);


    return 0;
}
