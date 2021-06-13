//	header file of American option based on Option class
#ifndef Ameoption_HPP
#define Ameoption_HPP

#include <iostream>
#include "Option.hpp"
using namespace std;

class Ameoption : public Option {
private:
	//	no member data for convience
public:
	Ameoption();							//	defualt constructor
	Ameoption(const Ameoption& source);		//	copy constructor
	Ameoption(const double& K1, const double& T1, const double& r1, const double& sig1, const double& b1, const char& type1);
	~Ameoption();							//	destructor

	//	assignment operator
	Ameoption& operator = (const Ameoption& source);

	//	price function
	double Price(const double& S) const;	//	pricing function with perpetual formulae
};

#endif