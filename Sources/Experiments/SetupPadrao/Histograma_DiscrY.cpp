//#include "Histograma_DiscrY.h"
//#include <opencv2\imgproc\imgproc.hpp>
//
//using namespace cv;
//
//Hsv_DiscrY::Hsv_DiscrY(const vector<int>&h):histograma_y(h){}
//
//Hsv_DiscrY::Hsv_DiscrY(vector<float>&h, int K){
//	histograma_y.resize(h.size());
//	for (int i = 0; i < h.size(); i++)
//		histograma_y[i] = (int)((h[i] * K) + 0.5);
//}
//
//int Hsv_DiscrY::getType() const{
//	return 2;
//}
//
//vector<int> Hsv_DiscrY::getHist_y(){
//	return histograma_y;
//}
//
//
//bool Hsv_DiscrY::operator<(const Vertice& other) const{
//	if (this->getType() != other.getType())
//		return this->getType() < other.getType();
//
//	const Hsv_DiscrY *other_hsv = dynamic_cast<const Hsv_DiscrY*>(&other);
//	return this->histograma_y < other_hsv->histograma_y;
//	//return dist;
//}
//
//Hsv_DiscrY::Hsv_DiscrY(char *nomearquivo, cv::Mat image, cv::Mat mask, int h, int s, int v, int n, std::string regiao, int K){
//	vector<float> hist;
//
//	FILE* arq = fopen(nomearquivo, "a");
//
//	Mat img_hsv;
//
//	float ph = 0, ps = 0, pv = 0;
//
//	//scanf("%d %d %d", &h, &s, &v);
//
//	ph = 255.0 / (h - 1);
//	ps = 255.0 / (s - 1);
//	pv = 255.0 / (v - 1);
//
//
//	hist.resize((h*s*v), 0);
//
//	cvtColor(image, img_hsv, CV_BGR2HSV_FULL);
//	//Convert RGB to HSV (FULL)->(0 - 255, 0-255, 0-255)
//
//	//printf("     %d %d\n", mask.cols, mask.rows);
//	//imshow("original", image);
//	//imshow("hsv", img_hsv);
//	//imshow("mask", mask);
//
//
//	int z = 0, branco = 0, h1 = 0, s1 = 0, v1 = 0, r = 0, g = 0, b = 0;
//
//	for (int x = 0; x < img_hsv.rows; x++){
//
//		for (int y = 0; y < img_hsv.cols; y++){
//
//			uchar bw = mask.at<uchar>(x, y);
//
//			Vec3b p = img_hsv.at<Vec3b>(x, y);
//
//			h1 = p.val[0];
//			s1 = p.val[1];
//			v1 = p.val[2];
//
//			if (bw != 0){
//
//				//printf("H(entravetor)=%d, S(entravetor)=%d, V(entravetor)=%d\n", h1, s1, v1);
//
//				particiona(&h1, ph);
//				particiona(&s1, ps);
//				particiona(&v1, pv);
//
//				z = ((s*v)*h1) + (v*s1) + v1;
//				hist[z] += 1;
//
//				z = 0;
//				branco++;
//			}
//
//		}
//	}
//
//	//fprintf(arq, "quantidade pixel que entrou no vetor:%d\n", branco);
//	//fprintf(arq, "\nImage:quantidade pixel linhas:%d\ colunas:%d e total:%d\n", img_hsv.rows, img_hsv.cols, (img_hsv.rows*img_hsv.cols));
//	//fprintf(arq, "\nMask:quantidade pixel linhas:%d\ colunas:%d e total:%d\n", mask.rows, mask.cols, (mask.rows*mask.cols));
//
//	hist = normalizavetor(hist, branco, (h*s*v));
//	fprintf(arq, "Regiao_%s%d_%d = [", regiao.c_str(), n, K);
//	for (int i = 0; i < (h*s*v); i++){
//		fprintf(arq, "%.2f ", hist[i]);
//	}
//	fprintf(arq, "];\n");
//
//	img_hsv.release();
//
//	//return hist;
//
//	histograma_y.resize(hist.size());
//	for (int i = 0; i < hist.size(); i++)
//		this->histograma_y[i] = (int)((hist[i] * K) + 0.5);
//
//	fprintf(arq, "Regiao_%s%d_discrY_%d = [", regiao.c_str(), n, K);
//	for (int i = 0; i < histograma_y.size(); i++){
//		fprintf(arq, "%d ", histograma_y[i]);
//	}
//	fprintf(arq, "];\n\n");
//
//	fclose(arq);
//}