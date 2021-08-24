/* Implement the shape class and make line, point, and circle as derived class*/
//	to test call ToString() function correctly. Keyword virtual was applied in Shape class
//	to call Shape::ToString() in Point::ToString()
#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
//	Declaration for a complete namespace
using namespace YuBai::CAD;
using namespace std;

int main() {
	Point p(10, 20);						//	Create point
	Line l(p, Point(5, 3));					//	Create line
	Circle cir(p, 10);						//	Create circle

	Shape* spp = &p;						//	Pointer to point p
	Shape* spl = &l;						//	Pointer to line l
	Shape* spc = &cir;						//	Pointer to circle cir

	//	to test if Shape::ToString() is properly called
	cout << spp->ToString() << endl;
	cout << spl->ToString() << endl;
	cout << spc->ToString() << endl;
	return 0;
}  