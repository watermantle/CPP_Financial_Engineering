/* To test Array class and its methods and functions*/
#include <iostream>
#include "Point.hpp"
#include "Array.hpp"

using namespace std;

int main() {
	int arr_size;
	// intro text and ask user to enter the size of the array
	cout << "Please enter the size of the array:\n";
	cin >> arr_size;
	//	Create an array of points with default constructor
	Array arr1;
	//	copy constructor
	Array arr2(arr1);
	//	Create an array with a specific size
	Array arr3(arr_size);
	// Test [] for setter
	for (int i = 0; i < arr3.Size(); i++) {
		arr3[i] = Point(5 + i, 6 + i);
	}
	//	Test [] for getter
	cout << "The points in array3 are: \n";
	for (int i = 0; i < arr3.Size(); i++) {
		cout << arr3[i] << endl;
	}
	//	out bounds case
	cout << "If the index is out of bounds: \n";
	arr3[arr3.Size() + 1];
	// Test setter, SetElement()
	int idx;					//	Index of the element user wants to set
	double val_x, val_y;		//	x, y coodinates of the point user wants to insert
	cout << "Please enter the index: \n";
	cin >> idx;
	cout << "Please enter the x-coodinate\n";
	cin >> val_x;
	cout << "Please enter the y-coodinate\n";
	cin >> val_y;

	Point p(val_x, val_y);		//	Declare the point
	arr3.SetElement(p, idx);	//	set the element of arr3
	if (idx > arr3.Size()) {
		arr3.GetElement(idx);	//	Return the first elelment and raises an error
	}
	else{
		cout << "The element just set is: " << arr3.GetElement(idx) << endl;
	}
	//	This will return a self-assignment check since arr1 == arr2
	arr1 = arr2;
	//	To test assignment operator
	Array arr4;
	arr4 = arr3;
	cout << "Array4 is created with assignment operator, which is \n";
	for (int i = 0; i < arr4.Size(); i++) {
		cout << arr4[i] << endl;
	}

	//	Test const version of []
	const Array arr5 = arr3;
	cout << endl << "The first point of array5 is "<< arr5[0] << endl;		//	const version of [] was called
	return 0;
} 