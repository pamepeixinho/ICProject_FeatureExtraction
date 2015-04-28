#ifndef RANDOM_IMAGES_H
#define RANDOM_IMAGES_H

#include <Utilities/SunDatabaseReader.hpp>
#include <Utilities/DatabaseReader.hpp>
#include <Utilities/SupervisedImage.hpp>
#include <FeatureExtractors/Region.hpp>
#include <Utilities/FeaturesComplexNetwork.hpp>
#include <Utilities/RandomWalk.hpp>
#include <FeatureExtractors/LabelFeatureFactory.hpp>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <vector>
#include <time.h>
#include <assert.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv/cxcore.h>

using namespace std;
using namespace cv;

class ImageRead{
public:
	string image_path;
	string supervised_path;

};

class RandomImages{

	vector<ImageRead> imagesChoosen;
	vector<ImageRead> images;
	vector<ImageRead> all;
	int  qtatual;

public:
	RandomImages(DatabaseReader&);
	void print(string file);
};


#endif
