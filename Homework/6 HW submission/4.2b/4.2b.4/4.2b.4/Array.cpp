// Array source file to implement array.hpp
#ifndef Array_CPP
#define Array_CPP

#include <iostream>
#include "Array.hpp"
#include "Exception.hpp"

namespace YuBai {
	namespace Containers {
		//	Default constructor
		template <typename T>
		Array<T>::Array() {
			m_size = 10;
			m_data = new T[m_size];
			//cout << "An array has been created with default construtor\n";
		}
		//	Constructor with the size of the array
		template <typename T>
		Array<T>::Array(const int& arr_size) {
			m_size = arr_size;
			m_data = new T[m_size];
			cout << "An array has been created with size of " << m_size << endl;
		}
		//	Copy constructor
		template <typename T>
		Array<T>::Array(const Array<T>& arr) {
				//	Set size and create a new array with the same size
				m_size = arr.m_size;
				m_data = new T[arr.m_size];
				//	copy the element one by one
				for (int i = 0; i < m_size; i++) {
					m_data[i] = arr.m_data[i];
				}
		}
		//	Destructor
		template <typename T>
		Array<T>::~Array() {
			delete[] m_data;
			//cout << "Destructor of Array was called\n";
		}

		//	Getter of the size of the array
		template <typename T>
		int Array<T>::Size() const {
			return m_size;
		}
		//	Setter to set an element to a specific location
		template <typename T>
		void Array<T>::SetElement(const T& t, const int idx) {
			if (idx >= m_size || idx < 0) {
				throw OutOfBoundsException(idx);		//	throw an error message
			}
			else {
				m_data[idx] = t;
			}
		}
		//	To set default size of the array
		template <typename T>
		void Array<T>::DefaultSize(const unsigned int size_df) {
			size_default = size_df;
		}

		//	Getter to return a Point reference
		template <typename T>
		const T& Array<T>::GetElement(const int idx) const {
			if (idx >= m_size || idx < 0) {
				throw OutOfBoundsException(idx);		//	throw an error message
			}
			else {
				return m_data[idx];
			}
		}
		//	init default size of the array
		template <typename T>
		unsigned int Array<T>::size_default = 10;
		//	Getter to return the default size
		template <typename T>
		const unsigned int Array<T>::DefaultSize() {
			return size_default;
		}

		//	Operators
		//	Assignment operator
		template <typename T>
		Array<T>& Array<T>::operator = (const Array<T>& source) {
			// To check if self-assignment by comparing every elelment
			if (this == &source) {
				cout << "Self-assignment check\n";
				return *this;
			}
			else {
				delete[] m_data;						//	Delete the Old array

				m_size = source.m_size;					//	Reassign m_size with the new size
				m_data = new T[m_size];				//	Recreate an array
				for (int i = 0; i < m_size; i++) {
					m_data[i] = source.m_data[i];
				}
			}
			return *this;
		}

		//	[] operator to return a point reference
		template <typename T>
		T& Array<T>::operator [] (int idx) {
			if (idx >= m_size || idx < 0) {
				throw OutOfBoundsException(idx);		//	throw an error message
			}
			else {
				return m_data[idx];
			}
		}
		//	const version of [] operator to return a const point reference
		template <typename T>
		const T& Array<T>::operator [] (int idx) const {
			if (idx >= m_size || idx < 0) {
				throw OutOfBoundsException(idx);		//	throw an error message
			}
			else {
				return m_data[idx];
			}
		}
	}
}
#endif