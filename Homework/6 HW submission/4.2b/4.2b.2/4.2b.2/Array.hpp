// Header file of Array class
// templated version of Array class
#ifndef Array_HPP
#define Array_HPP

#include <iostream>

namespace YuBai {
	namespace Containers {
		template <typename T>
		class Array {
		private:
			// Dynamic C array of T objects
			T* m_data;
			//	size of the array
			int m_size;
			//	member data of default size
			static unsigned int size_default;
		public:
			Array();									//  Defualt constructor that creates 10 elements
			Array(const int& arr_size);					//	Create an array with a specific size
			Array(const Array<T>& arr);					//	Copy constructor
			virtual ~Array();							//	Destructor

			int Size() const;							//	Return the size of the array
			//	To set an element to a specific location
			void SetElement(const T& t, const int idx);
			//	To set default size of the array
			static void DefaultSize(const unsigned int size_df);

			//	To get the element reference with a specific index
			const T& GetElement(const int idx) const;
			//	Get default size
			const static unsigned int DefaultSize();

			// Operators
			Array<T>& operator = (const Array<T>& source);				//	Assignment opertor
			T& operator [] (int idx);						//	[] operator to either return or write elements
			const T& operator [] (int idx) const;			//	const version of [] operator
		};
	}
}

//	By include the code "Array.cpp", we don't need to include Array.cpp in the main program 
//	but include "Array.hpp" withous having to include .cpp again 
#ifndef Array_CPP
#include "Array.cpp"
#endif

#endif
