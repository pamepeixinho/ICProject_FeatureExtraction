//#include <Utilities/SunDatabaseReader.hpp>
//#include <Utilities/SupervisedImage.hpp>
//#include <FeatureExtractors/Region.hpp>
//#include <Utilities/FeaturesComplexNetwork.hpp>
//#include <Utilities/RandomWalk.hpp>
//#include <FeatureExtractors/LabelFeatureFactory.hpp>
//#include <opencv2/core/core.hpp>
//#include <opencv2\core\mat.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv/cv.h>
//#include <opencv/highgui.h>
//#include <opencv/cxcore.h>
//#include <QList>
//#include <cstdio>
//#include <stdlib.h>
//#include <cstdlib>
//#include <iostream>
//#include <string.h>
//#include <vector>
//#include <math.h>
//#include <opencv2\imgproc\imgproc.hpp>
//#include <assert.h>
//#include <set>
//
//#define VALOR_COMP 0.25
//#define IND_LABEL 0
//#define IND_HIST 1
//
//using namespace cv;
//using namespace std;
//
//
//class Vertice{
//public:
//	int idx = -1;
//	virtual int getType() const = 0;
//	virtual ~Vertice(){}
//
//	virtual bool operator==(const Vertice& other) const = 0;
//
//};
//
//class Label : public Vertice{
//	string s;
//public:
//
//	Label(const string& s){
//		this->s = s;
//	}
//
//	int getType() const{
//		return 0;
//	}
//
//	bool operator==(const Vertice& other) const{
//		if (this->getType() != other.getType())
//			return false;
//		cout << "comparando " << this->s.c_str() << " com " << dynamic_cast<const Label*>(&other)->s.c_str() << "\n";
//		return  dynamic_cast<const Label*>(&other)->s.compare(this->s) == 0;
//	}
//
//	~Label(){}
//
//	string getLabel(){
//		return s;
//	}
//};
//
//class Hist_comp{
//public:
//	int ind;
//	float valor;
//	
//	bool operator < (const Hist_comp &a){
//		return this->valor > a.valor;
//	} 
//};
//
//class Hsv : public Vertice{
//	vector<float> histograma;
//	set<Hist_comp>histograma_cmp;
//
//public:
//	Hsv(vector<float>& values){
//		this->histograma = values;
//	}
//
//	Hsv(){}
//
//	int getType() const{
//		return 1;
//	}
//
//	float distancia(Hsv other)const {
//		relaxamento - distancia euclidiana
//		float dist = 0;
//		assert(this->histograma.size() == other.histograma.size());
//		for (int j = 0; j < this->histograma.size(); j++)
//			dist += pow((this->histograma[j] - other.histograma[j]), 2);
//		dist = sqrt(dist);
//		return dist;
//	}
//
//	bool operator==(const Vertice& other) const{
//		if (this->getType() != other.getType())
//			return false;
//		return this->histograma == dynamic_cast<const Hsv*>(&other)->histograma;
//		const Hsv *teste = dynamic_cast<const Hsv*>(&other);
//		float dist = distancia(*teste);
//		return dist < VALOR_COMP;
//	}
//
//	void show_hist(){
//		for (int i = 0; i < this->histograma.size(); i++)
//			printf("%f ", this->histograma[i]);
//		cout << endl;
//	}
//
//	Hsv(char *nomearquivo, Mat image, Mat mask, int h, int s, int v, int n, String regiao);
//
//	vector<float> getHist(){
//		return histograma;
//	}
//};
//
//set<unique_ptr<Vertice>> Vertices;
//vector<unique_ptr<Vertice> >indice;
//
//vector<vector<int> >Matriz_Adjacencia;
//
//char v[20];
//char aux[20];
//float result = 0;
//void particiona(int *n_img, float porcao){
//
//	result = 0;
//
//	result = *n_img / porcao;
//	*n_img = (int)(result + 0.5);
//
//}
//
//vector<float> normalizavetor(vector<float>hist, int t, int size){
//
//	t = (float)t;
//	int i = 0;
//	for (i = 0; i < size; i++){
//		printf("antes: %f", hist[i]);
//
//		hist[i] = hist[i] / t;
//
//		printf("depois: %f", hist[i]);
//	}
//
//	return hist;
//}
//
//Hsv::Hsv(char *nomearquivo, Mat image, Mat mask, int h, int s, int v, int n, String regiao){
//	vector<Hist_comp> hist;
//
//	FILE* arq = fopen(nomearquivo, "a");
//
//	Mat img_hsv;
//
//	float ph = 0, ps = 0, pv = 0;
//
//	scanf("%d %d %d", &h, &s, &v);
//
//	ph = 255.0 / (h - 1);
//	ps = 255.0 / (s - 1);
//	pv = 255.0 / (v - 1);
//
//
//	hist.resize((h*s*v), 0);
//
//	cvtColor(image, img_hsv, CV_BGR2HSV_FULL);
//	Convert RGB to HSV (FULL)->(0 - 255, 0-255, 0-255)
//
//	printf("     %d %d\n", mask.cols, mask.rows);
//	imshow("original", image);
//	imshow("hsv", img_hsv);
//	imshow("mask", mask);
//
//
//	int z = 0, branco = 0, h1 = 0, s1 = 0, v1 = 0, r = 0, g = 0, b = 0;
//
//	for (int x = 0; x < img_hsv.rows; x++){
//
//		for (int y = 0; y < img_hsv.cols; y++){
//
//			uchar m = mask.at<uchar>(x, y);
//
//			Vec3b p = img_hsv.at<Vec3b>(x, y);
//
//			h1 = p.val[0];
//			s1 = p.val[1];
//			v1 = p.val[2];
//
//			if (m != 0){
//
//				printf("H(entravetor)=%d, S(entravetor)=%d, V(entravetor)=%d\n", h1, s1, v1);
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
//	fprintf(arq, "quantidade pixel que entrou no vetor:%d\n", branco);
//	fprintf(arq, "\nImage:quantidade pixel linhas:%d\ colunas:%d e total:%d\n", img_hsv.rows, img_hsv.cols, (img_hsv.rows*img_hsv.cols));
//	fprintf(arq, "\nMask:quantidade pixel linhas:%d\ colunas:%d e total:%d\n", mask.rows, mask.cols, (mask.rows*mask.cols));
//
//	hist = normalizavetor(hist, branco, (h*s*v));
//	fprintf(arq, "Regiao_%s%d = [", regiao.c_str(), n);
//	for (int i = 0; i < (h*s*v); i++){
//		fprintf(arq, "%.2f ", hist[i]);
//	}
//	fprintf(arq, "];\n\n");
//
//	img_hsv.release();
//
//	fclose(arq);
//	return hist;
//
//	this->histograma = hist;
//}
//
//LINHA 236 - indice
//void printVertices(const char *arquivo_vertices){
//	strcpy(v, arquivo_vertices);
//	strcpy(aux, arquivo_vertices);
//
//	FILE *arq_g = fopen(strcat(v, ".txt"), "w"), *arq_gb = fopen(strcat(aux, "_ordem.bin"), "wb");
//	vector<float>Histograma;
//
//	for (int i = 0; i < indice.size(); i++){
//		fprintf(arq_g, "[%d] = ", i);
//		if (indice[i]->getType() == 1){
//			fprintf(arq_gb, "1 ");
//			Histograma = ((Hsv*)indice[i].get())->getHist();
//			for (int j = 0; j < Histograma.size(); j++)
//				fprintf(arq_g, "%.2f ", Histograma[j]);
//		}
//		else{
//			fprintf(arq_gb, "0 ");
//			fprintf(arq_g, "%s", ((Label*)indice[i].get())->getLabel().c_str());
//		}
//
//		fprintf(arq_g, "\n");
//	}
//	fclose(arq_g);
//	fclose(arq_gb);
//}
//
//void printGrafoB(const char *arquivo_grafo){
//	strcpy(v, arquivo_grafo);
//
//	FILE *arq_g = fopen(strcat(v, ".bin"), "wb");
//
//	fprintf(arq_g, "%d ", Matriz_Adjacencia.size());
//	for (int i = 0; i < Matriz_Adjacencia.size(); i++){
//		for (int j = 0; j < Matriz_Adjacencia.size(); j++)
//			fprintf(arq_g, "%d ", Matriz_Adjacencia[i][j]);
//		fprintf(arq_g, "\n");
//	}
//
//	fclose(arq_g);
//}
//
//void printGrafo(const char *arquivo_grafo){
//	char L = 'L';
//	char H = 'H';
//	strcpy(v, arquivo_grafo);
//
//	FILE *arq_g = fopen(strcat(v, ".txt"), "w");
//
//	fprintf(arq_g, "Matriz: %d\n\n", Matriz_Adjacencia.size());
//
//	for (int i = 0; i < Matriz_Adjacencia.size(); i++){
//		fprintf(arq_g, "%d-%c\t", i, indice[i]->getType() ? H : L);
//		for (int j = 0; j < Matriz_Adjacencia.size(); j++)
//			fprintf(arq_g, " %d ", Matriz_Adjacencia[i][j]);
//		fprintf(arq_g, "\n");
//	}
//
//	fclose(arq_g);
//}
//
//void MontaGrafo(Label l, Hsv h){
//
//	bool existia_H = false, existia_L = false;
//	int iH = 0, iL = 0;
//
//	set<unique_ptr<Vertice>>::iterator it_l = Vertices.find(unique_ptr<Vertice>(new Label(l)));
//	set<unique_ptr<Vertice>>::iterator it_h = Vertices.find(unique_ptr<Vertice>(new Hsv(h)));
//	std::pair<std::set<unique_ptr<Vertice>>::iterator, bool> insert_result;
//
//	if (it_l == Vertices.end()){
//		iL = Vertices.size();
//		unique_ptr<Vertice> new_l(new Label(l));
//		new_l->idx = iL;
//		insert_result = Vertices.insert(new_l);
//		it_l = insert_result.first;
//		indice.push_back((unique_ptr<Vertice>(new_l.get())));
//		cout << "cria vertice L" << endl;
//
//		Matriz_Adjacencia.resize(Matriz_Adjacencia.size() + 1);
//		for (int i = 0; i < Matriz_Adjacencia.size(); i++)
//			Matriz_Adjacencia[i].resize(Matriz_Adjacencia.size(), 0);
//	}
//
//	if (it_h == Vertices.end()){
//		iH = indice.size();
//		unique_ptr<Vertice> new_h(new Hsv(h));
//		new_h->idx = iH;
//		insert_result = Vertices.insert(new_h);
//		it_h = insert_result.first;
//		indice.push_back(unique_ptr<Vertice>(new_h.get()));
//		cout << "cria vertice H" << endl;
//
//		Matriz_Adjacencia.resize(Matriz_Adjacencia.size() + 1);
//		for (int i = 0; i < Matriz_Adjacencia.size(); i++)
//			Matriz_Adjacencia[i].resize(Matriz_Adjacencia.size(), 0);
//	}
//
//	cout << Matriz_Adjacencia.size() << endl;
//	printf("iH =%d   iL = %d\n\n", iH, iL);
//	Matriz_Adjacencia[it_h->get()->idx][it_l->get()->idx] += 1;
//	Matriz_Adjacencia[it_l->get()->idx][it_h->get()->idx] += 1;
//}
//
//horario inicio 00:19 19/02/2015
//horario termino ?? - Pamela's-Pc died
//
//entrada prompt: (pasta)imagens\imagem (hsv)0 0 0 (arquivos) Vertice Grafo
//int main(int argc, char* argv[]){
//
//	vector<float> histograma_vector;
//
//	char *nomearquivo = argv[1], nomearquivo_temp[500], *arq_vertice = argv[5], *arq_grafo = argv[6];
//	int arg_h = atoi(argv[2]), arg_s = atoi(argv[3]), arg_v = atoi(argv[4]);
//
//	SunDatabaseReader reader("/Users/pamela/Documents/IC/Study/project1/SUN2012_COMPLETA/SUN2012");
//
//	long long int qt = 0;
//
//	while (reader.hasNext()){
//
//		SupervisedImage i = reader.readNext();
//
//		char num[3];
//		itoa(qt, num, 10);
//
//		strcpy(nomearquivo_temp, nomearquivo);
//		strcat(nomearquivo_temp, num);
//		strcat(nomearquivo_temp, ".txt");
//
//		String path_image = i.getImagePath().toStdString();
//		Mat image = imread(path_image), image_show;
//
//		printf("\n\n %d -", qt);
//		printf("%s\n", path_image.c_str());
//		printf("Tamanho Image: %d %d\n", image.cols,image.rows);
//
//		resize(image, image_show, Size(image.cols / 4, image.rows / 4));
//		imshow("image_show", image_show);
//
//		for (int n = 0; n < i.getRegions().size(); n++){
//			printf("regiao: %s\n", i.getRegions()[n].getLabel().toStdString().c_str());
//
//			string label = i.getRegions()[n].getLabel().toStdString();
//			Label LABEL(label);
//
//			Mat mask = i.getRegions()[n].getMask(), mask_show;
//
//			resize(mask, mask_show, Size(mask.cols / 4, mask.rows / 4));
//			imshow("mask_show", mask_show);
//			waitKey(0);
//
//			Hsv HSV;
//			if ((mask.cols != 0 && mask.rows != 0) && (image.rows != 0 && image.cols != 0)){
//				HSV = Hsv(nomearquivo_temp, image, mask, arg_h, arg_s, arg_v, n, label);
//				MontaGrafo(LABEL, HSV);
//			}
//
//			imagens dando erro: 106 (mask) e 697(img) e 963(mask) e 2787(mask)
//			if (qt != 106 && qt != 697 && qt != 963 && qt != 1992 && qt != 2787){
//
//			HSV.show_hist();	
//			printf("%d", i.getRegions().size());
//		}
//
//		qt++;
//		printf("\n");
//		printGrafoB(arq_grafo);
//		printGrafo(arq_grafo);
//		printVertices(arq_vertice);
//
//		cout << path_image << endl;
//		fprintf(arq, "path image: %s\n",path_image);
//		image.release();
//	}
//
//	return 0;
//
//}