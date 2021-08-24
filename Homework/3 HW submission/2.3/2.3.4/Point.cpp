// Implements the Point class defined in the header file Point.hpp
#include "Point.hpp"		//	Include file "Point.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

//	Default constructor with values of 0.0
Point::Point() : m_x(0.0), m_y(0.0) {
	cout << "An origin has been created\n";
}
//	Constructor accepting two values
Point::Point(double val_x, double val_y) : m_x(val_x), m_y(val_y) {
	cout << ToString() << " has been created.\n";
}
//	Copy constructor
Point::Point(const Point& P) {
	m_x = P.m_x;
	m_y = P.m_y;
	cout << "Create " << ToString() << " with copy constructor\n";
}
//	Destructor
Point::~Point() {
	//	Destructor with text
	cout << "The point " << ToString() << " has been killed." << endl;
}

//	Getter method to return value x and y
double Point::X() const {
	return m_x;					// GetX method to return x value
}
double Point::Y() const {
	return m_y;					// GetX method to return x value
}

//	Setter method to set new values to x and y
void Point::X(double newx) {
	m_x = newx;
	return;
}
void Point::Y(double newy) {
	m_y = newy;
	return;
}

//	Return description of the point
std::string Point::ToString() const {
	stringstream des;
	des << "Point(" << m_x << ", " << m_y << ")";
	return des.str();
}

double Point::Distance() const {
	//	Distance from (0, 0) with (x^2 + y^2)^(1/2)
	return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

//	Calculate distance between two points with passing input point by reference
double Point::Distance(const Point& p) const {
	double sum_sq;
	//	Two points distance with ((x1-x2)^2 + (y1-y2)^2) ^ (1/2)
	sum_sq = pow((m_x - p.m_x), 2) + pow((m_y - p.m_y), 2);
	return sqrt(sum_sq);
}