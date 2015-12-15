#ifndef HISTOGRAMA_DISCRY_H
#define HISTOGRAMA_DISCRY_H

#include <vector>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <Utilities/SupervisedImage.hpp>
#include <FeatureExtractors/Region.hpp>
#include "Vertice.h"
#include "Funcoes_Vector_hist.h"

using namespace std;

class Hsv_DiscrY :public Vertice{
	vector<int> histograma_y;
	int  K;
public:

	Hsv_DiscrY(){}
	Hsv_DiscrY(const vector<int>&, int);
	Hsv_DiscrY(const vector<int>&);
	Hsv_DiscrY(vector<float>&, int);
	Hsv_DiscrY(const Region&, int, int, int);
	Hsv_DiscrY(cv::Mat, cv::Mat, int, int, int, int, string, float);
	Hsv_DiscrY(const Region &, int);
    Hsv_DiscrY( cv::Mat src, cv::Mat mask, int radius, int neighbors, int _fx[],int _fy[],int _cx[], int _cy[],
    float _w1[],float _w2[],float _w3[],float _w4[], int soma,int disc);
	
	int getType() const;

	vector<int> getHist_y();
	void printHistY();

	bool operator<(const Vertice&) const;

};

#endif
