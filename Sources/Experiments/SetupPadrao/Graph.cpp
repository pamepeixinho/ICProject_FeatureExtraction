//#include "Graph.h"
//
//bool operator<(const unique_ptr<Vertice> &a, const unique_ptr<Vertice> &b){
//	return *a < *b;
//}
//
////variaveis auxiliares
//char v[60];
//char aux[60];
//
//void Grafo::printVerticesY(const char *arquivo_vertices){
//	strcpy(v, arquivo_vertices);
//	strcpy(aux, arquivo_vertices);
//
//	FILE *arq_g = fopen(strcat(v, ".txt"), "w"), *arq_gb = fopen(strcat(aux, "_ordem.bin"), "wb");
//	//vector<int>Histograma;
//	vector<int>Histograma;
//
//	for (int i = 0; i < indice.size(); i++){
//		fprintf(arq_g, "[%d] = ", i);
//		if (indice[i]->getType() == 2){
//			fprintf(arq_gb, "1 ");
//			Histograma = ((Hsv_DiscrY*)indice[i])->getHist_y();
//			for (int j = 0; j < Histograma.size(); j++)
//				fprintf(arq_g, "%d ", Histograma[j]);
//		}
//		else{
//			fprintf(arq_gb, "0 ");
//			fprintf(arq_g, "%s", ((Label*)indice[i])->getLabel().c_str());
//		}
//
//		fprintf(arq_g, "\n");
//	}
//
//	fclose(arq_g);
//	fclose(arq_gb);
//}
//void Grafo::printVerticesD(const char *arquivo_vertices){
//	strcpy(v, arquivo_vertices);
//	strcpy(aux, arquivo_vertices);
//
//	FILE *arq_g = fopen(strcat(v, ".txt"), "w"), *arq_gb = fopen(strcat(aux, "_ordem.bin"), "wb");
//	//vector<int>Histograma;
//	vector<float>Histograma;
//	for (int i = 0; i < indice.size(); i++){
//		fprintf(arq_g, "[%d] = ", i);
//		if (indice[i]->getType() == 1){
//			fprintf(arq_gb, "1 ");
//			Histograma = ((Hsv_Dist*)indice[i])->getHistDist();
//			for (int j = 0; j < Histograma.size(); j++)
//				fprintf(arq_g, "%.2f ", Histograma[j]);
//		}
//		else{
//			fprintf(arq_gb, "0 ");
//			fprintf(arq_g, "%s", ((Label*)indice[i])->getLabel().c_str());
//		}
//
//		fprintf(arq_g, "\n");
//	}
//
//	fclose(arq_g);
//	fclose(arq_gb);
//}
//
//void Grafo::printGrafoB(const char *arquivo_grafo){
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
//void Grafo::printGrafo(const char *arquivo_grafo){
//	char L = 'L';
//	char H = 'H';
//
//	strcpy(v, arquivo_grafo);
//
//	FILE *arq_g = fopen(strcat(v, ".txt"), "w");
//
//	fprintf(arq_g, "Matriz: %d\n\n", Matriz_Adjacencia.size());
//
//	for (int i = 0; i < Matriz_Adjacencia.size(); i++){
//		fprintf(arq_g, "%d-%c\t", i, indice[i]->getType() == 1 ? H : L);
//		for (int j = 0; j < Matriz_Adjacencia.size(); j++)
//			fprintf(arq_g, " %d ", Matriz_Adjacencia[i][j]);
//		fprintf(arq_g, "\n");
//	}
//
//	fclose(arq_g);
//}
//
//void Grafo::MontaGrafo(Label l, Hsv_Dist h){
//
//	bool it_b;
//	set<unique_ptr<Vertice>>::iterator it_l = Vertices.find(unique_ptr<Vertice>(new Label(l)));
//	printf("passou find label\n");
//	printf(it_l != Vertices.end() ? "achou L\n" : "nao achou L\n");
//
//	//set<unique_ptr<Vertice>>::iterator it_h = Vertices.find(unique_ptr<Vertice>(new Hsv_DiscrY(h)));
//	set<unique_ptr<Vertice>>::iterator it_h = Vertices.find(unique_ptr<Vertice>(new Hsv_Dist(h)));
//	printf("passou find Hist\n");
//	printf(it_h != Vertices.end() ? "achou H\n" : "nao achou H\n");
//
//	std::pair<std::set<unique_ptr<Vertice>>::iterator, bool> insert_result;
//
//	if (it_l == Vertices.end()){
//		printf("Entrei para criar Label\n");
//		unique_ptr<Vertice> new_l(new Label(l));
//		new_l->idx = indice.size();
//		insert_result = Vertices.insert(move(new_l));
//		it_l = insert_result.first;
//		it_b = insert_result.second;
//		indice.push_back(it_l->get());
//		printf(it_b ? "cria vertice L\n" : "Erro ao criar\n");
//
//		Matriz_Adjacencia.resize(Matriz_Adjacencia.size() + 1);
//		for (int i = 0; i < Matriz_Adjacencia.size(); i++)
//			Matriz_Adjacencia[i].resize(Matriz_Adjacencia.size(), 0);
//	}
//
//
//	if (it_h == Vertices.end()){
//		printf("Entrei para criar Hist**************\n");
//		unique_ptr<Vertice> new_h(new Hsv_Dist(h));
//		//unique_ptr<Vertice> new_h(new Hsv_DiscrY(h));
//		new_h->idx = indice.size();
//		insert_result = Vertices.insert(move(new_h));
//		it_h = insert_result.first;
//		it_b = insert_result.second;
//		indice.push_back(it_h->get());
//		printf(it_b ? "cria vertice H\n" : "Erro ao criar\n");
//
//		Matriz_Adjacencia.resize(Matriz_Adjacencia.size() + 1);
//		for (int i = 0; i < Matriz_Adjacencia.size(); i++)
//			Matriz_Adjacencia[i].resize(Matriz_Adjacencia.size(), 0);
//	}
//
//	//cout << Matriz_Adjacencia.size() << endl;
//	printf("iH =%d   iL = %d\n\n", it_h->get()->idx, it_l->get()->idx);
//	Matriz_Adjacencia[it_h->get()->idx][it_l->get()->idx] += 1;
//	Matriz_Adjacencia[it_l->get()->idx][it_h->get()->idx] += 1;
//}
//void Grafo::MontaGrafo(Label l, Hsv_DiscrY h){
//
//	bool it_b;
//	set<unique_ptr<Vertice>>::iterator it_l = Vertices.find(unique_ptr<Vertice>(new Label(l)));
//	printf("passou find label\n");
//	printf(it_l != Vertices.end() ? "achou L\n" : "nao achou L\n");
//
//	//set<unique_ptr<Vertice>>::iterator it_h = Vertices.find(unique_ptr<Vertice>(new Hsv_DiscrY(h)));
//	set<unique_ptr<Vertice>>::iterator it_h = Vertices.find(unique_ptr<Vertice>(new Hsv_DiscrY(h)));
//	printf("passou find Hist\n");
//	printf(it_h != Vertices.end() ? "achou H\n" : "nao achou H\n");
//
//	std::pair<std::set<unique_ptr<Vertice>>::iterator, bool> insert_result;
//
//	//print_teste();
//
//	if (it_l == Vertices.end()){
//		//printf("Entrei para criar Label\n");
//		unique_ptr<Vertice> new_l(new Label(l));
//		new_l->idx = indice.size();
//		insert_result = Vertices.insert(move(new_l));
//		it_l = insert_result.first;
//		it_b = insert_result.second;
//		indice.push_back(it_l->get());
//		printf(it_b ? "cria vertice L\n" : "Erro ao criar\n");
//
//		Matriz_Adjacencia.resize(Matriz_Adjacencia.size() + 1);
//		for (int i = 0; i < Matriz_Adjacencia.size(); i++)
//			Matriz_Adjacencia[i].resize(Matriz_Adjacencia.size(), 0);
//	}
//
//
//	if (it_h == Vertices.end()){
//		//printf("Entrei para criar Hist**************\n");
//		unique_ptr<Vertice> new_h(new Hsv_DiscrY(h));
//		//unique_ptr<Vertice> new_h(new Hsv_DiscrY(h));
//		new_h->idx = indice.size();
//		insert_result = Vertices.insert(move(new_h));
//		it_h = insert_result.first;
//		it_b = insert_result.second;
//		indice.push_back(it_h->get());
//		printf(it_b ? "cria vertice H\n" : "Erro ao criar\n");
//
//		Matriz_Adjacencia.resize(Matriz_Adjacencia.size() + 1);
//		for (int i = 0; i < Matriz_Adjacencia.size(); i++)
//			Matriz_Adjacencia[i].resize(Matriz_Adjacencia.size(), 0);
//	}
//
//	//cout << Matriz_Adjacencia.size() << endl;
//	printf("iH =%d   iL = %d\n\n", it_h->get()->idx, it_l->get()->idx);
//	Matriz_Adjacencia[it_h->get()->idx][it_l->get()->idx] += 1;
//	Matriz_Adjacencia[it_l->get()->idx][it_h->get()->idx] += 1;
//}
