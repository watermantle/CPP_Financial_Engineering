//	header file to apply option pricing and more
//	base class that constains esstential inputs. The class could add more type of otions
#ifndef Option_hpp
#define Option_hpp

#include <iostream>
using namespace std;


class Option {
private:
	//	No member data for convience
public:
	//	essential inputs for a europen option
	double K, T, r, sig, b;
	char type;			//	'C' for call option, 'P' for put option

	//	constructors
	Option();						//	defualt constructor
	Option(const Option& source);	// copy constructor
	//	constructor with given values
	Option(const double& K1, const double& T1, const double& r1, const double& sig1, const double& b1, const char& type1);
	virtual ~Option();			//	destructor

	//	assignment operator
	Option& operator = (const Option& source);

	virtual double Price(const double& S) const = 0;				//	pricing function, pure virtual

	void toggle();													//	switch bewteen call and put

	//	sensitivities calculation
	double Delta(const double& S) const;							//	detla
	double Gamma(const double& S) const;							//	gamma
	double Vega(const double& S) const;								//	vega
	double Theta(const double& S) const;							//	theta
	double Rho(const double& S) const;								//	rho
	double ApprxDelta(const double& S, const double& h) const;		//	approximate approach detla
	double ApprxGamma(const double& S, const double& h) const;		//	approximate approach gamma
};
#endif