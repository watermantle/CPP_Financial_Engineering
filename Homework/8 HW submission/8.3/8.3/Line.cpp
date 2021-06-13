// Implements the Line class defined in the header file Line.hpp
//	implement shape class
#include "Point.hpp"//	Include file "Point.hpp"
#include "Line.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

namespace YuBai {
	namespace CAD {
		//	Default constructor, will create a line with (0, 0)s, as the default points are origins
		Line::Line() : Shape(), p_start(0.0, 0.0), p_end(0.0, 0.0) {
			//cout << "A line is initialized with two origins\n";
		}
		//	constructor accepting two points to create a line with two points
		Line::Line(const Point& p1, const Point& p2) : Shape(), p_start(p1), p_end(p2) {
			//cout << "A line has been created with given data" << endl;
		}
		//	Copy constructor
		Line::Line(const Line& l) : Shape(l), p_start(l.p_start), p_end(l.p_end) {
			//cout << "A copy constructor was called\n";
		}
		//	Assignment operator
		Line& Line::operator = (const Line& source) {
			if (this == &source) {
				cout << "Self-assignment check\n";	//	Self-ssignment check
				return *this;
			};
			//	Call Shape class assignment
			Shape::operator = (source);
			p_start = source.p_start;
			p_end = source.p_end;
			//cout << "Line assignment operator was called\n";
			return *this;
		}
		//	Destructor
		Line::~Line() {
			//cout << "The line has been killed\n";
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

		//Description of the line
		std::string Line::ToString() const {
			stringstream des;
			string s = Shape::ToString();
			des << s << ". start-" << p_start << ",end-" << p_end;
			return des.str();
		}

		//	Drawing simulation
		void Line::Draw() const {
			cout << "The drawing simulation of a line: -----\n";
		}

		//	Return length of the line with embeded method Distance()
		double Line::Length() const {
			return p_start.Distance(p_end);
		}
		//	Send to ostream
		ostream& operator << (ostream& os, const Line& l) {
			os << "start-" << l.p_start << ",end-" << l.p_end;
			return os;
		}
	}
}
