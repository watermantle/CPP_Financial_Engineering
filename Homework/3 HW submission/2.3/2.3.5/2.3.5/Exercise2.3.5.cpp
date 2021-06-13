/*	A test program for the Line class. Should initial a line with default contrsuctor with (0, 0)s
Next will test P1(), P2() to set up second line and Length() to return length of the line*/
#include "Point.hpp"		//	Include file "Point.hpp"
#include "Line.hpp"			//	Include file "Line.hpp"
#include <iostream>
using namespace std;

int main() {
	// Declare two values x, y to create a point
	double val_x, val_y;
	//	Ask user to enter x, y-coordinates
	cout << "Please enter x-coordinate of the start-point" << endl;
	cin >> val_x;
	cout << "Please enter y-coordinate of the start-point" << endl;
	cin >> val_y;
	//	Set up P1 with the assgined value val_x and val_y
	Point P1(val_x, val_y);

	//	Ask user to enter x, y-coordinates
	cout << "Please enter x-coordinate of the end-point" << endl;
	cin >> val_x;
	cout << "Please enter y-coordinate of the end-point" << endl;
	cin >> val_y;
	//	Set up P2 with the assgined value val_x and val_y
	Point P2(val_x, val_y);
	//	Set a line with accepting start-point P1 and end-point P2
	Line l1(P1, P2);
	//	To test ToString() method to return description
	cout << "The line " << l1.ToString() << " was created by accepeting two points\n\n";
	
	// Declare two values x, y to create a point
	cout << "Please enter x-coordinate of the start-point" << endl;
	cin >> val_x;
	cout << "Please enter y-coordinate of the start-point" << endl;
	cin >> val_y;
	//	Set up P3 with the assgined value val_x and val_y
	Point P3(val_x, val_y);

	// Declare two values x, y to create a point
	cout << "Please enter x-coordinate of the end-point" << endl;
	cin >> val_x;
	cout << "Please enter y-coordinate of the end-point" << endl;
	cin >> val_y;
	//	Set up P4 with the assgined value val_x and val_y
	Point P4(val_x, val_y);

	//	Declare a new line with defult constructor
	Line l2;
	//	Set up the line l2 with setter method
	l2.P1(P3);
	l2.P2(P4);
	//	To test P1() and P2() method. The copy constructor will be called. 
	cout << "The line with star-" << l2.P1().ToString() << " and end-" << l2.P2().ToString() << " was created by setter method\n";
	//	To test Length() to return the length of the line
	cout << "The length of the l2 is " << l2.Length() << endl << endl;
	return 0;
}