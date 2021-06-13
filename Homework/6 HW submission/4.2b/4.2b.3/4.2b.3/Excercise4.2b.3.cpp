//	to test Point Array that stores points also, Length() function to return 
//	the total length of points
#include <iostream>
#include "Array.hpp"
#include "Exception.hpp"
#include "PointArray.hpp"
#include <stdlib.h>

//	Declaration for a complete namespace
using namespace YuBai::Containers;
using namespace std;

int main() {
	//	Declare a point array with 10 elements
	PointArray arr_p(10);
	//	assign and display values
	for (int i = 0; i < arr_p.Size(); i++) {
		arr_p[i] = Point((rand() % 10), (rand() % 10));
		cout << arr_p[i] << endl;
	}
	//	to test Length() function
	cout << "The total length between the points in the array is " << arr_p.Length() << endl;

	/*
	it will return warning as the point array only has 1 element
	PointArray arr_p2(1);
	arr_p2[0] = Point(1, 2);
	cout << arr_p2.Length() << endl;*/

	return 0;
}  