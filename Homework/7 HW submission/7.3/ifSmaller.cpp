//	implement ifSmaller header file
#include "ifSmaller.hpp"
#include <iostream>
using namespace std;

//	default constructor
ifSmaller::ifSmaller() : m_val(0.0) {}
//	copy constructor
ifSmaller::ifSmaller(const ifSmaller& source) : m_val(source.m_val) {}
//	constructor with given value
ifSmaller::ifSmaller(const double& val) : m_val(val) {}
//	destructor
ifSmaller::~ifSmaller() {}

//	operators
//	self-assignment operator
ifSmaller& ifSmaller::operator = (const ifSmaller& source) {
	if (this == &source) {
		//	self-assignment check
		cout << "Self-assignment check\n";
	}
	else {
		//	copy values
		m_val = source.m_val;
	}
	return *this;
}

//	overload operator to return a bool object if num less than m_val
bool ifSmaller::operator() (const double& num) const {
	return num < m_val;
}