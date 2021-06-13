#ifndef MatrixCal_HPP
#define MatrixCal_HPP

#include "Option.hpp"
#include <iostream>
#include <vector>

template <typename T>
class MatrixCal {
private:
	//	Option engin to price the matrix. Other type of option could be applied
	//	now only European and American option are available
	T option_engin;
	//	input matrix for pricing
	vector<vector<double>> matrix;
	//	option type, "C" for call, "P" for Put option
	char type;
	
public:
	//	small value to apply sensitivities approximation
	double h;

	//	construcotrs
	MatrixCal();								//	default constructor
	MatrixCal(const MatrixCal& source);			//	copy constructor
	//	constructor with given values
	MatrixCal(const T& opt, const vector<vector<double>>& mx, const double& new_h, const char& opt_type);
	~MatrixCal();								//	destructor

	//	assignment operator
	MatrixCal& operator = (const MatrixCal& source);

	//	function
	vector<double> Calculate(const string& CalType);	//	matrix calculation to calculate price or Greeks
	
	void toggle();										//	switch embedded option type from one to another
};

#ifndef MatrixPricing_CPP
#include "MatrixCal.cpp"
#endif

#endif