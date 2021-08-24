// Implements the Point class defined in the header file Point.hpp
#include "Point.hpp"		//	Include file "Point.hpp"
#include <iostream>
#include <sstream>
using namespace std;

//	Default constructor with values of 0.0
Point::Point() : m_x(0.0), m_y(0.0) {
	cout << "An origin has been created\n";
}
Point::~Point() {
	//	Destructor with text
	cout << "The point " << ToString() << " has been killed." << endl;
}

//	Getter method to return value x and y
double Point::GetX() {
	return m_x;					// GetX method to return x value
}
double Point::GetY() {
	return m_y;					// GetX method to return x value
}

//	Setter method to set new values to x and y
void Point::SetX(double newx) {
	m_x = newx;
	return;
}
void Point::SetY(double newy) {
	m_y = newy;
	return;
}

//	Return description of the point
std::string Point::ToString() {
	stringstream des;
	des << "Point(" << m_x << ", " << m_y << ")";
	return des.str();
}