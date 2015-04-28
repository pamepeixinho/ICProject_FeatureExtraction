#ifndef RANDOM_REGION_READER_H
#define RANDOM_REGION_READER_H

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
#include <QString>

using namespace std; 
class ChoosedRegion{
public:
	string image_path;
	string supervised_path;
	int regionChoosed;
	SupervisedImage readNextSupervisedImage()const;
	ChoosedRegion(string, string, int);
};

class RandomRegionReader{
	vector<ChoosedRegion>Regions;
	int actualRegion;
public:
	RandomRegionReader(string);
	ChoosedRegion readNextRegion();
	bool hasNextRegion()const;
	
};


#endif
