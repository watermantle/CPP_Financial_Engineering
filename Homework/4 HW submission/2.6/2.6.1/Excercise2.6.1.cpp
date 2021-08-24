/* to test namespace*/
#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.hpp"

//	Declaration for a complete namespace
using namespace YuBai::Containers;
// shorter alias for Yourname::CAD
namespace YBCAD = YuBai::CAD;

int main() {
	//	full namespace for Point class
	YuBai::CAD::Point p1(1, 2);
	YuBai::CAD::Point p2(5, 3);
	cout << "The point is " << p1 << endl;
	//	Declaration for using a single class (Line)
	using YuBai::CAD::Line;
	cout << "The line is: " << Line(p1, p2) << endl;
	//	Declaration for a complete namespace
	Array arr(5);
	cout << "The array is: " << endl;
	for (int i = 0; i < arr.Size(); i++) {
		cout << arr[i] << endl;
	}
	// Create circle class by shorter alias
	YBCAD::Circle cir(p1, 5);
	cout << "The circle is " << cir << endl;
	return 0;
} 