//	ArrayException source to implement the ArrayExcption class
#include "Exception.hpp"
#include <iostream>
using namespace std;

//	Defualt constructor
ArrayException::ArrayException() {
	//	cout << "Defualt constructor of ArrayException has been called\n";
}
//	Copy constructor
ArrayException::ArrayException(const ArrayException& source) {};
//	Assignment operator
ArrayException& ArrayException::operator = (const ArrayException & source){
	if (this == &source) {
		cout << "Self-assignment checked\n";
	}
	return *this;
}
//	Destructor
ArrayException::~ArrayException() {};
