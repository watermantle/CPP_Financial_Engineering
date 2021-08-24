//	Header file of ifSmaller class that is to replace global function
#ifndef ifSmaller_HPP
#define ifSmaller_HPP

#include <iostream>
using namespace std;

class ifSmaller {
private:
	double m_val;
public:
	ifSmaller();							//	default constructor
	ifSmaller(const ifSmaller& source);		//	copy constructor
	ifSmaller(const double& val);			//	constructor with given value
	~ifSmaller();							//	destructor

	//	operators
	ifSmaller& operator = (const ifSmaller& source);	//	assignment operator
	bool operator () (const double& num) const;		//	overlaod operator ()
};

#endif