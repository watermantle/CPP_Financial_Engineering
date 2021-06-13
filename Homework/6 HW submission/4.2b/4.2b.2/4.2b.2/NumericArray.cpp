//	to implement NumericArry file in header file
#ifndef NumericArray_CPP
#define NumericArray_CPP

#include "NumericArray.hpp"
#include "Exception.hpp"

#include <iostream>
using namespace std;

namespace YuBai {
	namespace Containers {
		//	default constructor
		template <typename T>				
		NumericArray<T>::NumericArray() : Array<T>() {};

		//	copy construtor
		template <typename T>
		NumericArray<T>::NumericArray(const NumericArray<T>& source) : Array<T>(source) {};

		//	constructor with given default size
		template <typename T>
		NumericArray<T>::NumericArray(const int& size) : Array<T>(size) {};

		//	destructor
		template <typename T>
		NumericArray<T>::~NumericArray() {};

		//	operators
		//	Assignment operator
		template <typename T>
		NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source) {
			if (this == &source) {
				cout << "Self-assignment checked\n";
			}
			else {
				Array<T>::operator = (source);
			}
			return *this;
		}

		//	scale the elements of the numeric array by a factor
		template <typename T>
		NumericArray<T> NumericArray<T>::operator * (const T& factor) const {
			NumericArray<T> scaled((*this).Size());	//	declare an empty array to store the scaled array
			for (int i = 0; i < (*this).Size(); i++) {
				scaled[i] = factor * (*this)[i];	//	stoce scaled elements
			}
			return scaled;
		}

		//	add the elements of two numeric arrays
		template <typename T>
		NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& arr_num) const {
			if ((*this).Size() == arr_num.Size()) {
				//	declare the output array
				NumericArray<T> arr_sum((*this).Size());
				for (int i = 0; i < (*this).Size(); i++) {
					arr_sum[i] = (*this)[i] + arr_num[i];
				}
				return arr_sum;
			}
			else {
				//	if two array sizes do not match, expetion raises
				throw DimNotMatchException();
			}
		}

		//	to return dot product of two arrays
		template <typename T>
		T NumericArray<T>::DotProduct(const NumericArray<T>& arr_num) const {
			if ((*this).Size() == arr_num.Size()) {
				//	declare the output
				T dp = 0;
				for (int i = 0; i < (*this).Size(); i++) {
					dp += (*this)[i] * arr_num[i];
				}
				return dp;
			}
			else {
				//	if two array sizes do not match, expetion raises
				throw DimNotMatchException();
			}
		}
	}
}
#endif