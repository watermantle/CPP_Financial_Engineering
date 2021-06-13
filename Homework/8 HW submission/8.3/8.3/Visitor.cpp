//	source file to implement Visitor header file
#include "Visitor.hpp"
#include <iostream>
using namespace std;

Visitor::Visitor() : m_dx(0.0), m_dy(0.0) {};		//	default constructor
//	copy constructor
Visitor::Visitor(const Visitor& source) : m_dx(source.m_dx), m_dy(source.m_dy) {};
//	constructor with given values
Visitor::Visitor(double x, double y) : m_dx(x), m_dy(y) {};
//	destructor
Visitor::~Visitor() {}

//	operators
//	assignment operator
Visitor& Visitor::operator = (const Visitor& source) {
	if (this == &source) {
		cout << "self-assignment check";
	}
	else {
		//	call base class
		boost::static_visitor<void>::operator = (source);

		//	assign member data from source
		m_dx = source.m_dx;
		m_dy = source.m_dy;
	}
	return *this;
}

//	operators to visit various shapes objects
void Visitor::operator () (Point& p) const {
	p.X(p.X() + m_dx);
	p.Y(p.Y() + m_dy);
}
void Visitor::operator () (Line& l) const {
	//	assign start or end points with the values of 
	//	original points adding to a modified values. + operator to sum two points
	l.P1(l.P1() + Point(m_dx, m_dy));
	l.P2(l.P2() + Point(m_dx, m_dy));
}
void Visitor::operator () (Circle& c) const {
	//	assign center point with the values of 
	//	original points adding to a modified values. + operator to sum two points
	c.CentrePoint(c.CentrePoint() + Point(m_dx, m_dy));
}