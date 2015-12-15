#include "LBP.h"
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv/cv.h>
//#include <opencv/highgui.h>
//#include <opencv/cxcore.h>
#include "Funcoes_Vector_hist.h"

using namespace cv;

LBP::LBP(const vector<int>&h, int k):histograma_y(h), K(k){}
LBP::LBP(const vector<int>&h) : histograma_y(h){}
LBP::LBP(const Region& r, int v, int s, int  t){
}
LBP::LBP(const Region &r, int t){
}
LBP::LBP(vector<float>&h, int K){
    this->K = K;
    histograma_y.resize(h.size());
    for (int i = 0; i < h.size(); i++)
        histograma_y[i] = (int)((h[i] * K) + 0.5);
}
LBP::LBP(cv::Mat i, cv::Mat m, int r, int p, int q, int teste, string erro, float w){}

int LBP::getType() const{
    return 5;
}

void LBP::printLBPY(){
    for(int i=0;i<histograma_y.size();i++)
        printf("%d ", histograma_y[i]);
}

bool LBP::operator<(const Vertice& other) const{
    if (this->getType() != other.getType())
        return this->getType() < other.getType();

    const LBP *other_lbp= dynamic_cast<const LBP*>(&other);
    return this->histograma_y < other_lbp->histograma_y;
    //return dist;
}

LBP::LBP( cv::Mat src, cv::Mat mask, int radius, int neighbors, int _fx[],int _fy[],int _cx[], int _cy[],
float _w1[],float _w2[],float _w3[],float _w4[], int soma, int disc){
    this->K = disc;
    neighbors = max(min(neighbors,31),1); // set bounds...

    int t1 = 1, t2 = 1, t3 = 1, t4 = 1, p1, p2, p3, p4;

    vector<float>hist(soma+1,0);
    int _LBP = 0, brancos = 0;
    float t = 0;
    for(int Xc = radius; Xc < src.rows - radius; Xc++){
        for(int Yc = radius; Yc < src.cols - radius; Yc++){
            if (mask.data[Xc * mask.cols + Yc] > 0){
                _LBP = 0;
                brancos++;
                for(int p = 0; p < neighbors; p++){
                    t1 = 1, t2 = 1, t3 = 1, t4 = 1;

                    p1 = Xc+_fy[p]; p2 = Xc+_cy[p]; p3 = Yc+_fx[p]; p4 = Yc+_cx[p];

                    if(mask.data[p1 * mask.cols + p3] <= 0)
                        t1 = 0;
                    else if(mask.data[p1 * mask.cols + p4] <= 0)
                        t2 = 0;
                    else if(mask.data[p2 * mask.cols + p3] <= 0)
                        t3 = 0;
                    else if(mask.data[p2 * mask.cols + p4] <= 0)
                        t4 = 0;

                    t = t1*_w1[p]*src.at<uchar>(p1,p3) + t2*_w2[p]*src.at<uchar>(p1,p4) + t3*_w3[p]*src.at<uchar>(p2,p3) + t4*_w4[p]*src.at<uchar>(p2,p4);

                    if(src.at<uchar>(Xc,Yc) <= t && (t1 + t2 + t3 + t4) != 0)
                        _LBP += pow(2,p);
                }
                hist[_LBP]++;
//                printf("LBP(%d,%d) = %d\n", Xc, Yc, _LBP);
            }
        }
    }

    vector <int> tmp = normalizaDiscr(hist, brancos, hist.size(), K);
    this->histograma_y = tmp;
}

vector<int> LBP::getLBP_y(){
    return this->histograma_y;
}
