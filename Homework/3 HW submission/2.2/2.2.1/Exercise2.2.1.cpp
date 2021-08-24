/*	A test program for the Point class. Should initial a point with default contrsuctor
New x and y value will be set with methods SetX() and SetY(). Descri[tion with ToString() and 
GetX(), GetY() methods*/
#include "Point.hpp"		//	Include file "Point.hpp"
#include <iostream>
using namespace std;

int main() {
	//	Create a Point using the default constructor.
	Point P;
	//	Declare x, and y coordinate
	double val_x, val_y;
	//	Out put the default point (0, 0). "Point(0,0)" is expected
	cout << "The default " << P.ToString() << endl;
	//	Ask user to enter value x and assign to val_x
	cout << "Please enter x-coordinate" << endl;
	cin >> val_x;
	//	Ask user to enter value y and assign to val_y
	cout << "Please enter y-coordinate" << endl;
	cin >> val_y;
	//	Set val_x and val_y to the x-coordinate and y-coordinate
	P.SetX(val_x);
	P.SetY(val_y);
	
	cout << P.ToString() << endl;		// Method ToString to get the description of the point
	//	Return a description of the point by using GetX() and GetY() methods.
	cout << "The x-coordinate is " << P.GetX() << " and the y-coordinate is " << P.GetY() << endl;
	
	return 0;
}