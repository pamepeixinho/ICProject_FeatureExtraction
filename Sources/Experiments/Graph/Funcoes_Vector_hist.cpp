#include "Funcoes_Vector_hist.h"

float result = 0;

vector<float> normalizavetor(vector<float>hist, int t, int size){

	t = (float)t;
	int i = 0;
	for (i = 0; i < size; i++)
		hist[i] = hist[i] / t;

	return hist;
}

void particiona(int *n_img, float porcao){

	result = 0;

	result = *n_img / porcao;
	*n_img = (int)(result + 0.5);

}