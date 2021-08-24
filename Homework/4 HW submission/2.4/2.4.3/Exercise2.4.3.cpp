/*	Test new constructor that accepts only one argument to set both x and y coordinates*/
//	Declare the constructor as explicit
#include "Point.hpp"
#include <iostream>

using namespace std;

int main() {
	// the following code will compile and p will be converted to a double from a point if we don't set explicit
	// With "explicit" an error occurs as the Point(p) cannot be compare with the double(1.0)
	/*
	Point p(1.0, 1.0);
	if (p == 1.0) cout << "Equal!" << endl;
	else cout << "Not equal" << endl;*/

	//	Declared the constructor as explicit and apply
	Point p(1.0, 1.0);
	if (p == (Point) 1.0) cout << "Equal!" << endl;
	else cout << "Not equal" << endl;
	return 0;
}