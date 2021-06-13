//	source file to implement PointArray header file
#include "Array.hpp"
#include "PointArray.hpp"
#include <iostream>


namespace YuBai {
	namespace Containers {
		//	default constructor
		PointArray::PointArray() : Array<Point>() {}
		//	copy constructor
		PointArray::PointArray(const PointArray& source) : Array<Point>(source) {}
		//	constructor with given value
		PointArray::PointArray(const int& size) : Array<Point>(size) {}
		//	destructor
		PointArray::~PointArray() {}

		//	operator
		PointArray& PointArray::operator = (const PointArray& source) {
			if (this == &source) {
				cout << "Self-assignment check\n";
			}
			else {
				Array<Point>::operator = (source);
			}
			return *this;
		}
		
		//	funtions
		double PointArray::Length() const {
			//	to check if the point array has two or more points
			if ((*this).Size() < 2) {
				cout << "The function only supports Point Array with at least two points\n";
			}
			else {
				double sum_res = 0;
				for (int i = 0; i < (*this).Size()-1; i++) {
					sum_res += (*this)[i].Distance((*this)[i + 1]);
				}
				return sum_res;
			}
		}
	}
}
