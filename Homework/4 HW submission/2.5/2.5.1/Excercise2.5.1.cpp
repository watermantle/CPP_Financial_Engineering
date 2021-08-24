/*	Dynamically creating objects */
#include <iostream>
#include "Point.hpp"

using namespace std;

int main() {
	//	create a point with default constructor
	Point* p1 = new Point;
	cout << "The point p1 created by default constructor is " << *p1 << endl;
	
	//	create a point with constructor with coordinates
	Point* p2 = new Point(5.1, 6.3);
	cout << "The point p2 created with assigned coordinates is " << *p2 << endl;

	//	create a point with copy constructor
	Point* p3 = new Point(*p2);
	cout << "The point p3 created with copy consturctor is " << *p3 << endl;

	//	Call the Distance() function
	cout << "The distance bewteen " << *p1 << " and " << *p2 << " is " << (*p1).Distance(*p2) << endl;
	//	delete point objects and arrays
	delete p1;
	delete p2;
	delete p3;

	//	declare and ask user to enter the size of the array
	int size;
	cout << "Please enter the size of the array\n";
	cin >> size;
	//	create an array of points with default constructor
	Point* arr_p = new Point[size];
	//	display the array of the points
	cout << "Display the array: \n";
	for (int i = 0; i < size; i++) {
		cout << arr_p[i] << endl;
	}

	//	delete the array
	delete[] arr_p;

	return 0;
} 