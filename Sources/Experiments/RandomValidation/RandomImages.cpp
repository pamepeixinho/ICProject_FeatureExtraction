#include "RandomImages.h"

RandomImages::RandomImages(DatabaseReader &reader){
int n=0;
	this->qtatual = 0;
	//printf("carrega\n");
	while (reader.hasNext()){
		SupervisedImage image = reader.readNext();
		ImageRead aux;
		aux.image_path = image.getImagePath().toStdString();
		aux.supervised_path = image.getSupervisedPath().toStdString();	
		Mat img = imread(aux.image_path);
		if(img.rows!=0 && img.cols !=0)
			all.push_back(aux);
		//printf("%d\n", n);
		n++;
	}
	
	printf("all = %d - %d\n", all.size(), n);

	n=0;
	srand(time(0));
	int in;
	int percent =  ((int)((all.size() * 70) / 100.0));

	while (qtatual != percent){
		in = rand() % all.size();
		imagesChoosen.push_back(all[in]);
		all.erase(all.begin()+in);
		qtatual++;
	}

	printf("quant30 = %d, 70% =  %d,qtatual =  %d\n",all.size(), percent, qtatual);
	n = 0;
	
	//system("pause");
	
	while(all.size()>0){	
		int t = all.size();
		images.push_back(all[t-1]);
		all.erase(all.begin()+(t-1));
		//printf("30 - %d\n", n);
		n++;
	}

	printf("images = %d\nall = %d\n", images.size(), all.size());
}

void RandomImages::print(string file_path){
	
	string choosen = file_path + "ImagesChoosen.bin";
	printf("%s\n", choosen.c_str());
	
	string others = file_path + "Others.bin";
	printf("%s\n",others.c_str());

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
