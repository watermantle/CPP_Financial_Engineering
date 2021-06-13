//	source file that applies Matrix Pricing header file

#ifndef MatrixCal_CPP
#define MatrixCal_CPP

#include "MatrixCal.hpp"
#include "Option.hpp"
#include "Ameoption.hpp"
#include "Euroption.hpp"
#include <iostream>
#include <math.h>
#include <map>
using namespace std;

//	default constructor
template <typename T>
MatrixCal<T>::MatrixCal() {
	//	initialize option_engin and matrix
	T opt;
	vector<vector<double>> matrix_init{ {} };
	option_engin = opt;
	matrix = matrix_init;
	h = 0;
	type = "C";
	option_engin.type = type;
}
//	copy constructor
template <typename T>
MatrixCal<T>::MatrixCal(const MatrixCal& source) {
	option_engin = source.option_engin;
	matrix = source.matrix;
	type = source.type;
	option_engin.type = type;
	h = source.h;
}
//	constructor with given values
template <typename T>
MatrixCal<T>::MatrixCal(const T& opt, const vector<vector<double>>& mx, const double& new_h, const char& opt_type) {
	option_engin = opt;
	matrix = mx;
	type = opt_type;
	option_engin.type = type;
	h = new_h;
}
//	destructor
template <typename T>
MatrixCal<T>::~MatrixCal(){}

//	assignment operator
template <typename T>
MatrixCal<T>& MatrixCal<T>::operator = (const MatrixCal& source) {
	if (this == &source) {
		cout << "self-assignment check";
	}
	else {
		//	assign values
		option_engin = source.option_engin;
		matrix = source.matrix;
		type = source.type;
		option_engin.type = source.type;
		h = source.h;
	}
	return *this;
}

template <typename T>
vector<double> MatrixCal<T>::Calculate(const string& CalType) {
	//	working vector for each row
	vector<double> working_vector, res_vector;

	//	case map
	map<string, int> cal_dict{
		{"Pricing", 1}, {"Delta", 2}, {"Gamma", 3}, {"Vega", 4},
		{"Theta", 5}, {"Rho", 6}, {"ApprxDelta", 7}, {"ApprxGamma", 8}
	};
	
	int cal_case = cal_dict[CalType];
	
	//	to store single value
	double tem;
	//	go over the matrix
	for (int i = 0; i != matrix.size(); i++) {
		working_vector = matrix[i];
		option_engin.K = working_vector[1];
		option_engin.T = working_vector[2];
		option_engin.r = working_vector[3];
		option_engin.sig = working_vector[4];
		option_engin.b = working_vector[5];
		//	to decide kind of calculation
		switch (cal_case) {
		case 1:
			tem = option_engin.Price(working_vector[0]);
			break;
		case 2:
			tem = option_engin.Delta(working_vector[0]);
			break;
		case 3:
			tem = option_engin.Gamma(working_vector[0]);
			break;
		case 4:
			tem = option_engin.Vega(working_vector[0]);
			break;
		case 5:
			tem = option_engin.Theta(working_vector[0]);
			break;
		case 6:
			tem = option_engin.Rho(working_vector[0]);
			break;
		case 7:
			tem = option_engin.ApprxDelta(working_vector[0], h);
			break;
		case 8:
			tem = option_engin.ApprxGamma(working_vector[0], h);
			break;
		default:
			tem = option_engin.Price(working_vector[0]);
		};
		res_vector.push_back(tem);
	}
	return res_vector;
}
//	switch embedded option type from one to another
template <typename T>
void MatrixCal<T>::toggle() {
	option_engin.toggle();
}
#endif