// Implements the Circle class defined in the header file Circle.hpp
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#include <cmath>
#endif

#include "Point.hpp"		//	Include file "Point.hpp"
#include "Circle.hpp"		//	Include file "Circle.hpp"
#include <iostream>
#include <sstream>
using namespace std;

namespace YuBai {
	namespace CAD {
		//	Default constructor to create  a circle with (0,0) as center point and radius of 0
		Circle::Circle() : Shape(), m_centre_p(0, 0), m_radius(0) {
			//cout << "A default circle has been created\n";
		}
		//	Constructor accepting centre_point and radius to set up a circle
		Circle::Circle(const Point& centre_p, const double& radius) : Shape(), m_centre_p(centre_p), m_radius(radius) {
			//cout << "A circle has been created with given data\n";
		}
		//	Copy constructor
		Circle::Circle(const Circle& cir) : Shape(cir), m_centre_p(cir.m_centre_p), m_radius(cir.m_radius) {
			//cout << "Copy constructor has been called\n";
		}
		//	Assignment operator
		Circle& Circle::operator = (const Circle& source) {
			if (this == &source) {
				cout << "Self-assignment check\n";		// Self-assignment check
				return *this;
			}
			Shape::operator = (source);
			m_radius = source.m_radius;
			m_centre_p = source.m_centre_p;
			//cout << "Circle assignment operator was called\n";
			return *this;
		}
		//	Destructor
		Circle::~Circle() {
			//cout << "The circle has been killed\n";
		}

		//	Setter methods to set up center point and radius
		void Circle::CentrePoint(const Point& centre_p) {
			m_centre_p = centre_p;
			return;
		}
		void Circle::Radius(const double& radius) {
			m_radius = radius;
			return;
		}

		//	Getter methods to get current center point and radius
		const Point& Circle::CentrePoint() const {
			return m_centre_p;
		}
		double Circle::Radius() const {
			return m_radius;
		}

		//	Properties functions
		double Circle::Diameter() const {
			return m_radius * 2;
		}
		double Circle::Area() const {
			return pow(m_radius, 2) * M_PI;
		}
		double Circle::Circumference() const {
			return 2 * m_radius * M_PI;
		}

		//	Description
		std::string Circle::ToString() const {
			stringstream des;
			string s = Shape::ToString();
			des << s << ". Center " << m_centre_p << " radius of " << m_radius;
			return des.str();
		}

		//	drawing simulation
		void Circle::Draw() const {
			cout << "The drawing simulation of a cirle: O\n";
		}
		//	Send to ostream
		ostream& operator << (ostream& os, const Circle& cir) {
			os << "Center " << cir.m_centre_p << " radius of " << cir.m_radius;
			return os;
		}
	}
}