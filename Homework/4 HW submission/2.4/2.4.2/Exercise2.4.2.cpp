//	To test overloading operator << that sends descriptions without using ToString()
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>
using namespace std;

int main() {
	//	Declare a point P and test << for a descrtion without ToString()
	Point p(1, 2);
	cout << "The point P is " << p << endl << endl;

	//	Declare a Line l and test << for a descrtion without ToString()
	Line l(Point(1, 3), Point(2, 3));
	cout << "The line l with " << l << endl << endl;

	//	Declare a Cricle cir and test << for a descrtion without ToString()
	Circle cir(Point(5, 3), 5);
	cout << "The circle cir with " << cir << endl;
	return 0;
}