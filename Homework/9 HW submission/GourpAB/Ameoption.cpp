//	source file to apply Ameoption class header file
#include "Ameoption.hpp"
#include "Option.hpp"
#include <iostream>
#include <math.h>
using namespace std;

//	constructors
Ameoption::Ameoption() : Option(){}
Ameoption::Ameoption(const Ameoption& source) : Option(source) {}
Ameoption::Ameoption(const double& K1, const double& T1, const double& r1, const double& sig1, const double& b1, const char& type1) : Option(K1, T1, r1, sig1, b1, type1) {}
Ameoption::~Ameoption() {}

//	operator
Ameoption& Ameoption::operator = (const Ameoption& source) {
	if (this == &source) {
		cout << "self-assignment check";
	}
	else {
		Option::operator = (source);
	}
	return *this;
}

//	price functions
double Ameoption::Price(const double& S) const {
	double price;
	//	intermediate paramaters y1 and y2
	double t1 = pow(b / (sig * sig) - 0.5, 2) + 2 * r / (sig * sig);
	double t2 = b / (sig * sig);

	double y1 = 0.5 - t2 + sqrt(t1);
	double y2 = 0.5 - t2 - sqrt(t1);

	//	calculate price
	if (type == 'C') {
		double p1 = K / (y1 - 1);
		double p2 = (y1 - 1) / y1 * S / K;
		price = p1 * pow(p2, y1);
	}
	else {
		double p1 = K / (1 - y2);
		double p2 = (y2 - 1) / y2 * S / K;
		price = p1 * pow(p2, y2);
	}
	return price;
}
