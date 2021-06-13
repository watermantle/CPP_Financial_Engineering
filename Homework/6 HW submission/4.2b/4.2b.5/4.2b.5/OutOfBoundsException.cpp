//	OutOfBoundsException source to implement the OutOfBoundsException class
#include "Exception.hpp"
#include <iostream>
#include <sstream>
using namespace std;


//	Defualt constructor
OutOfBoundsException::OutOfBoundsException() : ArrayException(), m_index(0) {}
//	Constructor with given data
OutOfBoundsException::OutOfBoundsException(int indx) : ArrayException(), m_index(indx) {}
//	Copy constructor
OutOfBoundsException::OutOfBoundsException(const OutOfBoundsException& source) : ArrayException(source), m_index(source.m_index) {}
//	Assignment operator
OutOfBoundsException& OutOfBoundsException::operator = (const OutOfBoundsException& source) {
	if (this == &source) {
		cout << "Self-assignment checked\n";
		return *this;
	}
	//	Call base class assignment
	ArrayException::operator = (source);
	m_index = source.m_index;
	return *this;
}
//	Destructor
OutOfBoundsException::~OutOfBoundsException() {}
//	Overriden GetMessage() funtion
string OutOfBoundsException::GetMessage() const {
	stringstream msg;
	msg << "given index " << m_index << " is out of bounds";
	return msg.str();
}