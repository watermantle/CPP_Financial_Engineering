//	source file to apply Euroption class header file
#include "Euroption.hpp"
#include "Option.hpp"
#include <iostream>
#include <boost/math/distributions.hpp>
#include <math.h>
using namespace std;
using namespace boost::math;

//	constructors
Euroption::Euroption() : Option(){}
Euroption::Euroption(const Euroption& source) : Option(source) {}
Euroption::Euroption(const double& K1, const double& T1, const double& r1, const double& sig1, const double& b1, const char& type1) : Option(K1, T1, r1, sig1, b1, type1) {}
Euroption::~Euroption() {}

//	operator
Euroption& Euroption::operator = (const Euroption& source) {
	if (this == &source) {
		cout << "self-assignment check";
	}
	else {
		Option::operator = (source);
	}
	return *this;
}

//	price functions
double Euroption::Price(const double& S) const {
	normal_distribution<> SND(0.0, 1.0);	//	standard normal distribution
	double price;
	//	intermediate paramaters d1 and d2
	double d1 = (log(S / K) + (b + sig * sig / 2) * T) / (sig * sqrt(T));
	double d2 = d1 - sig * sqrt(T);

	//	calculate price
	if (type == 'C') {
		price = S * exp((b - r) * T) * cdf(SND, d1) - K * exp(-r * T) * cdf(SND, d2);
	}
	else {
		price = K * exp(-r * T) * cdf(SND, -d2) - S * exp((b - r) * T) * cdf(SND, -d1);
	}
	return price;
}

//	put-call parity
double Euroption::Parity(const double& S) {
	double res;
	if (type == 'C') {
		res = Price(S) + K * exp(-r * T) - S;
	}
	else {
		res = Price(S) + S - K * exp(-r * T);
	}
	return res;
}

bool Euroption::Parity(const double& S, const double tol) {
	//	to store the original type
	char orig_type = type;
	double val_price, val_parity;
	bool res;
	
	val_parity = Parity(S);
	//	swtich from one to another
	toggle();
	val_price = Price(S);
	res = abs(val_price - val_parity) < tol;
	//	swtich back
	toggle();
	return res;
}