/*	Implement the shape class and make line, point, and circle as derived class*/
//	to test try/catch code to deal with excpetion
//	catch statement will catch an ArrayException object and return 
#include <iostream>
#include "Point.hpp"
#include "Array.hpp"
#include "Exception.hpp"

//	Declaration for a complete namespace
using namespace YuBai::CAD;
using namespace YuBai::Containers;
using namespace std;

int main() {
	int idx;			//	declare an index variable
	Array arrp;			//	create an array of points with defualt number of elements of 10
	
	//	Intro text to ask user enter an index
	cout << "Please an index\n";
	cin >> idx;

	//	To test GetElement() function
	try {
		cout << arrp.GetElement(idx) << endl;
	}
	catch (ArrayException& arrerr) {
		//	out of bounds error message
		cout << "GetElement() function error " << arrerr.GetMessage() << endl;
	}
	catch (...) {
		//	unexpected error message
		cout << "An unknown error has raised\n";
	}

	//	To test SetElement() function
	try {
		arrp.SetElement(Point(3.0, 5.0), idx);
		cout << "New point is " << arrp.GetElement(idx) << endl;
	}
	catch (ArrayException& arrerr) {
		//	out of bounds error message
		cout << "SetElement() function error " << arrerr.GetMessage() << endl;
	}
	catch (...) {
		//	unexpected error message
		cout << "An unknown error has raised\n";
	}

	//	To test index operator
	try {
		arrp[idx] = Point(3.9, 8.0);
		cout << "New point is " << arrp[idx] << endl;
	}
	catch (ArrayException& arrerr) {
		//	out of bounds error message
		cout << "Index operator error " << arrerr.GetMessage() << endl;
	}
	catch (...) {
		//	unexpected error message
		cout << "An unknown error has raised\n";
	}
	return 0;
}  