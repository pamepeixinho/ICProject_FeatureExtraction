#ifndef HISTOGRAMA_DISTANCIA_H
#define HISTOGRAMA_DISTANCIA_H

#include "Vertice.h"
#include <vector>
#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <assert.h>

class Hsv_Dist : public Vertice{
	std::vector<float> histograma;
	int VALOR_COMP;
public:
	Hsv_Dist(std::vector<float>&);
	Hsv_Dist(){}
	Hsv_Dist(char*, cv::Mat, cv::Mat, int, int, int, int, std::string);

	int getType() const;
	std::vector<float> getHistDist();
	void setHist(const std::vector<float>&);

	float distancia(Hsv_Dist)const;

	bool operator<(const Vertice&) const;

};

#endif