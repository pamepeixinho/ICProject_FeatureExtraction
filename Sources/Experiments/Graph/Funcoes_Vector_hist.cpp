#include "Funcoes_Vector_hist.h"

float result = 0;

vector<float> normalizavetor(vector<float>hist, int t, int size){

	t = (float)t;
	int i = 0;
	for (i = 0; i < size; i++)
		hist[i] = hist[i] / t;

	return hist;
}

vector<int> normalizaDiscr(vector<float>hist, int t, int size, int K){
	vector<int> hist_y(hist.size());
	t = (float)t;
	int i = 0;
	for (i = 0; i < size; i++)
		hist_y[i] = (int)(((hist[i] / t)* K) + 0.5);
	
	return hist_y;
}

void particiona(int *n_img, float porcao){

	result = 0;

	result = *n_img / porcao;
	*n_img = (int)(result + 0.5);

}