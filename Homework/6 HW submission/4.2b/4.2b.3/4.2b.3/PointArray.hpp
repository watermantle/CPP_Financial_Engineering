//	PointArray header file to declare essential modules and functions
#ifndef PointArray_HPP
#define PointArray_HPP

#include <iostream>
#include "Array.hpp"
#include "Point.hpp"
using namespace std;
using namespace YuBai::CAD;

namespace YuBai {
	namespace Containers {
		class PointArray : public Array<Point> {
		private:
			//	The class has no member data
		public:
			PointArray();								//	default constructor
			PointArray(const PointArray& source);		//	copy constructor
			PointArray(const int& size);				//	constructor with given data
			~PointArray();								//	destructor

			//	operator
			PointArray& operator = (const PointArray& source);	//	assignment operator

			//	function
			double Length() const;
		};
	}
}

#endif