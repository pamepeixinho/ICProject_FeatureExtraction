#ifndef RANDOM_READER_H
#define RANDOM_READER_H

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

class RandomReader: public DatabaseReader{
	vector<string>images_path;
	vector<string>supervised_path;
	vector<string>::iterator i_it;
	vector<string>::iterator s_it;
	bool started;
public:
	RandomReader(string);
	bool hasNext()const;
	bool hasPrevious()const;
	SupervisedImage readNext();
	SupervisedImage readPrevious();
	unsigned int getTotal()const;
	~RandomReader(){}
};

#endif
