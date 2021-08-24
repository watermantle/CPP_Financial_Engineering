//	to test NumericArray class and its operator, functions. Also the exceptions when
//	two given arrays have different sizes. The NumericArray can't store Point objects
#include <iostream>
#include "Array.hpp"
#include "NumericArray.hpp"
#include "Exception.hpp"
#include <stdlib.h>

//	Declaration for a complete namespace
using namespace YuBai::Containers;
using namespace std;

int main() {
	//	Declare two numeric arrays
	NumericArray<double> arr1(12);
	NumericArray<double> arr2(10);
	
	//	to assign values to arr1, arr2 with random numbers in range(10)
	cout << "arr1:\n";
	for (int i = 0; i < arr1.Size(); i++) {
		arr1[i] = (rand() % 10);
		cout << arr1[i] << endl;
	}
	cout << "arr2:\n";
	for (int i = 0; i < arr2.Size(); i++) {
		arr2[i] = (rand() % 10);
		cout << arr2[i] << endl;
	}

	//	to test * operator which scaled up elements with fator times
	double factor = 2.5;
	NumericArray<double> arr3 = arr1 * factor;
	for (int i = 0; i < arr3.Size(); i++) {
		cout << arr3[i] << endl;
	}

	//	to test + operator. The results should be 3.5 times of arr1's elements
	NumericArray<double> arr4 = arr1 + arr3;
	for (int i = 0; i < arr3.Size(); i++) {
		cout << arr4[i] << endl;
	}
	//	in case two arrays have different sizes
	try {
		NumericArray<double> arr5 = arr1 + arr2;
	}
	catch (ArrayException& arrerr) {
		cout << arrerr.GetMessage() << endl;
	}
	catch (...) {
		cout << "An unknown error has occured" << endl;
	}

	//	to test DotProduct function
	cout << "The dot product of arr1 and arr3 is " << arr1.DotProduct(arr3) << endl;

	//	in case two arrays have different sizes
	try {
		cout << "The dot product of arr1 and arr2 is " << arr1.DotProduct(arr2) << endl;
	}
	catch (ArrayException& arrerr) {
		cout << arrerr.GetMessage() << endl;
	}
	catch (...) {
		cout << "An unknown error has occured" << endl;
	}
	return 0;
}  