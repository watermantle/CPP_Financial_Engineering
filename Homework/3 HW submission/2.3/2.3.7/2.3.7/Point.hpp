//	Point header file. To define a class Point representing a point in XY coordiante and methods
//	Inline functions applied. Normal inline for the getters and default inline for the setters
#ifndef Point_HPP
#define Point_HPP

#include <iostream>
#include <sstream>
using namespace std;

class Point {
private:
	double m_x, m_y;			//	X, Y coordinate
public:
	//	Constructors & Destructor
	Point();					//	Default constructor
	Point(const double& val_x, const double& val_y);	//	New construtor to create a point with values
	Point(const Point& P);		//	a copy constructor
	~Point();

	//	Getter functions for the x-and y-coordinates
	double X() const;			//	Return x vlaue
	double Y() const;			//	Return y value

	//	Setter functions for the x-and y-coordinates, default inline functions
	void X(const double& newx) { m_x = newx; };		//	Set new value to x
	void Y(const double& newy) { m_y = newy; };		//	Set new value to y

	//	Description of the point 
	std::string ToString() const;

	double Distance() const;	//	Calculate the distance to the origin (0, 0)
	double Distance(const Point& p) const;	//	input by reference
};
#endif

//	Getter method to return value x and y inline function
inline double Point::X() const {
	return m_x;					// GetX method to return x value
}
inline double Point::Y() const {
	return m_y;					// GetX method to return x value
}