//	Header file of Stack class
#ifndef Stack_HPP
#define Stack_HPP

#include "Array.hpp"
#include <iostream>
using namespace std;

namespace YuBai {
	namespace Containers {
		template <typename T>
		class Stack {
		private:
			Array<T> m_arr;			//	member data of an array
			int m_current;			//	current index
		public:
			Stack();							//	Default constructor
			Stack(const Stack<T>& source);		//	copy constructor
			Stack(const int& size);				//	constructor with given size
			~Stack();							//	destructor

			//	operator
			//	Assignment operator
			Stack<T>& operator = (const Stack<T>& source);

			// functions
			//	store the elemenment at the current position and increment the current postion afterward
			void Push(const T& element);
			//	decrements the current position and returns the element
			const T& Pop();

		    /*int curentidx();
			T ele_arr(int idx);*/
		};
	}
}

#ifndef Stack_CPP
#include "Stack.cpp"
#endif

#endif