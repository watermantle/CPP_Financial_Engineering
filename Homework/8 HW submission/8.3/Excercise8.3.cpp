//	To test Smart Pointers with creating various shapes, including Point, Line
//	, and circle objects
#include <iostream>
#include <boost/variant.hpp>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Visitor.hpp"

using namespace std;
using namespace YuBai::CAD;

//	create a ShapeType variant
typedef boost::variant<Point, Line, Circle> ShapeType;
//	function to ask user to choose a shape
ShapeType CreateShape() {
	ShapeType shape;
	int type;
	//	intro text and ask user to enter a shape type
	cout << "Please enter a shape you want to create:\n1.Point, 2.Line, 3.Cicle\n";
	cin >> type;		//	get type from user
	switch (type) {
	case 1:
		shape = Point(3.14, 2.56);
		break;
	case 2:
		shape = Line(Point(), Point(2.53, 3.52));
		break;
	case 3:
		shape = Circle(Point(), 5);
		break;
	default:
		cout << "Bad input, a Point will create\n";
		shape = Point();
		break;
	}
	return shape;
}

int main() {
	//	decalre a shape object
	ShapeType shape;
	//	call CreateShape() function to ask user create a specific shape
	shape = CreateShape();
	cout << "A " << shape << " has been created\n";

	//	test exception
	try {
		Line l;							//	create a line object
		l = boost::get<Line>(shape);	//	try to assign shape to l
	}
	catch (boost::bad_get& err) {
		//	to print error message
		cout << "Error: " << err.what() << endl;
	}
	catch (...) {
		cout << "An unknown error has occurred\n";
	}

	//	to implement visitor
	Visitor visit(3.14, 1.41);				//	a visitor to move Shapes 
	boost::apply_visitor(visit, shape);
	cout << "The shape after shifting with x = 3.14 y = 1.41 is " << shape << endl;

	Point p(1, 2);
	Line l(Point(2, 2), Point(3, 4));
	Circle cir(Point(1, 1), 10);
	visit(p);
	visit(l);
	visit(cir);

	cout << p.ToString() << endl;
	cout << l.ToString() << endl;
	cout << cir.ToString() << endl;
	return 0;
}