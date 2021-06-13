/*	A test program for the Point class. Should initial a point with default contrsuctor
New x and y value will be set with methods SetX() and SetY(). Descri[tion with ToString() and
GetX(), GetY() methods*/
#include "Point.hpp"		//	Include file "Point.hpp"
#include <iostream>
using namespace std;

int main() {
	//	Create a Point using the default constructor.
	Point P1, P2;
	//	Declare x, and y coordinate
	double val_x, val_y;
	//	Ask user to enter value x for P1
	cout << "Please enter x-coordinate for the first point P1" << endl;
	cin >> val_x;
	//	Ask user to enter value y for P1
	cout << "Please enter y-coordinate for the first point P1" << endl;
	cin >> val_y;
	//	Set val_x and val_y to the x-coordinate and y-coordinate for P1
	P1.SetX(val_x);
	P1.SetY(val_y);
	// Method ToString to get the description of the point
	cout << "The first point P1 is "<< P1.ToString() << endl;
	
	//	Ask user to enter value x for P2
	cout << "Please enter x-coordinate for the first point P2" << endl;
	cin >> val_x;
	//	Ask user to enter value y for P2
	cout << "Please enter y-coordinate for the first point P2" << endl;
	cin >> val_y;
	//	Set val_x and val_y to the x-coordinate and y-coordinate for P2
	P2.SetX(val_x);
	P2.SetY(val_y);
	// Method ToString to get the description of the point
	cout << "The second point P2 is " << P2.ToString() << endl << endl;
	
	//	Distance between two points
	cout << "The distance between " << P1.ToString() << " and " << P2.ToString() << " is " << P1.Distance(P2) << endl;
	return 0;
}