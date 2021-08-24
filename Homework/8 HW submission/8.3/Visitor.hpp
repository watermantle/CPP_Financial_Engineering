//	Visitor header file. A class that implements boost::static_visitor<T>

#ifndef Visitor_HPP
#define Visitor_HPP

#include <iostream>
#include "boost/variant.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
using namespace YuBai::CAD;
using namespace std;

class Visitor : public boost::static_visitor<void> {
private:
	//	member data
	double m_dx, m_dy;				//	moves for x/y-coordinate
public:
	Visitor();						//	default constructor
	Visitor(const Visitor& source);	//	copy constructor
	Visitor(double x, double y);	//	constructor with given values
	virtual ~Visitor();				//	destructor

	//	operators
	Visitor& operator = (const Visitor& source);	//	assignment operator
	void operator () (Point& p) const;				//	to visit a point
	void operator () (Line& l) const;				//	to visit a line
	void operator () (Circle& c) const;				//	to visit a circle
};
#endif