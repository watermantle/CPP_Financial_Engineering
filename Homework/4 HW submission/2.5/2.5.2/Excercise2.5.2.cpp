/*	Dynamically creating objects
create array of pointers with constructor other than the default constructor*/
#include <iostream>
#include "Point.hpp"

using namespace std;

int main() {
	//	Create a arr with three points
	Point** arr_pp = new Point*[3];
	//	Create for each element in the array a point
	for (int i = 0; i < 3; i++){
		arr_pp[i] = new Point (5 + i, 6 + i);
	}
	//	Point out each item, dereference
	for (int i = 0; i < 3; i++) {
		cout << *arr_pp[i] << endl;
	}
	
	//	Delete each point
	for (int i = 0; i < 3; i++) {
		delete arr_pp[i];
	}
	//	delete the array
	delete[] arr_pp;

	return 0;
} 