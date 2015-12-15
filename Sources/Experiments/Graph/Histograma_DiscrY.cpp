#include "Histograma_DiscrY.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv/cxcore.h>

//#include "Funcoes_Vector_hist.h"

using namespace cv;

Hsv_DiscrY::Hsv_DiscrY(const vector<int>&h, int k):histograma_y(h), K(k){}
Hsv_DiscrY::Hsv_DiscrY(const vector<int>&h) : histograma_y(h){}
Hsv_DiscrY::Hsv_DiscrY(const Region& r, int v, int s, int  t){
}

Hsv_DiscrY::Hsv_DiscrY(const Region &r, int t){
}

Hsv_DiscrY::Hsv_DiscrY(vector<float>&h, int K){
	this->K = K;
	histograma_y.resize(h.size());
	for (int i = 0; i < h.size(); i++)
		histograma_y[i] = (int)((h[i] * K) + 0.5);
}

Hsv_DiscrY::Hsv_DiscrY( cv::Mat src, cv::Mat mask, int radius, int neighbors, int _fx[],int _fy[],int _cx[], int _cy[],
float _w1[],float _w2[],float _w3[],float _w4[],int soma, int disc){}

int Hsv_DiscrY::getType() const{
	return 2;
}

vector<int> Hsv_DiscrY::getHist_y(){
	return histograma_y;
}

void Hsv_DiscrY::printHistY(){
	for(int i=0;i<histograma_y.size();i++)
		printf("%d ", histograma_y[i]);
}

bool Hsv_DiscrY::operator<(const Vertice& other) const{
	if (this->getType() != other.getType())
		return this->getType() < other.getType();

	const Hsv_DiscrY *other_hsv = dynamic_cast<const Hsv_DiscrY*>(&other);
	return this->histograma_y < other_hsv->histograma_y;
	//return dist;
}

Hsv_DiscrY::Hsv_DiscrY( cv::Mat image, cv::Mat mask, int h, int s, int v, int n, std::string regiao, float  K){
	this->K = (int)K;
	//printf("K = %d\n",this->K);
	vector<float> hist;

	//FILE* arq = fopen(nomearquivo, "a");

//	Mat img_hsv;

//	float ph = 0, ps = 0, pv = 0;

	//scanf("%d %d %d", &h, &s, &v);

//	ph = 255.0 / (h - 1);
//	ps = 255.0 / (s - 1);
//	pv = 255.0 / (v - 1);

	int sizeH = (h*s*v);
	hist.resize(sizeH, 0);

//	cvtColor(image, img_hsv, CV_BGR2HSV_FULL);
	//Convert RGB to HSV (FULL)->(0 - 255, 0-255, 0-255)

	//printf("     %d %d\n", mask.cols, mask.rows);
//	namedWindow( "original", WINDOW_AUTOSIZE );
//	imshow("original", image);
//	waitKey(0);
	//imshow("hsv", img_hsv);
	//imshow("mask", mask);


	int branco = 0, h1 = 0, s1 = 0, v1 = 0, shift=0;

	for (int x = 0; x < image.rows; x++){

		for (int y = 0; y < image.cols; y++){

			if (mask.data[x*mask.cols + y] > 0){

//				cv::Vec3b& c = image.at<cv::Vec3b>(x,y);
//				h1 = MIN(c[0]/256.*(h-1)+0.5, (h-1)) ;
//		                s1 = MIN(c[1]/256.*(s-1)+0.5, (s-1));
//		                v1 = MIN(c[2]/256.*(v-1)+0.5, (v-1));

				shift = x*image.cols * 3 + y * 3;
				h1 = MIN(image.data[shift] / 255.*(h - 1) + 0.5, (h - 1));
				s1 = MIN(image.data[shift + 1] / 255.*(s - 1) + 0.5, (s - 1));
				v1 = MIN(image.data[shift + 2] / 255.*(v - 1) + 0.5, (v - 1));

				hist[h1*v*s + v*s1 + v1] +=1;
				branco++;
			}
		
		}
	}

	this->histograma_y = normalizaDiscr(hist, branco, (sizeH), K);

	/*hist = normalizavetor(hist, branco, (h*s*v));
	
	histograma_y.resize(hist.size());
	for (int i = 0; i < hist.size(); i++)
		this->histograma_y[i] = (int)((hist[i] * K) + 0.5);*/
	
//	printHistY();

}
