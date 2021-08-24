//	Header file of Stack class
#ifndef Stack_HPP
#define Stack_HPP

#include "Array.hpp"
#include <iostream>
using namespace std;

namespace YuBai {
	namespace Containers {
		template <typename T, int size>
		class Stack {
		private:
			Array<T> m_arr;			//	member data of an array
			int m_current;			//	current index
		public:
			Stack();							//	Default constructor
			Stack(const Stack<T, size>& source);//	copy constructor
			~Stack();							//	destructor

			//	operator
			//	Assignment operator
			Stack<T, size>& operator = (const Stack<T, size>& source);

			// functions
			//	store the elemenment at the current position and increment the current postion afterward
			void Push(const T& element);
			//	decrements the current position and returns the element
			const T& Pop();
		};
	}
}

#ifndef Stack_CPP
#include "Stack.cpp"
#endif

#endif