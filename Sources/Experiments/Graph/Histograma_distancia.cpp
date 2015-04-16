#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <math.h>
#include "Histograma_distancia.h"
#include "Funcoes_Vector_hist.h"


Hsv_Dist::Hsv_Dist(std::vector<float>& values, float valor):VALOR_COMP(valor){
	this->histograma = values;
}

Hsv_Dist::Hsv_Dist(float valor):VALOR_COMP(valor){}

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

float Hsv_Dist::getValor(){
	return VALOR_COMP;
}

void Hsv_Dist::setValor(float VALOR_COMP){
	this->VALOR_COMP = VALOR_COMP;
}

Hsv_Dist::Hsv_Dist( cv::Mat image, cv::Mat mask, int h, int s, int v, int n, std::string regiao, float k){
	vector<float> hist;
	
	setValor(k);

//	FILE* arq = fopen(nomearquivo, "a");




	hist.resize((h*s*v), 0);


	int branco = 0, h1 = 0, s1 = 0, v1 = 0, shift=0;

	for (int x = 0; x < image.rows; x++){

		for (int y = 0; y < image.cols; y++){

			//uchar m = mask.at<uchar>(x, y);
			//Vec3b p = img_hsv.at<Vec3b>(x, y);
			//h1 = p.val[0];
			//s1 = p.val[1];
			//v1 = p.val[2];

			if (mask.data[x*mask.cols + y] > 0){
			
				shift = x*image.cols * 3 + y * 3;
				h1 = MIN(image.data[shift] / 255.*(h - 1) + 0.5, (h - 1));
				s1 = MIN(image.data[shift + 1] / 255.*(s - 1) + 0.5, (h - 1));
				v1 = MIN(image.data[shift + 2] / 255.*(v - 1) + 0.5, (h - 1));
				//ret[h*vd*sd + s*vd + v]++;

				hist[((s*v)*h1) + (v*s1) + v1] += 1;
				branco++;
			}

		}
	}

	hist = normalizavetor(hist, branco, (h*s*v));
//	fprintf(arq, "Regiao_%s%d = [", regiao.c_str(), n);
//	for (int i = 0; i < (h*s*v); i++){
//		fprintf(arq, "%.2f ", hist[i]);
//	}
//	fprintf(arq, "];\n\n");


//	fclose(arq);
	
	this->histograma = hist;
}
