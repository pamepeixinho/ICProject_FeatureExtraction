#include "RandomReader.h"

RandomReader::RandomReader(string path){
	char *image, *supervised;
	FILE *arq = fopen(path.c_str(), "rb");
	assert(arq != NULL);
	while (!feof(arq)){
		fscanf(arq, "%s", image);
		fscanf(arq, "%s", supervised);
		printf("img = %s\nSup = %s\n", image, supervised);
		if (!feof(arq)){
			images_path.push_back(string(image));
			supervised_path.push_back(string(supervised));
		}
	}

	printf("\n%d %d\n", images_path.size(), supervised_path.size());
	i_it = images_path.begin();
	s_it = supervised_path.begin();
	started = false;
	fclose(arq);
	printf("already!\n");
}

unsigned int RandomReader::getTotal()const{
	return images_path.size();
}

bool RandomReader::hasNext()const{
	return (i_it+1 != images_path.end());
}

bool RandomReader::hasPrevious()const{
	return (i_it-1 != images_path.begin());
}

SupervisedImage RandomReader::readNext(){
	if (hasNext()){
		if (started){
			i_it++;
			s_it++;
		}
	}
	started = true;
	SupervisedImage img(QString((*i_it).c_str()),QString((*s_it).c_str()));
	return img;
}
SupervisedImage RandomReader::readPrevious(){
	if (hasPrevious()){
			i_it--;
			s_it--;
	}
	SupervisedImage img(QString((*i_it).c_str()),QString((*s_it).c_str()));
	return img;
}
