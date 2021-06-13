//	Point header file. To define a class Point representing a point in XY coordiante and methods
//	Inline functions applied. Normal inline for the getters and default inline for the setters
//	Operators overloading
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
	explicit Point(const double& val_xy);				//	Constructor to accept single argument
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
	double Distance(const Point& p) const;		//	input by reference

	//	Operator overloading 
	Point operator - () const;					//	Negate the coordinates
	Point operator * (double factor) const;		//	Scale the coordinates
	Point operator + (const Point& P) const;	//	Add coordinates
	bool operator == (const Point& P) const;	//	Equally compare operator
	Point& operator = (const Point& source);	//	Assignment operator
	Point& operator *= (double factor);			//	Scale the coodinates & assign
};

ostream& operator << (ostream& os, const Point& P); //	Send to ostream
#endif