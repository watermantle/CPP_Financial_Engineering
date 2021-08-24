/* Implement the shape class and make line, point, and circle as derived class*/
//	declar virtual in the base class to call destructors properly
#include <iostream>
#include "Point.hpp"
#include "Line.hpp"

//	Declaration for a complete namespace
using namespace YuBai::CAD;
using namespace std;

int main() {
	//	to create an array of shape pointers
	Shape* shapes[3];
	shapes[0] = new Shape;
	shapes[1] = new Point;
	shapes[2] = new Line;
	for (int i = 0; i != 3; i++) delete shapes[i];
	/*
	The derived class destructors will not be called unless the destructor
	is declared virtual in the base class. Destructors now are called properly
	*/
	return 0;
}  