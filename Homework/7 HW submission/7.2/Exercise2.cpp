
#include "Sum.hpp"
#include <list>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int main() {
	//	To declare and test Sum() function for list and two containers
	list<double> l(10);
	l.push_back(10);
	l.push_back(10);
	l.push_back(10);
	l.push_back(10);
	cout << "The sum of the list is:" << Sum(l) << endl;
	cout << "The sum of the list with two iterators is: " << Sum(l.begin(), l.end()) << endl;

	//	To declare and test Sum() function for vector and two containers
	vector<double> v(10);
	for (int i = 0; i < v.capacity(); i++) {
		v[i] = 3.14;
	}
	cout << "The sum of the vector is:" << Sum(v) << endl;
	cout << "The sum of the vector with two iterators is: " << Sum(v.begin(), v.end()) << endl;

	//	To declare and test Sum() function for map and two containers
	map<string, double> dict;
	dict["one"] = 1;
	dict["two"] = 2;
	dict["three"] = 3;
	dict["four"] = 4;
	cout << "The sum of the map is:" << Sum(dict) << endl;
	map<string, double>::const_iterator start = dict.begin(), end = dict.end();
	cout << "The sum of the map with two iterators is: " << Sum<string, double>(start, end) << endl;
}