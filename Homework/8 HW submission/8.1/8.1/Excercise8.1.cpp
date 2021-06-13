//	To test Smart Pointers with creating various shapes, including Point, Line
//	, and circle objects
#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.hpp"
#include "boost/shared_ptr.hpp"
using namespace std;
using namespace YuBai::CAD;
using namespace YuBai::Containers;

int main() {

	/*
	//	Typedef for a shared pointer to shape and
	//	a typedef for anarray with shapes stored as shared pointers
	typedef boost::shared_ptr<Shape> ShapePtr;
	typedef Array<ShapePtr> ShapeArray;

	//	decalre a shape array and store various shapes
	ShapeArray arr(3);
	arr[0] = ShapePtr(new Point);		//	one point
	arr[1] = ShapePtr(new Line);		//	a line and two points
	arr[2] = ShapePtr(new Circle);		//	a circle and one point

	//	Print each elements
	for (int i = 0; i < 3; i++) {
		arr[i]->Print();
	}
	//	at the end, 4 points, one line, and one circle will be deleted

	*/
	

	typedef boost::shared_ptr<Shape> Shape_Prt;
	typedef Array<Shape_Prt> ShapeArray;

	ShapeArray arr(5);
	arr[0] = Shape_Prt(new Point(1, 1));
	arr[1] = Shape_Prt(new Circle(Point(5, 5), 1));
	arr[2] = Shape_Prt(new Line(Point(1, 1), Point(1, 2)));
	arr[3] = Shape_Prt(new Point(1, 2));
	arr[4] = Shape_Prt(new Line(Point(1, 5), Point(3.14, 5.215)));

	for (int i = 0; i != arr.Size(); i++) {
		cout << arr[i]->ToString() << endl;
	}

	return 0;
}