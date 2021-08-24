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
	~Point();

	//	Getter functions for the x-and y-coordinates
	double GetX();				//	Return x vlaue
	double GetY();				//	Return y value

	//	Setter functions for the x-and y-coordinates
	void SetX(double newx);		//	Set new value to x
	void SetY(double newy);		//	Set new value to y

	//	Description of the poinr
	std::string ToString();

	double DistanceOrigin();	//	Calculate the distance to the origin (0, 0)
	double Distance(Point p);	//	Calculate the distance between two points
};
#endif