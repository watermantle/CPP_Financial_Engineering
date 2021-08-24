/*To pracctice with the different STL constiners*/
#include <list>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int main() {
	cout << "To test a list" << endl;//	intro text
	//	create a list of doubles
	list<double> list_double;
	//	add values to the list
	list_double.push_front(4);
	list_double.push_front(2);
	list_double.push_back(8);
	list_double.push_back(10);		//	The list should be 2, 4, 8, 10


	//	print data from the list
	cout << "The front of the list: " << list_double.front() << endl;
	cout << "The back of the list: " << list_double.back() << endl;
	list_double.clear();			//	clear list

	cout << "To test a vector" << endl;	//	intro text
	//	create a vector of doubles
	vector<double> vector_double(10);	//	the capcity of the vector is 10
	//	add some values
	for (int i = 0; i < vector_double.capacity(); i++) {
		vector_double[i] = rand();
	}
	
	cout << "The old capacity is " << vector_double.capacity() << endl;
	vector_double.push_back(3.14);		//	make the vector grow
	cout << "The new capacity is " << vector_double.capacity() << endl;
	//	print each element
	for (int i = 0; i < vector_double.size(); i++) {
		cout << vector_double[i] << endl;
	}

	vector_double.clear();		// clear vector

	cout << "To test a map" << endl;	//	intro text
	//	create a map with strings keys and doubles values
	map<string, double> map_double;
	//	add keys and values
	map_double["num1"] = 0.618;
	map_double["num2"] = 0.618 * 2;
	map_double["num3"] = 0.618 * 3;

	map<string, double>::iterator it_map;
	for (it_map = map_double.begin(); it_map != map_double.end(); it_map++) {
		cout << it_map->first << " is " << it_map->second << endl;
	}

	//	output data
	cout << map_double["num1"] << endl;
	cout << map_double["num2"] << endl;
	cout << map_double["num3"] << endl;
	return 0;
}