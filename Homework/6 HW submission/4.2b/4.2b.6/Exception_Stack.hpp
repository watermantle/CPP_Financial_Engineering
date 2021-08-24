//	stack exception header file for base class stackexception, and its derived classes
//	stackfullexception and stackemptyexception. Also, implements involved
#ifndef Exception_Stack_HPP
#define Exception_Stack_HPP
#include <iostream>
#include <sstream>
using namespace std;

class StackException {
private:
	//	No memeber data for this class
public:
	StackException() {};										//	default constructor
	StackException(const StackException& source) {};			//	copy constructor
	virtual ~StackException() {};								//	destructor
	
	//	assignment operator
	StackException& operator = (const StackException& source) {
		if (this == &source) {
			cout << "Self-assignment check\n";
		}
		return *this;
	};
	
	//	to return state of the stack
	virtual string GetMessage() const = 0;
};

class StackFullException : public StackException {
private:
	//	No memeber data for this class
public:
	StackFullException() {};									//	default constructor
	StackFullException(const StackFullException& source) {};	//	copy constructor
	~StackFullException() {};									//	destructor

	//	assignment operator
	StackFullException& operator = (const StackFullException& source) {
		if (this == &source) {
			cout << "Self-assignment check\n";
		}
		return *this;
	};
	
	//	to return state of the stack
	string GetMessage() const{
		stringstream msg;
		msg << "Stack is full.\n";
		return msg.str();
	}
};

class StackEmptyException : public StackException {
private:
	//	No memeber data for this class
public:
	StackEmptyException() {};									//	default constructor
	StackEmptyException(const StackEmptyException& source) {};	//	copy constructor
	~StackEmptyException() {};									//	destructor

	//	assignment operator
	StackEmptyException& operator = (const StackEmptyException& source) {
		if (this == &source) {
			cout << "Self-assignment check\n";
		}
		return *this;
	};

	//	to return state of the stack
	string GetMessage() const {
		stringstream msg;
		msg << "Stack is empty.\n";
		return msg.str();
	}
};
#endif