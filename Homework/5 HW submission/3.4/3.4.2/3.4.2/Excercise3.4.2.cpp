/* Implement the shape class and make line, point, and circle as derived class*/
#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
//	Declaration for a complete namespace
using namespace YuBai::CAD;
using namespace std;

int main() {
	Shape s;								//	Create shape
	Point p(10, 20);						//	Create point
	Line l(Point(1, 2), Point(3, 4));		//	Create line

	cout << s.ToString() << endl;			//	Print shape
	cout << p.ToString() << endl;			//	Print point
	cout << l.ToString() << endl;			//	Print line

	cout << "Shape ID: " << s.ID() << endl;	//	ID of the shape
	cout << "Point ID: " << p.ID() << endl; //	ID of the point. Does this work?
	/* Yes, it works. ID() will call the public member of the base class (Shape).
	Point class will inherit functions from Shape class*/

	cout << "Line ID: " << l.ID() << endl; //	ID of the line. Does this work?
/* Yes, it works. ID() will call the public member of the base class (Shape).
Line class will inherit functions from Shape class*/

	Shape* sp;								//	Create pointer to a shape variable.
	sp = &p;								//	Point in a shape variable. Possible?
	/*Yes, it is possible to point to a shape variable as the point class is derived from
	Shape class. sp will store the address of the point*/
	cout << sp->ToString() << endl;			//	What is printed
	/*ID: 18467. It will print out the id of the point as complier does not know which level of ToString() function we called
	so it just returns the result from its base class level*/
	
	//	Create and copy Point p to new point
	Point p2;
	p2 = p;
	cout << p2 << ", " << p2.ID() << endl;	//	Is the ID copied if you do not call
											//	the base class assignment in point?
	/*The ID would not be copied if shape (base) class assignment was not called in point
	or meaning, if we did't set Shape::operator = (source); in Point = operator, the id
	would not be copied*/
	return 0;
}  