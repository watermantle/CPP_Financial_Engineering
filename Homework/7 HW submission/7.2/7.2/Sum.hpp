//	sum header file
#ifndef Sum_HPP
#define Sum_HPP

#include <list>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

//	declare Sum() function to return sum of a list or vector
template<typename T> double Sum(const T& container);
//	declare Sum() function to return sum of a map
template<typename T1, typename T2> double Sum(const map<T1, T2>& container);
//	declare Sum() function to return sum between two iterators
template<typename T> double Sum(const T& start, const T& end);
//	declare Sum() function to return sum between two iterators for map objects
template<typename T1, typename T2> double Sum(const typename map<T1, T2>::const_iterator& start, const typename map<T1, T2>::const_iterator& end);

//	Sum() function to receive a list or a vector and return the sum of the elements
template<typename T>
double Sum(const T& container) {
	double sum = 0;
	typename T::const_iterator it;
	for (it = container.begin(); it != container.end(); it++) {
		sum += *it;
	}
	return sum;
}

//	Sum() function to accept map and return the sum of the elements
template<typename T1, typename T2>
double Sum(const map<T1, T2>& container) {
	double sum = 0;
	typename map<T1, T2>::const_iterator it;
	for (it = container.begin(); it != container.end(); it++) {
		sum += (*it).second;
	}
	return sum;
}

//Sum() function to accept two iterators, T should be iterator
template<typename T> 
double Sum(const T& start, const T& end) {
	double sum = 0;
	T it;
	for (it = start; it != end; it++) {
		sum += *it;
	}
	return sum;
}

//sum() function for map objects to accept two iterators
template<typename T1, typename T2> 
double Sum(const typename map<T1, T2>::const_iterator& start, const typename map<T1, T2>::const_iterator& end) {
	double sum = 0;
	typename map<T1, T2>::const_iterator it;
	for (it = start; it != end; it++) {
		sum += (*it).second;
	};
	return sum;
};

#endif