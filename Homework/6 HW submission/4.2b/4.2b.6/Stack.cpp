//	source file to Implement Stack class header file
#ifndef Stack_CPP
#define Stack_CPP
#include "Stack.hpp"
#include "Exception_Stack.hpp"
#include <iostream>

namespace YuBai {
	namespace Containers {
		//	default constructor
		template <typename T, int size>
		Stack<T, size>::Stack() : m_arr(size), m_current(0) {}
		
		//	copy constructor
		template <typename T, int size>
		Stack<T, size>::Stack(const Stack<T, size>& source) : m_arr(source.m_arr), m_current(source.m_current) {}

		//	destructor
		template <typename T, int size>
		Stack<T, size>::~Stack() {}

		//	operator 
		template <typename T, int size>
		Stack<T, size>& Stack<T, size>::operator = (const Stack<T, size>& source) {
			if (this == &source) {
				cout << "Self-assignment check\n";
			}
			else {
				//	copy member data
				m_arr = source.m_arr;
				m_current = source.m_current;
			}
			return *this;
		}

		//	functions
		//	store the elemenment at the current position and increment the current postion afterward
		template <typename T, int size>
		void Stack<T, size>::Push(const T& element) {
			try {
				//	Store element at current index
				m_arr[m_current] = element;
				m_current++;		//	increment current index
			}
			catch (ArrayException&) {
				//	throw StackFullException of current index is greater than size
				throw StackFullException();
			}
			catch (...) {
				cout << "An unknown error has occured\n";
			}
		}

		//	decrements the current position and returns the element
		template <typename T, int size>
		const T& Stack<T, size>::Pop(){
			try {
				if (m_current < 1) {
					//	m_current will not change in this case.
					return m_arr[m_current - 1];	//	This will target exception
				}
				else {
					return m_arr[--m_current];		//	index decrements and return element
				}
			}
			catch (ArrayException&) {
				//	throw StackEmptyExcpetion if current index is 0 and it calls Pop()
				throw StackEmptyException();
				m_current = 0;
			}
			catch (...) {
				cout << "An unknown error has occured\n";
			}
		}
	}
}

#endif