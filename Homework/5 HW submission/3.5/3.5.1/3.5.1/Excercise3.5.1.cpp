/* Implement the shape class and make line, point, and circle as derived class*/
//	to test call ToString() function correctly. Keyword virtual was applied in Shape class
#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
//	Declaration for a complete namespace
using namespace YuBai::CAD;
using namespace std;

int main() {
	Point p(10, 20);						//	Create point
	Shape* sp;								//	Pointer to point p
	Shape* sp2;
	Shape* sp3;
	Line l(Point(1, 2), Point(5, 3));
	Circle cir(Point(1, 10), 10);
	sp = &p;
	sp2 = &l;
	sp3 = &cir;

	//	To test which ToString is called
	cout << sp->ToString() << endl;			//	Point::ToString() is called
	cout << sp2->ID() << endl;
	cout << sp3->ToString() << endl;
	cout << (*sp3).ID() << endl;
	//	Shape::ToString will be called if Shape::ToString is not a virtual function
	//	Point::ToString will be called if Shape::ToString is a virtual function
	return 0;
}  