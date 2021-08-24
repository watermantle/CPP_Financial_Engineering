//	DimNotMatchException source to implement the DimNotMatchException class
#include "Exception.hpp"
#include <iostream>
#include <sstream>
using namespace std;

//	Defualt constructor
DimNotMatchException::DimNotMatchException() : ArrayException(), m_size(0) {}
//	Constructor with given data
DimNotMatchException::DimNotMatchException(int size) : ArrayException(), m_size(size) {}
//	Copy constructor
DimNotMatchException::DimNotMatchException(const DimNotMatchException& source) : ArrayException(source), m_size(source.m_size) {}
//	Assignment operator
DimNotMatchException& DimNotMatchException::operator = (const DimNotMatchException& source) {
	if (this == &source) {
		cout << "Self-assignment checked\n";
		return *this;
	}
	//	Call base class assignment
	ArrayException::operator = (source);
	m_size = source.m_size;
	return *this;
}
//	Destructor
DimNotMatchException::~DimNotMatchException() {}
//	Overriden GetMessage() funtion
string DimNotMatchException::GetMessage() const {
	return "Dimensions of the two arrays do not match\n";
}