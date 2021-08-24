//	Exception classes header files for both class ArrayException and its derived class OutOfBoundsException
#ifndef Exception_HPP
#define Exception_HPP
#include <iostream>

using namespace std;
//	Base class ArrayException
class ArrayException {
private:
	// No member data at this point
public:
	ArrayException();											//	Defualt constructor
	ArrayException(const ArrayException& source);				//	Copy constructor
	ArrayException& operator = (const ArrayException& source);	//	Assignment operator
	virtual ~ArrayException();									//	Destructor

	string virtual GetMessage() const = 0;						//	abstract GetMessage() function
};


//	derived class OutOfBoundsExcpetion
class OutOfBoundsException : public ArrayException {
private:
	int m_index;												//	member data to store the erronecous array index
public:
	OutOfBoundsException();										//	Defualt constructor
	OutOfBoundsException(const OutOfBoundsException& source);	//	Copy constructor
	OutOfBoundsException(int idx);								//	constructor with int argument
	//	Assignment operator
	OutOfBoundsException& operator = (const OutOfBoundsException& source);
	~OutOfBoundsException();									//	Desturctor

	string GetMessage() const;									//	Return the message that the index is out of bounds	
};
#endif