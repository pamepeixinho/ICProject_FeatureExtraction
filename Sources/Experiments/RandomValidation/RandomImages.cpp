#include "RandomImages.h"

RandomImages::RandomImages(DatabaseReader &reader){
	while (reader.hasNext()){
		SupervisedImage image = reader.readNext();
		ImageRead aux;
		aux.image_path = image.getImagePath().toStdString();
		aux.supervised_path = image.getSupervisedPath().toStdString();
		all.push_back(aux);
	}
	srand(time(0));
	vector<int> ind;
	int in;
	while (qtatual != ((all.size() * 70) / 100)){
		in = rand() % all.size();
		imagesChoosen.push_back(all[in]);
		ind.push_back(in);
		qtatual++;
	}

	bool thereIs;
	for (int i = 0; i < all.size(); i++){
		for (int j = 0; j < ind.size(); j++){
			if (i == ind[j]){
				thereIs = true;
				break;
			}
		}

		if (thereIs != true)
			images.push_back(all[i]);
	}
}

void RandomImages::print(string file_path){
	string choosen = file_path + "ImagesChoosen.bin";
	string others = file_path + "Others.bin";

	FILE *arq70 = fopen(choosen.c_str(), "wb");
	assert(arq70 != NULL);
	FILE *arq30 = fopen(others.c_str(), "wb");
	assert(arq30 != NULL);

	for (int i = 0; i < imagesChoosen.size(); i++)
		fprintf(arq70, "%s\n%s\n", imagesChoosen[i].image_path.c_str(), imagesChoosen[i].supervised_path.c_str());
	
	for (int i = 0; i < images.size();i++)
		fprintf(arq30, "%s\n%s\n", images[i].image_path.c_str(), images[i].supervised_path.c_str());

	fclose(arq70);
	fclose(arq30);

}
