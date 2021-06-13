/*	A test program for the Point class. Should initial a point with default contrsuctor
New x and y value will be set with methods X(), Y(), also they will return value x and y.
Also const function will be applied*/
#include "Point.hpp"		//	Include file "Point.hpp"
#include <iostream>
using namespace std;

int main() {
	//	Declare a point with a specific value pairs, ToString() will be called when it's been created
	const Point cp(1.5, 3.9), cp2(3.14, 2020);
	//	cp.X(0.3), can't be changed, a compiler error would raise
	
	//	Test const function X() and Y()
	cout << "x-coordinate of cp is " << cp.X() << ", y-coordinate of cp is " << cp.Y() << endl;
	//	Test const function Distance() to return the distance from orign
	cout << "The distance from " << cp.ToString() << " to origin is " << cp.Distance() << endl;
	//	Test const function Distance() to return the distance between two points
	cout << "The distance bewteen " << cp.ToString() << " and " << cp2.ToString() << " is " << cp.Distance(cp2) << endl;

	return 0;
}