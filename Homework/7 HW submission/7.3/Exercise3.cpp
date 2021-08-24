#include <vector>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include "ifSmaller.hpp"
using namespace std;

double val = 3.14;	//	global value to set a benchmark for comparsion
bool ifSmaller_f(const double& num) { return num < val; };	//	global function

int main() {
	vector<double> v(10);		//	declare a vector
	//	set some value to the vector
	for (int i = 0; i < v.capacity(); i++) {
		v[i] = (rand() % 10);
	}
	//	print the values in vector
	for (int i = 0; i < v.capacity(); i++) {
		cout << v[i] << endl;
	}
	//	apply count_if algorithm with passing the global function as functor
	int n_smaller = count_if(v.begin(), v.end(), ifSmaller_f);
	cout << "The number of elements smaller than " << val << " is " << n_smaller << endl;

	//	apply count_if algorithm with passing the ifSmaller object as functor
	ifSmaller ifs(val);

	int n_smaller2 = count_if(v.begin(), v.end(), ifs);
	cout << "The number of elements smaller than " << val << " with object is " << n_smaller2 << endl;

	return 0;
}