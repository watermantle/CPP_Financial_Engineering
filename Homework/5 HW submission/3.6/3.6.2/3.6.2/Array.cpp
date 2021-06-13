// Array source file to implement array.hpp
#include <iostream>
#include "Array.hpp"
#include "Exception.hpp"

namespace YuBai {
	namespace Containers {
		//	Default constructor
		Array::Array() {
			m_size = 10;
			m_data = new CAD::Point[m_size];
			cout << "An array has been created with default construtor\n";
		}
		//	Constructor with the size of the array
		Array::Array(const int& arr_size) {
			m_size = arr_size;
			m_data = new CAD::Point[m_size];
			cout << "An array has been created with size of " << m_size << endl;
		}
		//	Copy constructor
		Array::Array(const Array& arr) {
				//	Set size and create a new array with the same size
				m_size = arr.m_size;
				m_data = new CAD::Point[arr.m_size];
				//	copy the element one by one
				for (int i = 0; i < m_size; i++) {
					m_data[i] = arr.m_data[i];
				}
		}
		//	Destructor
		Array::~Array() {
			delete[] m_data;
			cout << "Destructor of Array was called\n";
		}

		//	Getter of the size of the array
		int Array::Size() const {
			return m_size;
		}
		//	Setter to set an element to a specific location
		void Array::SetElement(const CAD::Point& p, const int idx) {
			if (idx >= m_size || idx < 0) {
				throw OutOfBoundsException(idx);		//	throw an error message
			}
			else {
				m_data[idx] = p;
			}
		}
		//	Getter to return a Point reference
		const CAD::Point& Array::GetElement(const int idx) const {
			if (idx >= m_size || idx < 0) {
				throw OutOfBoundsException(idx);		//	throw an error message
			}
			else {
				return m_data[idx];
			}
		}
		//	Operators
		//	Assignment operator
		Array& Array::operator = (const Array& source) {
			// To check if self-assignment by comparing every elelment
			if (this == &source) {
				cout << "Self-assignment check\n";
				return *this;
			}
			else {
				delete[] m_data;						//	Delete the Old array

				m_size = source.m_size;					//	Reassign m_size with the new size
				m_data = new CAD::Point[m_size];				//	Recreate an array
				for (int i = 0; i < m_size; i++) {
					m_data[i] = source.m_data[i];
				}
			}
			return *this;
		}

		//	[] operator to return a point reference
		CAD::Point& Array::operator [] (int idx) {
			if (idx >= m_size || idx < 0) {
				throw OutOfBoundsException(idx);		//	throw an error message
			}
			else {
				return m_data[idx];
			}
		}
		//	const version of [] operator to return a const point reference
		const CAD::Point& Array::operator [] (int idx) const {
			if (idx >= m_size || idx < 0) {
				throw OutOfBoundsException(idx);		//	throw an error message
			}
			else {
				return m_data[idx];
			}
		}
	}
}
