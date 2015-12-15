#include "Area.h"

Area::Area()
{
}

Area::Area(int discr) :discr(discr)
{
}

Area::Area(float area, int discr) :area(area), discr(discr)
{
}
Area::Area(const Region &r, int t){}

Area::Area(cv::Mat a, cv::Mat b, int c, int d, int e, int f, std::string g, float h){
}

Area::Area(const Region &r, int discr, int width, int height) : discr(discr)
{
	this->area = 0;
	//printf("width*height = %d %d\n", width, height);
	int areaImg = width*height;
	//printf("width*height = %d\n", areaImg);

	QPolygon boundary = r.getBoundary();
	for (int i = 0; i < boundary.size() - 1; i++)
		area += ((1.0*boundary[i].x()*boundary[i + 1].y()) - (1.0*boundary[i].y()*boundary[i + 1].x()));
	area += ((1.0*boundary.last().x()*boundary[0].y()) - (1.0*boundary.last().y()*boundary[0].x()));

	area = fabs(area) / 2.0;
	//printf("1 ------- Area = %.2f\n", area);
	float areav = area / (1.0*areaImg);
	//printf("2 ------- %.2f = %.2f / %d\n",areav, area,areaImg);

	//discretizacao(area*discr) normalizado /discr
	this->area = ((int)(areav*discr)) / (float)discr;
	printf(" ------- Area = %f\n", area);
}

Area::Area(cv::Mat image, cv::Mat mask, int radius, int neighbors, int _fx[], int _fy[], int _cx[], int _cy[],
float _w1[], float _w2[], float _w3[], float _w4[], int soma, int disc){}

int Area::getType() const{
	return 3;
}

float Area::getArea()const{
	return this->area;
}

bool Area::operator<(const Vertice& other) const{
	if (this->getType() != other.getType())
		return this->getType() < other.getType();

	const Area *other_area = dynamic_cast<const Area*>(&other);
	return this->area < other_area->area;
	//return dist;
}

Area::~Area()
{
}
