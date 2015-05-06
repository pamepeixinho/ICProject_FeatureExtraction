#ifndef ORIENTACAO_H
#define ORIENTACAO_H

#include "Vertice.h"
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <Utilities/SupervisedImage.hpp>
#include <FeatureExtractors/Region.hpp>
#include <opencv/cxcore.h>
#include <cmath>
#include <QPolygon>
#include <QPoint>

using namespace std;
//using namespace cv;

class Orientacao : public Vertice {
	int discr;
	int orientacao;
public:
	Orientacao();
	Orientacao(const Region &r, int discr);
	Orientacao(const Region&, int, int, int);
	Orientacao(cv::Mat, cv::Mat, int, int, int, int, string, float);
	QList<QPoint> makeQList(const Region &r);
	void factory(const Region &r);
	float distance(QPoint a, QPoint b)const;
	int discretiza(float min, float max, float d, int val)const;

	int getType() const;
	bool operator<(const Vertice& other) const;

	int getOrientacao()const;
	//~Orientacao();
};

#endif //ORIENTACAO_H
