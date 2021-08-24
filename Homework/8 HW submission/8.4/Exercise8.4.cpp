//	Random number generation task to simulate trowing a dice
#include <iostream>
#include <boost/random.hpp>
#include <map>
using namespace std;

int main() {
	//	Throwing dice
	//	Mersenne Twister
	boost::random::mt19937 myRng;

	//	Set the seed
	myRng.seed(static_cast<boost::uint32_t>	(std::time(0)));

	//	Uniform in range [1, 6]
	boost::random::uniform_int_distribution<int> six(1, 6);

	map<int, long> statistics;	//	Structure to hold outcome + frequencises
	int outcome;				//	Current outcome
	long frequency = 0;			//	frequency for an outcome
	
	long n_trial;				//	times for each trial
	cout << "How many trials? ";
	cin >> n_trial;
	cout << endl;

	for (int i = 0; i <= n_trial; i++) {
		outcome = six(myRng);		//	trowing a dice
		statistics[outcome]++;		//	update the frequency of the outcome in the map
	}
	for (int i = 1; i <= 6; i++) {
		//	persentage frequency for each outcome
		double freq, count = statistics[i], n = n_trial;
		freq = count * 100 / n;
		cout << "Trial " << i << " has " << freq << "% outcomes\n";
	}
	return 0;
}