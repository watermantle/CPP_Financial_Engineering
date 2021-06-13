/*	Use friend to let << operator get accece to member data that should be private*/
#include <iostream>
#include "Point.hpp"
#include "Line.hpp"

using namespace std;

int main() {
	//	Declare a point to test << operator with friend method
	Point p(1.1, 3.1);
	cout << "The point p is " << p << endl;
	//	Declare a line to test << operator with friend method
	Line l(Point(1.2, 3.1), Point(5.1, 6.3));
	cout << "The line l with " << l << endl;
	return 0;
}