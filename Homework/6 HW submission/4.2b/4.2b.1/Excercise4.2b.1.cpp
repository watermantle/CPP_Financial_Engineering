//	Implement templated version of Array class
//	To test static variable for array default size
#include <iostream>
#include "Array.hpp"
#include "Exception.hpp"

//	Declaration for a complete namespace
using namespace YuBai::Containers;
using namespace std;

int main() {
	//	Decalre three objects with default size of 10
	Array<int> intArray1;
	Array<int> intArray2;
	Array<double> doubleArray;

	cout << intArray1.DefaultSize() << endl;	// 10
	cout << intArray2.DefaultSize() << endl;	// 10
	cout << doubleArray.DefaultSize() << endl;	// 10

	intArray1.DefaultSize(15);

	cout << intArray1.DefaultSize() << endl;	// 15
	cout << intArray2.DefaultSize() << endl;	// 15
	cout << doubleArray.DefaultSize() << endl;	// 10

	/*All objects will share the same static variables. For templated version, 
	static variables will share within a typename. Since intArray1 and intArray2 have the same
	typename, they will print 15 when static varibale have been changed but double type's object
	stays the unchanged*/
	return 0;
}  