//	NumericArray to apply some numeric operators
#ifndef NumericArray_HPP
#define NumericArray_HPP

#include "Array.hpp"
#include <iostream>
using namespace std;

namespace YuBai {
	namespace Containers {
		template<typename T>
		class NumericArray : public Array<T> {
		private:
			//	No member data for this calss
		public:
			NumericArray();										//	default constructor
			NumericArray(const NumericArray<T>& source);		//	copy constructor 
			NumericArray(const int& size);						//	constructor with given size
			~NumericArray();									//	destructor

			//	functions
			T DotProduct(const NumericArray<T>& arr_num) const;	//	return dot product of two arraies

			//	operators
			//	Assignment operator
			NumericArray<T>& operator = (const NumericArray<T>& source);
			//	scale the elements of the numeric array by a factor
			NumericArray<T> operator * (const T& factor) const;
			//	add the elements of two numeric arrays
			NumericArray<T> operator + (const NumericArray<T>& arr_num) const;
		};
	}
}

#ifndef NumericArray_CPP
#include "NumericArray.cpp"
#endif

#endif 
