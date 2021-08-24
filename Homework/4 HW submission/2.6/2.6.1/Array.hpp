// Header file of Array class
#ifndef Array_HPP
#define Array_HPP
#include "Point.hpp"
#include <iostream>

namespace YuBai {
	namespace Containers {
		class Array {
		private:
			// Dynamic C array of Point objects
			CAD::Point* m_data;
			//	size of the array
			int m_size;
		public:
			Array();									//  Defualt constructor that creates 10 elements
			Array(const int& arr_size);					//	Create an array with a specific size
			Array(const Array& arr);					//	Copy constructor
			~Array();									//	Destructor

			int Size() const;							//	Return the size of the array
			//	To set an element to a specific location
			void SetElement(const CAD::Point& p, const int idx);
			//	To get the element reference with a specific index
			const CAD::Point& GetElement(const int idx) const;

			// Operators
			Array& operator = (const Array& source);				//	Assignment opertor
			CAD::Point& operator [] (int idx);						//	[] operator to either return or write elements
			const CAD::Point& operator [] (int idx) const;			//	const version of [] operator
		};
	}
}
#endif
