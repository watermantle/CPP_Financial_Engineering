//	add Push() and Pop() functions to munipulate current index and return or store element
#include <iostream>
#include "Array.hpp"
#include "Stack.hpp"
#include "Exception.hpp"
#include <stdlib.h>

//	Declaration for a complete namespace
using namespace YuBai::Containers;
using namespace std;

int main() {
	//	declare a stack that has size of 5 with current index of 0
	Stack<double> stack(3);				//	current index: 0
	//	to test Push() function
	try {
		stack.Push(1.1);				//	current index: 1
		stack.Push(2.2);				//	current index: 2
		stack.Push(3.3);				//	current index: 3
		stack.Push(4.4);				//	exception raises, current index: 3	
	}
	catch (ArrayException& arrerr) {
		cout << arrerr.GetMessage() << endl;
		cout << "The stack is full " << endl;
	}
	catch (...) {
		cout << "An unknown error has occured\n";
	}
	//	to test Pop() function
	try {
		cout << stack.Pop() << endl;	//	current index: 2, return 3.3
		cout << stack.Pop() << endl;	//	current index: 1, return 2.2
		cout << stack.Pop() << endl;	//	current index: 0, return 1.1
		cout << stack.Pop() << endl;	//	exception raises, current index: 0	
	}
	catch (ArrayException& arrerr) {
		cout << arrerr.GetMessage() << endl;
	}
	catch (...) {
		cout << "An unknown error has occured\n";
	}
	return 0;
}  