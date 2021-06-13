//	header file of European option based on Option class
#ifndef Euroption_HPP
#define Euroption_HPP

#include <iostream>
#include "Option.hpp"
using namespace std;

class Euroption : public Option {
private:
	//	no member data for convience
public:
	Euroption();							//	defualt constructor
	Euroption(const Euroption& source);		//	copy constructor
	Euroption(const double& K1, const double& T1, const double& r1, const double& sig1, const double& b1, const char& type1);
	~Euroption();							//	destructor

	//	assignment operator
	Euroption& operator = (const Euroption& source);

	//	price function
	double Price(const double& S) const;							//	pricing function

	//	put-call parity
	double Parity(const double& S);							//	return price with put-call parity
	bool Parity(const double& S, const double tol);			//	to check if satify parity. check with tolerance tol
};

#endif