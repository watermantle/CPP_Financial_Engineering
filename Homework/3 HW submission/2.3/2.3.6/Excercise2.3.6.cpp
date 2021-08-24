// Test program to test circle class
#include "Point.hpp"		//	Include file "Point.hpp"
#include "Circle.hpp"//	Include file "Circle.hpp"
#include <sstream>
#include <iostream>
using namespace std;

int main() {
	// declare val_x and val_y for center point. r for radius
	double val_x, val_y, r, r2;
	//	Ask user to enter x and y
	cout << "Please enter x-coordinate for the center point\n";
	cin >> val_x;
	cout << "Please enter y-coordinate for the center point\n";
	cin >> val_y;
	//	declare center point cp
	Point cp(val_x, val_y);
	//	Ask user to enter radius
	cout << "Please enter the radius for the circle\n";
	cin >> r;
	//	Declare the circle with center point cp and radius r
	Circle cir(cp, r);
	//	Test ToString() method
	cout << "The circle " << cir.ToString() << " has been created with accepting cp and r\n\n";

	//	Create the second circle with the same parameters and setter method
	Circle cir2;
	cir2.CentrePoint(cp);
	cir2.Radius(r);
	//	Test properties functions
	cout << "The circle center " << cir2.CentrePoint().ToString() << " and radius of " << cir2.Radius() << " has been created with setter method"<< endl;
	cout << "The diameter of the circle is " << cir2.Diameter() << endl;
	cout << "The area of the circle is " << cir2.Area() << endl;
	cout << "The circumference of the circle is " << cir2.Circumference() << endl;
	return 0;
}