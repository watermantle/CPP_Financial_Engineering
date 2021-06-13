//	Point header file. To define a class Point representing a point in XY coordiante and methods
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
	Point(double val_x, double val_y);	//	New construtor to create a point with values
	Point(const Point& P);		//	a copy constructor
	~Point();

	//	Getter functions for the x-and y-coordinates
	double X();				//	Return x vlaue
	double Y();				//	Return y value

	//	Setter functions for the x-and y-coordinates
	void X(double newx);		//	Set new value to x
	void Y(double newy);		//	Set new value to y

	//	Description of the poinr
	std::string ToString();

	double Distance();	//	Calculate the distance to the origin (0, 0)
	double Distance(const Point& p);	//	input by reference
};
#endif