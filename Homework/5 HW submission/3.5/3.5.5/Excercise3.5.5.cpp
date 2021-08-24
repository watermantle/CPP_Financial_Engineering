/* Implement the shape class and make line, point, and circle as derived class*/
//	declar virtual in the base class to call destructors properly
//	Call Print() function that was only in Shape class for a template method pattern
#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

//	Declaration for a complete namespace
using namespace YuBai::CAD;
using namespace std;

int main() {
	//	declare an array of pointers
	Shape* shapes[10];
	shapes[0] = new Line;
	shapes[1] = new Point;
	shapes[2] = new Circle;
	shapes[3] = new Line;
	shapes[4] = new Point;
	shapes[5] = new Circle;
	shapes[6] = new Line(Point(3.5, 1.2), Point(5.0, 3.0));
	shapes[7] = new Point(1.0, 3.1);
	shapes[8] = new Circle(Point(1.0, 5.3), 10);
	shapes[9] = new Line(Point(1.0, 2.5), Point(3.4, 5.2));

	for (int i = 0; i != 10; i++) shapes[i]->Print();	//	Call Print() function for each
	for (int i = 0; i != 10; i++) delete shapes[i];		//	Delete all of objects

	return 0;
}  