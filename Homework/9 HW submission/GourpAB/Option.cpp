//	source file that applies Option header file


#include "Option.hpp"
#include <boost/math/distributions.hpp>
#include <iostream>
#include <math.h>
using namespace std;
using namespace boost::math;

//	defualt constructor
Option::Option() : K(0), T(0), r(0), sig(0), b(0), type('C') {};
//	copy constructor
Option::Option(const Option& source) : K(source.K), T(source.T), r(source.r), sig(source.sig), b(source.b), type(source.type) {}
//	constructor with given value
Option::Option(const double& K1, const double& T1, const double& r1, const double& sig1, const double& b1, const char& type1) : K(K1), T(T1), r(r1), b(b1), sig(sig1), type(type1) {}
//	destructor
Option::~Option() {}

//	assignment operator
Option& Option::operator = (const Option& source) {
	if (this == &source) {
		cout << "self-assignment check";
	}
	else {
		//	assign values
		K = source.K;
		T = source.T;
		r = source.r;
		sig = source.sig;
		b = source.b;
		type = source.type;
	}
	return *this;
}

void Option::toggle() {
	if (type == 'C') {
		type = 'P';
	}
	else {
		type = 'C';
	}
	return;
}

// sensitivities
//	Delta calculation
double Option::Delta(const double& S) const {
	normal_distribution<> SND(0.0, 1.0);	//	standard normal distribution
	double Delta;
	//	intermediate paramaters d1 and d2
	double d1 = (log(S / K) + (b + sig * sig / 2) * T) / (sig * sqrt(T));
	double d2 = d1 - sig * sqrt(T);

	//	calculate price
	if (type == 'C') {
		Delta = exp((b - r) * T) * cdf(SND, d1);
	}
	else {
		Delta = -exp((b - r) * T) * cdf(SND, -d1);
	}
	return Delta;
}

//	Gamma calculation
double Option::Gamma(const double& S) const {
	normal_distribution<> SND(0.0, 1.0);	//	standard normal distribution
	//	intermediate paramaters d1
	double d1 = (log(S / K) + (b + sig * sig / 2) * T) / (sig * sqrt(T));
	//	gamma
	double Gamma = pdf(SND, d1) / (S * sig * sqrt(T));
	return Gamma;
}

//	Vega calculation
double Option::Vega(const double& S) const {
	normal_distribution<> SND(0.0, 1.0);	//	standard normal distribution
	//	intermediate paramaters d1
	double d1 = (log(S / K) + (b + sig * sig / 2) * T) / (sig * sqrt(T));
	//	gamma
	double Vega = S * sqrt(T) * exp((b - r) * T) * pdf(SND, d1);
	return Vega;
}

//	Theta calculation
double Option::Theta(const double& S) const {
	normal_distribution<> SND(0.0, 1.0);	//	standard normal distribution
	double Theta;
	//	intermediate paramaters d1 and d2
	double d1 = (log(S / K) + (b + sig * sig / 2) * T) / (sig * sqrt(T));
	double d2 = d1 - sig * sqrt(T);

	//	calculate theta
	if (type == 'C') {
		double t1 = (S * exp((b - r) * T) * pdf(SND, d1) * sig / 2) / sqrt(T);
		double t2 = (b - r) * (S * exp((b - r) * T) * cdf(SND, d1));
		double t3 = r * K * exp(-r * T) * cdf(SND, d2);
		Theta = -(t1 + t2 + t3);
	}
	else {
		double t1 = (S * exp((b - r) * T) * pdf(SND, d1) * sig / 2) / sqrt(T);
		double t2 = (b - r) * (S * exp((b - r) * T) * cdf(SND, -d1));
		double t3 = r * K * exp(-r * T) * cdf(SND, -d2);
		Theta = -t1 + t2 + t3;
	}
	return Theta;
}

//	Rho calculation
double Option::Rho(const double& S) const {
	normal_distribution<> SND(0.0, 1.0);	//	standard normal distribution
	double Rho;
	//	intermediate paramaters d1 and d2
	double d1 = (log(S / K) + (b + sig * sig / 2) * T) / (sig * sqrt(T));
	double d2 = d1 - sig * sqrt(T);

	//	calculate price
	if (type == 'C') {
		if (b != 0.0) {
			Rho = T * K * exp(-r * T) * cdf(SND, d2);
		}
		else {
			Rho = -T * Price(S);
		}
	}
	else {
		if (b != 0.0) {
			Rho = -T * K * exp(-r * T) * cdf(SND, -d2);
		}
		else {
			Rho = -T * Price(S);
		}
	}
	return Rho;
}

//	approximate approach for delta and gamma
double Option::ApprxDelta(const double& S, const double& h) const {
	return (Price(S + h) - Price(S - h)) / (2 * h);
}
double Option::ApprxGamma(const double& S, const double& h) const {
	return (Price(S + h) - 2 * Price(S) + Price(S- h)) / (h * h);
}
