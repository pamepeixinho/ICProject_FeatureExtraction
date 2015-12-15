#include "Orientacao.h"

#define _USE_MATH_DEFINES
#include <math.h>

Orientacao::Orientacao(){}
Orientacao::~Orientacao(){}
Orientacao::Orientacao( cv::Mat src, cv::Mat mask, int radius, int neighbors, int _fx[],int _fy[],int _cx[], int _cy[],
float _w1[],float _w2[],float _w3[],float _w4[], int soma,int disc){}

Orientacao::Orientacao(const Region &r, int discr):discr(discr){
	factory(r);
}

void Orientacao::factory(const Region &r){
	QList<QPoint>points =  makeQList(r);

	QPoint p1, p2;

	float distance = 0;
	for (auto p = points.begin(); p != points.end(); p++){
		for (auto q = points.begin(); q != points.end(); q++){
			if (this->distance(*p, *q) > distance){
				p1 = *p;
				p2 = *q;
			}
		}
	}
	QPoint rp = (p2 - p1);
	float angle = atan2(rp.y(), rp.x()) *180. / M_PI + 180;
	int v = discretiza(0, 360, this->discr, angle);
	printf("Orientacao = %d\n", v);
	this->orientacao = v;
}

Orientacao::Orientacao(const Region&, int, int, int){
}
Orientacao::Orientacao(cv::Mat, cv::Mat, int, int, int, int, string, float){
}


QList<QPoint> Orientacao::makeQList(const Region &r){
	QPolygon boundary = r.getBoundary();
	QList<QPoint>points;

	for (QPolygon::Iterator p = boundary.begin(); p != boundary.end(); p++)
		points.append(*p);
		
	return points;
}

float Orientacao::distance(QPoint a, QPoint b)const{
	return sqrt(pow(b.x() - a.x(), 2) + pow(b.y() - a.y(), 2));
}

int Orientacao::discretiza(float min, float max, float d, int val)const{
	val -= min;
	val = (val / (max - min)*d);
	if (val >= d)
		val = d - 1;
	return val;
}


int Orientacao::getType() const{
	return 4;
}

bool Orientacao::operator<(const Vertice& other) const{
	if (this->getType() != other.getType())
		return this->getType() < other.getType();

	const Orientacao *other_orientacao = dynamic_cast<const Orientacao*>(&other);
	return this->orientacao < other_orientacao->orientacao;
}

int Orientacao::getOrientacao()const{
	return this->orientacao;
}
