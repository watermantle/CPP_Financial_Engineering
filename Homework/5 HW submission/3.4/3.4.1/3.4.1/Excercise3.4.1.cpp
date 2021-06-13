/* to test colon syntax*/
#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
//	Declaration for a complete namespace
using namespace YuBai::CAD;
using namespace std;

int main() {
	/*My original code of Line defult constructor was
	Line(){} as member data fo Line are p_start and p_end that will be created with
	point's defualt constructor. If use colon syntax with given data, the Point's constructor
	Point(val_x, val_y) would be called*/ 

	/* Point constructor and destructor have been called two times. Line defualt constructor and 
	destructor have been called one time*/
	Line l;
	/* Points assignment operator will be called two times, line assignment operator will be called*/
	Line l1;
	l1 = l;
	/* Point constructor and destructor have been called one time. Circle defualt constructor and
	destructor have been called one time*/
	Circle cir;
	return 0;
}  