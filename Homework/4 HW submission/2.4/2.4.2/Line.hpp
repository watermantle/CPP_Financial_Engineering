//	Line header file. To define a class Line with start-and end-point
#ifndef Line_HPP
#define Line_HPP

#include <iostream>
#include <sstream>
#include "Point.hpp"
using namespace std;

class Line {
private:
	//	data for class Line, start-and end-point
	Point p_start, p_end;
public:
	//	constructors and destructor
	Line();
	Line(const Point& p1, const Point& p2);	//	Constructor accepting two values
	Line(const Line& l);					//	copy construtor
	Line& operator = (const Line& source);	//	Assignment operator
	~Line();								//	destructor

	//	Gettors for start- and end-point. P1() is start-point, P2() returns end_point
	const Point& P1() const;
	const Point& P2() const;

	//	Setters for start- and end-point. P1() for start-point, P2() to set end-point
	void P1(const Point& p1);
	void P2(const Point& p2);

	// Description function to return info of the line
	std::string ToString() const;

	// The length of the line
	double Length() const;
};

ostream& operator << (ostream& os, const Line& l);	//	Send to ostream
#endif
