// Test added operators in Point class
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>
#include <sstream>
using namespace std;

int main() {
	//	Decalre x, y coordinates
	double val_x, val_y;
	//	Intro text
	cout << "Please enter x-coordinate for the point\n";
	cin >> val_x;
	cout << "Please enter y-coordinate for the point\n";
	cin >> val_y;
	//	Create a point with x, y
	Point P(val_x, val_y);
	Point P1(val_x, val_y);		// Test compare operator later on
	cout << "The point entered is " << P.ToString() << endl;
	//	Test - operator
	Point P2 = -P;
	cout << "The negated point is " << P2.ToString() << endl;
	//	Test Scale operator
	double factor;
	cout << "Please enter the scale factor\n";
	cin >> factor;
	Point P3 = P * factor;
	cout << factor << " times of " << P.ToString() << " is " << P3.ToString() << endl;
	//	Test addition
	Point P4(3.14, 5.01);		//	Addtional point to test addition
	cout << "P4 is " << P4.ToString() << endl;

	Point P5 = P + P4;
	cout << "The addition of " << P.ToString() << " and " << P4.ToString() << " is " << P5.ToString() << endl;
	//	Test equally compare operator
	cout << P.ToString() << " and " << P1.ToString() << " are " << (P == P1 ? "Equal" : "Not equal") << endl;
	cout << P.ToString() << " and " << P2.ToString() << " are " << (P == P2 ? "Equal" : "Not equal") << endl;
	//	Scale the coordinate & assign
	P4 *= factor;
	cout << "The " << factor << " times of P4 is " << P4.ToString() << endl << endl;

	//	Test assignment operator for line class
	Line l1(P1, P2);
	Line l2(P3, P4);
	cout << "Line l1 with " << l1.ToString() << endl;
	cout << "Line l2 with " << l2.ToString() << endl;
	l1 = l2;
	cout << "Now line l1 with " << l1.ToString() << endl << endl;

	//	Test assignment operator for circle class
	Circle cir1(P1, 4);
	Circle cir2(P2, 5);
	cout << "Circle cir1 with " << cir1.ToString() << endl;
	cout << "Circle cir2 with " << cir2.ToString() << endl;
	cir1 = cir2;
	cout << "Now circle cir1 with " << cir1.ToString() << endl << endl;
	return 0;
}