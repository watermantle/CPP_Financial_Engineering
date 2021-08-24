// Implements the Point class defined in the header file Point.hpp
//	Operators overloading
#include "Point.hpp"		//	Include file "Point.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

namespace YuBai {
	namespace CAD {
		//	Default constructor with values of 0.0
		Point::Point() : m_x(0.0), m_y(0.0) {
			//cout << "An origin has been created\n";
		}
		Point::Point(const double& val_x, const double& val_y) : m_x(val_x), m_y(val_y) {
			//cout << ToString() << " has been created.\n";
		}
		Point::Point(const Point& P) {
			m_x = P.m_x;
			m_y = P.m_y;
			//cout << "Create " << ToString() << " with copy constructor\n";
		}
		Point::~Point() {
			//	Destructor with text
			//cout << "The point " << ToString() << " has been killed." << endl;
		}

		double Point::X() const {
			return m_x;					// GetX method to return x value
		}
		double Point::Y() const {
			return m_y;					// GetX method to return x value
		}
		double Point::Distance() const {
			//	Distance from (0, 0) with (x^2 + y^2)^(1/2)
			return sqrt(pow(m_x, 2) + pow(m_y, 2));
		}

		//	Calculate distance between two points with passing input point by reference
		double Point::Distance(const Point& p) const {
			double sum_sq;
			//	Two points distance with ((x1-x2)^2 + (y1-y2)^2) ^ (1/2)
			sum_sq = pow((m_x - p.m_x), 2) + pow((m_y - p.m_x), 2);
			return sqrt(sum_sq);
		}

		//	Operator overloading
		//	Negate the coordinates
		Point Point::operator -() const {
			return Point(-m_x, -m_y);
		}
		//	Scale the coordinates
		Point Point::operator * (double factor) const {
			return Point(factor * m_x, factor * m_y);
		}
		//	Add coordinates
		Point Point::operator + (const Point& P) const {
			return Point(m_x + P.m_x, m_y + P.m_y);
		}
		//	Equally compare operator
		bool Point::operator == (const Point& P) const {
			return (m_x == P.m_x) && (m_y == P.m_y);
		}
		//	Assignment operator
		Point& Point::operator = (const Point& source) {
			if (this == &source) {
				cout << "Self-assignment check\n";		//	Self-assignment check
				return *this;
			};
			m_x = source.m_x;
			m_y = source.m_y;
			return *this;
		}
		//	Scale the coordinates & assgin
		Point& Point::operator *= (double factor) {
			m_x *= factor;
			m_y *= factor;
			return *this;
		}
		//	Send description to ostream with member data
		ostream& operator << (ostream& os, const Point& P) {
			os << "Point(" << P.m_x << ", " << P.m_y << ")";
			return os;
		}
	}
}
