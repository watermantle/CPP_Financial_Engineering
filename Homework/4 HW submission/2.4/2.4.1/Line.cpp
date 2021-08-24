// Implements the Line class defined in the header file Line.hpp
#include "Point.hpp"//	Include file "Point.hpp"
#include "Line.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

//	Default constructor, will create a line with (0, 0)s, as the default points are origins
Line::Line() {
	//cout << "A line is initialized with two origins\n";
}
//	constructor accepting two points to create a line with two points
Line::Line(const Point& p1, const Point& p2) : p_start(p1), p_end(p2) {
	//cout << "A line " << ToString() << " has been created" << endl;
}
//	Copy constructor
Line::Line(const Line& l) {
	p_start = l.p_start;
	p_end = l.p_end;
	//cout << "A copy constructor was called\n";
}
//	Assignment operator
Line& Line::operator = (const Line& source) {
	if (this == &source) {
		cout << "Self-assignment check\n";	//	Self-ssignment check
		return *this;
	};
	p_start = source.p_start;
	p_end = source.p_end;
	return *this;
}
//	Destructor
Line::~Line() {
	//cout << "The line with " << ToString() << " has been killed\n";
}

//	Getter method to return start-point with P1(), end-point with P2()
const Point& Line::P1() const {
	return p_start;
}
const Point& Line::P2() const {
	return p_end;
}

//	Setter method to set new points to the line
void Line::P1(const Point& p1) {
	p_start = p1;
	return;
}
void Line::P2(const Point& p2) {
	p_end = p2;
	return;
}

//	Return length of the line with embeded method Distance()
double Line::Length() const {
	return p_start.Distance(p_end);
}

//	Description of the line
std::string Line::ToString() const	{
	stringstream des;
	des << "start-" << p_start.ToString() << ",end-" << p_end.ToString();
	return des.str();
}