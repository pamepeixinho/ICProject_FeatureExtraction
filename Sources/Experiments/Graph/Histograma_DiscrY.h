#ifndef HISTOGRAMA_DISCRY_H
#define HISTOGRAMA_DISCRY_H

#include <vector>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "Vertice.h"
#include "Funcoes_Vector_hist.h"

using namespace std;

class Hsv_DiscrY :public Vertice{
	vector<int> histograma_y;
	int  K;
public:

	Hsv_DiscrY(){}
	Hsv_DiscrY(const vector<int>&, int);
	Hsv_DiscrY(vector<float>&, int);
	Hsv_DiscrY(cv::Mat, cv::Mat, int, int, int, int, string, float);
	
	int getType() const;

	vector<int> getHist_y();
	void printHistY();

	bool operator<(const Vertice&) const;

};

#endif
