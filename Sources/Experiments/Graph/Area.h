#ifndef AREA_H
#define AREA_H

#include "Vertice.h"
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <Utilities/SupervisedImage.hpp>
#include <FeatureExtractors/Region.hpp>
#include <opencv/cxcore.h>
#include <math.h>

using namespace std;
//using namespace cv;

class Area : public Vertice {
	float area;
	int discr;
public:
	Area();
	Area(const Region&, int, int, int);
	Area(int);
	Area(float, int);
	Area(cv::Mat, cv::Mat, int, int, int, int, std::string, float);
	Area(const Region &, int);
	int getType() const;
	bool operator<(const Vertice& other) const;
	~Area();
	float getArea()const;
};

#endif //AREA_H
