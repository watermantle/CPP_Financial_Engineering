//	to practise tuple data structrue that stores Person info. Also to increment the age of
//	one persons
#include <iostream>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
using namespace std;

typedef boost::tuple<string, int, double> Person;

//	function that prints the person tuple
void PrintPerson(const Person& person) {
	cout << "Name: " << person.get<0>() << ", Age: " << person.get<1>() << ", Length: " << person.get<2>() << endl;
	return;
}

int main() {
	//	create some persons with basic info
	Person YuBai("Yu Bai", 29, 183.2), Shauna("Shauna", 27, 165.5), JS("Jeffrey", 65, 190.1);
	//	print persons
	PrintPerson(YuBai);
	PrintPerson(Shauna);
	PrintPerson(JS);
	
	//	increment one person's age
	get<1>(YuBai)++;
	cout << "One year later YuBai's age will be " << YuBai.get<1>() << endl;

	return 0;
}