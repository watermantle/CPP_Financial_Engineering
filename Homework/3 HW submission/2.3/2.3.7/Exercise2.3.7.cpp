/*	A re-test program for the Point class. Should initial a point with default contrsuctor
New x and y value will be set with methods X(), and Y(), they will also return the value x, y
Also, the inline funtions are applied*/
#include "Point.hpp"		//	Include file "Point.hpp"
#include <iostream>
using namespace std;

int main() {
	// declare x, y-coordinate 
	double val_x, val_y;
	//	ask user to enter x, y
	cout << "Please enter x-coordinate\n";
	cin >> val_x;
	cout << "Please enter y-coordinate\n";
	cin >> val_y;
	
	//	declare a point P
	Point P(val_x, val_y);
	cout << "The point is " << P.ToString() << endl << endl;
	//	Ask user to enter now values
	cout << "Please enter a new x-coordinate\n";
	cin >> val_x;
	cout << "Please enter a new y-coordinate\n";
	cin >> val_y;
	//	Set new x, y value for the point P with inline functions
	P.X(val_x);
	P.Y(val_y);

	//	description with X(), Y(), inline functions
	cout << "Now P is Point(" << P.X() << ", " << P.Y() << ")\n";
	return 0;
}