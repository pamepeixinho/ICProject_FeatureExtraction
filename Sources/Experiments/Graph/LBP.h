#ifndef LBP_H
#define LBP_H

#include <vector>
#include <iostream>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/core/mat.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv/cv.h>
#include <Utilities/SupervisedImage.hpp>
#include <FeatureExtractors/Region.hpp>
#include "Vertice.h"
#include "Funcoes_Vector_hist.h"

using namespace std;

class LBP : public Vertice{
    vector<int> histograma_y;
    int  K;
public:

    LBP(){}
    LBP(const vector<int>&, int);
    LBP(const vector<int>&);
    LBP(vector<float>&, int);
    LBP(const Region&, int, int, int);
    LBP(cv::Mat, cv::Mat, int, int, int, int, string, float);
    LBP(const Region &, int);
    LBP( cv::Mat src, cv::Mat mask, int radius, int neighbors, int _fx[],int _fy[],int _cx[], int _cy[],
    float _w1[],float _w2[],float _w3[],float _w4[], int soma, int discr);

    int getType() const;

    vector<int> getLBP_y();
    void printLBPY();

    bool operator < (const Vertice&) const;

};

#endif
