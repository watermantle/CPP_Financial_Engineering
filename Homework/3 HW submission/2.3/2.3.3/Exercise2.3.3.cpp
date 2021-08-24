/*	A test program for the Point class. Should initial a point with default contrsuctor
New x and y value will be set with methods X(), and Y(), they will also return the value x, y*/
#include "Point.hpp"		//	Include file "Point.hpp"
#include <iostream>
using namespace std;

int main() {
	//	Declare two origins P1, P2
	Point P1, P2;
	//	Declare x, and y coordinate
	double val_x, val_y;
	//	Ask user to enter value x for P1
	cout << "Please enter x-coordinate for the first point P1" << endl;
	cin >> val_x;
	//	Ask user to enter value y for P1
	cout << "Please enter y-coordinate for the first point P1" << endl;
	cin >> val_y;
	//	Test X()/Y() for SetX(), SetY()
	P1.X(val_x);
	P1.Y(val_y);
	//	Test X()/Y() for GetX(), GetY()
	cout << "P1 now is " << "Point(" << P1.X() << ", " << P1.Y() << ")\n";

	//	Ask user to enter value x for P2
	cout << "Please enter x-coordinate for the first point P2" << endl;
	cin >> val_x;
	//	Ask user to enter value y for P2
	cout << "Please enter y-coordinate for the first point P2" << endl;
	cin >> val_y;
	//	Test X()/Y() for SetX(), SetY()
	P2.X(val_x);
	P2.Y(val_y);
	//	Test X()/Y() for GetX(), GetY()
	cout << "P2 now is "<< "Point(" << P2.X() << ", " << P2.Y() << ")\n";

	//	Test Distrance() for DistranceOrigin()
	cout << "The distance from " << P1.ToString() << " to origin is " << P1.Distance() << endl;
	cout << "The distance from " << P2.ToString() << " to origin is " << P2.Distance() << endl;

	//	Distance between two points to test Distance()
	cout << "The distance between " << P1.ToString() << " and " << P2.ToString() << " is "<< P1.Distance(P2) << endl;
	return 0;
}