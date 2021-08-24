// Implements the Shape class defined in the header file Shape.hpp
#include "Shape.hpp"
#include <sstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

namespace YuBai {
	namespace CAD {
		//	Defualt constructor
		Shape::Shape() : m_id(rand()) {
			//cout << "A shape has been created\n";
		}
		//	Copy constructor
		Shape::Shape(const Shape& source) : m_id(source.m_id) {
			//cout << "A shape has been created with copy constructor\n";
		}
		//	Assignment operator
		Shape& Shape::operator = (const Shape& source) {
			//	Self-assignment check
			if (this == &source) {
				cout << "Self-assignment check\n";
				return *this;
			}
			//	copy m_id
			m_id = source.m_id;
			cout << "Shape assignment operator has been called\n";
			return *this;
		}
		//	Destructor
		Shape::~Shape() {
			//cout << "A Shape has been killed\n";
		}

		//	member functions 
		//	To return the id as string 
		string Shape::ToString() const {
			stringstream des;
			des << "ID: " << m_id;
			return des.str();
		}
		//	Print shape information for all derived class
		void Shape::Print() const {
			cout << ToString() << endl;
		}
		//	To retrieve the id of the shape
		int Shape::ID() const {
			return m_id;
		}
	}
}