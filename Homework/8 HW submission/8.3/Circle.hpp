/*	Circle header file. To define a class Circle representing a circle defined by center point, radius
Diameter, area, and circumference could be returned*/
#ifndef Circle_HPP
#define Circle_HPP

#include "Point.hpp"
#include "Shape.hpp"
#include <iostream>
#include <sstream>
using namespace std;

namespace YuBai {
	namespace CAD {
		class Circle : public Shape {
		private:
			Point m_centre_p;		//	member data of center point
			double m_radius;		//	member data of radius
		public:
			Circle();									//	Default constructor
			Circle(const Point& centre_p, const double& radius);	//	Constructor accepting cp and r
			Circle(const Circle& cir);					//	Copy constructor	
			Circle& operator = (const Circle& source);	//	Assignment operator
			~Circle();									//	Destructor

			//	Setter methods for center point and radius
			void CentrePoint(const Point& centre_p);			//	set center point for the circle
			void Radius(const double& radius);				//	set radius for the circle

			//	Getter methods for center point and radius
			const Point& CentrePoint() const;					//	Return centrepoint
			double Radius() const;						//	Return radius

			//	Properties functions
			double Diameter() const;					//	Return dismeter
			double Area() const;						//	Return area of the circle
			double Circumference() const;				//	Return circumference of the circle

			//	Description of the line
			std::string ToString() const;
			
			//	Drawing simulation
			void Draw() const;

			friend ostream& operator << (ostream& os, const Circle& cir);	//	Send to ostream
		};
	}
}
#endif