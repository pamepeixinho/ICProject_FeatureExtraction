#ifndef HISTOGRAMA_DISTANCIA_H
#define HISTOGRAMA_DISTANCIA_H

#include <Experiments/Graph/Vertice.h>
#include <vector>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

class Hsv_Dist : public Vertice{
	vector<float> histograma;
public:
	int VALOR_COMP;
	Hsv_Dist(vector<float>&, int);
	Hsv_Dist(){}
	Hsv_Dist(char*, Mat, Mat, int, int, int, int, string);
	Hsv_Dist(int);

	int getType() const;
	vector<float> getHistDist();
	void setHist(const vector<float>&);

	float distancia(Hsv_Dist)const;

	bool operator<(const Vertice&) const;

};

#endif