#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <math.h>
#include "Histograma_distancia.h"
#include "Funcoes_Vector_hist.h"


Hsv_Dist::Hsv_Dist(std::vector<float>& values, int valor):VALOR_COMP(valor){
	this->histograma = values;
}

Hsv_Dist::Hsv_Dist(int valor):VALOR_COMP(valor){}

int Hsv_Dist::getType() const{
	return 1;
}

std::vector<float> Hsv_Dist::getHistDist(){
	return histograma;
}

void Hsv_Dist::setHist(const std::vector<float>&Hist){
	histograma = Hist;
}

float Hsv_Dist::distancia(Hsv_Dist other)const {
	float dist = 0;
	assert(this->histograma.size() == other.histograma.size());
	for (int j = 0; j < this->histograma.size(); j++)
		if (fabs(other.histograma[j] - this->histograma[j])>VALOR_COMP)
			return other.histograma[j] < this->histograma[j];

	return false;
}

bool Hsv_Dist::operator<(const Vertice& other) const{
	if (this->getType() != other.getType())
		return this->getType() < other.getType();

	const Hsv_Dist *other_hsv = dynamic_cast<const Hsv_Dist*>(&other);

	return distancia(*other_hsv);
}

Hsv_Dist::Hsv_Dist(char *nomearquivo, cv::Mat image, cv::Mat mask, int h, int s, int v, int n, std::string regiao){
	vector<float> hist;

	FILE* arq = fopen(nomearquivo, "a");

	Mat img_hsv;

	float ph = 0, ps = 0, pv = 0;

	//scanf("%d %d %d", &h, &s, &v);

	ph = 255.0 / (h - 1);
	ps = 255.0 / (s - 1);
	pv = 255.0 / (v - 1);


	hist.resize((h*s*v), 0);

	cvtColor(image, img_hsv, CV_BGR2HSV_FULL);

	int z = 0, branco = 0, h1 = 0, s1 = 0, v1 = 0, r = 0, g = 0, b = 0;

	for (int x = 0; x < img_hsv.rows; x++){

		for (int y = 0; y < img_hsv.cols; y++){

			uchar m = mask.at<uchar>(x, y);

			Vec3b p = img_hsv.at<Vec3b>(x, y);

			h1 = p.val[0];
			s1 = p.val[1];
			v1 = p.val[2];

			if (m != 0){

				//printf("H(entravetor)=%d, S(entravetor)=%d, V(entravetor)=%d\n", h1, s1, v1);

				particiona(&h1, ph);
				particiona(&s1, ps);
				particiona(&v1, pv);

				z = ((s*v)*h1) + (v*s1) + v1;
				hist[z] += 1;

				z = 0;
				branco++;
			}

		}
	}

	hist = normalizavetor(hist, branco, (h*s*v));
	fprintf(arq, "Regiao_%s%d = [", regiao.c_str(), n);
	for (int i = 0; i < (h*s*v); i++){
		fprintf(arq, "%.2f ", hist[i]);
	}
	fprintf(arq, "];\n\n");

	img_hsv.release();

	fclose(arq);
	
	this->histograma = hist;
}
