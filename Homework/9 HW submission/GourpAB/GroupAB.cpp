#include "Euroption.hpp"
#include "Ameoption.hpp"
#include "MatrixCal.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
//just a test
//	mesher function to product a matrix. The input vector should be a group of input for option
vector<vector<double>> mesher(const vector<double>& v, const string& Param, const double& start, const double& end, const double& h);

//	mesher printer, to print the input matrix
void print_mesh(vector<vector<double>>& matrix);

int main() {
	cout << "GroupA Exact Solutions of One-Factor Plain Options question a, b:\n\n";
	//	Batch 1: 
	double T = 0.25, K = 65, sig = 0.30, r = 0.08, S = 60, b = r; // price wtih Black-Scholes
	Euroption option_1(K, T, r, sig, b, 'C');
	cout << "Batch 1 call option price with Black-Scholes: " << option_1.Price(S) << endl;
	cout << "Batch 1 put option price with put-call parity: " << option_1.Parity(S) << endl;
	cout << "Results will " << (option_1.Parity(S, 0.01) ? "stify" : "not stify") << " the parity" << endl;
	//	swtich to put option from call option
	option_1.type = 'P';
	cout << "Batch 1 put option price with Black-Scholes: " << option_1.Price(S) << endl;
	cout << "Batch 1 call option price with put-call parity: " << option_1.Parity(S) << endl << endl;

	//	Batch 2:
	T = 1.0, K = 100, sig = 0.2, r = 0.0, S = 100, b = r;
	Euroption option_2(K, T, r, sig, b, 'C');
	cout << "Batch 2 call option price with Black-Scholes: " << option_2.Price(S) << endl;
	cout << "Batch 2 put option price with put-call parity: " << option_2.Parity(S) << endl;
	cout << "Results will " << (option_2.Parity(S, 0.01) ? "stify" : "not stify") << " the parity" << endl;
	//	swtich to put option from call option
	option_2.type = 'P';
	cout << "Batch 2 put option price with Black-Scholes: " << option_2.Price(S) << endl;
	cout << "Batch 2 call option price with put-call parity: " << option_2.Parity(S) << endl << endl;

	//	Batch 3:
	T = 1.0, K = 10, sig = 0.50, r = 0.12, S = 5, b = r;
	Euroption option_3(K, T, r, sig, b, 'C');
	cout << "Batch 3 call option price with Black-Scholes: " << option_3.Price(S) << endl;
	cout << "Batch 3 put option price with put-call parity: " << option_3.Parity(S) << endl;
	cout << "Results will " << (option_3.Parity(S, 0.01) ? "stify" : "not stify") << " the parity" << endl;
	//	swtich to put option from call option
	option_3.type = 'P';
	cout << "Batch 3 put option price with Black-Scholes: " << option_3.Price(S) << endl;
	cout << "Batch 3 call option price with put-call parity: " << option_3.Parity(S) << endl << endl;

	//	Batch 4:
	T = 30.0, K = 100.0, sig = 0.30, r = 0.08, S = 100.0, b = r;
	Euroption option_4(K, T, r, sig, b, 'C');
	cout << "Batch 4 call option price with Black-Scholes: " << option_4.Price(S) << endl;
	cout << "Batch 4 put option price with put-call parity: " << option_4.Parity(S) << endl;
	cout << "Results will " << (option_4.Parity(S, 0.01) ? "stify" : "not stify") << " the parity" << endl;
	//	swtich to put option from call option
	option_4.type = 'P';
	cout << "Batch 4 put option price with Black-Scholes: " << option_4.Price(S) << endl;
	cout << "Batch 4 call option price with put-call parity: " << option_4.Parity(S) << endl << endl;

	cout << "question c, d for demostration purpose, only check S, T, sig, and K\n\n";
	//	input with Batch 1 as the base case.
	T = 0.25, K = 65, sig = 0.30, r = 0.08, S = 60, b = r;
	//	declare an input order S, K, T, r, sig, b
	vector<double> option_inputs{ S, K, T, r, sig, b };

	//	declare a matrix to store the out puts
	vector<vector<double>> mtxS, mtxT, mtxsig, mtxK;

	//	mesher with left close and right open
	mtxS = mesher(option_inputs, "S", 10, 51, 1);
	mtxT = mesher(option_inputs, "T", 0.25, 3, 0.25);
	mtxsig = mesher(option_inputs, "sig", 0.1, 0.56, 0.05);
	mtxK = mesher(option_inputs, "K", 10, 71, 5);

	//	using reugular code to out put a vector. Option_1 now is a put option
	vector<double> res_groupA_c;
	cout << "Using regular code to price a matrix input\n";
	for (int i = 0; i != mtxS.size(); i++) {
		res_groupA_c.push_back(option_1.Price(mtxS[i][0]));
		cout << res_groupA_c[i] << " ";
	}
	cout << "\n\n";
	//	Matrix pricer
	Euroption OptionEngin = option_1;
	MatrixCal<Euroption> MatrixPricerS(OptionEngin, mtxS, 0.01, 'P');
	MatrixCal<Euroption> MatrixPricerT(OptionEngin, mtxT, 0.01, 'C');
	MatrixCal<Euroption> MatrixPricersig(OptionEngin, mtxsig, 0.01, 'P');
	MatrixCal<Euroption> MatrixPricerK(OptionEngin, mtxK, 0.01, 'C');

	//	outputs
	vector<double> res_S = MatrixPricerS.Calculate("Pricing");
	vector<double> res_T = MatrixPricerT.Calculate("Pricing");
	vector<double> res_sig = MatrixPricersig.Calculate("Pricing");
	vector<double> res_K = MatrixPricerK.Calculate("Pricing");

	//	display outputs
	cout << "Matrix by changing S from 10 to 50 with step of 1:\n";
	print_mesh(mtxS);
	cout << endl << "The matrix price results with put option are: " << endl;
	for (int i = 0; i != res_S.size(); i++) {
		cout << res_S[i] << ' ';
	}

	cout << "\nMatrix by changing T from 0.25 to 3 with step of 0.25:\n";
	print_mesh(mtxT);
	cout << endl << "The matrix price results with call option are: " << endl;
	for (int i = 0; i != res_T.size(); i++) {
		cout << res_T[i] << ' ';
	}

	cout << "\nMatrix by changing sig from 0.1 to 0.56 with step of 0.05:\n";
	print_mesh(mtxsig);
	cout << endl << "The matrix price results put option are: " << endl;
	for (int i = 0; i != res_sig.size(); i++) {
		cout << res_sig[i] << ' ';
	}

	cout << "\nMatrix by changing K from 10 to 71 with step of 5:\n";
	print_mesh(mtxK);
	cout << endl << "The matrix price results with call option are: " << endl;
	for (int i = 0; i != res_K.size(); i++) {
		cout << res_K[i] << ' ';
	}
	
	cout << "\n\nOption Greeks: \n\n";
	//	test set
	K = 100, S = 105, T = 0.5, r = 0.1, b = 0, sig = 0.36;
	Euroption option_greek(K, T, r, sig, b, 'C');
	cout << "Exact delta call: " << option_greek.Delta(S) << endl;
	cout << "Approximation delta call, h = 0.5: " << option_greek.ApprxDelta(S, 0.5) << endl;
	cout << "Approximation delta call, h = 0.1: " << option_greek.ApprxDelta(S, 0.1) << endl;
	cout << "Approximation delta call, h = 0.05: " << option_greek.ApprxDelta(S, 0.05) << endl;
	//	switch from call to put
	option_greek.toggle();
	cout << "Exact delta put: " << option_greek.Delta(S) << endl;
	cout << "Approximation delta call, h = 0.5: " << option_greek.ApprxDelta(S, 0.5) << endl;
	cout << "Approximation delta call, h = 0.1: " << option_greek.ApprxDelta(S, 0.1) << endl;
	cout << "Approximation delta call, h = 0.05: " << option_greek.ApprxDelta(S, 0.05) << endl << endl;

	//	switch back to call option	
	option_greek.toggle();

	//	question b, c matS will be used
	vector<double> inputs_greek{ S, K, T, r, sig, b };
	vector<vector<double>> mtxS_greek = mesher(inputs_greek, "S", 10, 51, 1);
	//	0.5 is h for greeks
	MatrixCal<Euroption> MatrixPricerGreek(option_greek, mtxS_greek, 0.5, 'C');

	//	matrix pricer to calculate Delta and Gamma
	vector<double> Deltas_v = MatrixPricerGreek.Calculate("Delta");
	vector<double> Gammas_v = MatrixPricerGreek.Calculate("Gamma");

	cout << "Matrix by changing S from 10 to 50 with step of 1:\n";
	print_mesh(mtxS_greek);

	//	matrix pricing with regular code
	vector<double> res_groupA_greek;
	cout << "\nUsing regular code to calculate exact delta for call option with a matrix input\n\n";
	for (int i = 0; i != mtxS_greek.size(); i++) {
		res_groupA_greek.push_back(option_greek.Delta(mtxS_greek[i][0]));
		cout << res_groupA_greek[i] << " ";
	}
	cout << endl;
	//	display matrix pricing with matrix pricer
	for (int i = 0; i != Deltas_v.size(); i++) {
		cout << "Delta: " << Deltas_v[i] << " ";
		cout << "Gamma: " << Gammas_v[i] << endl;
	}

	cout << endl << "Detla and Gamma approximation approach\n\n";
	vector<double> ApprxDeltas_v = MatrixPricerGreek.Calculate("ApprxDelta");
	vector<double> ApprxGammas_v = MatrixPricerGreek.Calculate("ApprxGamma");

	cout << "Apprx with h = 0.5\n";
	for (int i = 0; i != ApprxDeltas_v.size(); i++) {
		cout << "ApprxDelta: " << ApprxDeltas_v[i] << " ";
		cout << "ApprxGamma: " << ApprxGammas_v[i] << endl;
	}
	
	//	change h to get different accuracy
	MatrixPricerGreek.h = 0.01;
	ApprxDeltas_v = MatrixPricerGreek.Calculate("ApprxDelta");
	ApprxGammas_v = MatrixPricerGreek.Calculate("ApprxGamma");
	cout << "\nApprx with h = 0.01\n";
	for (int i = 0; i != ApprxDeltas_v.size(); i++) {
		cout << "ApprxDelta: " << ApprxDeltas_v[i] << " ";
		cout << "ApprxGamma: " << ApprxGammas_v[i] << endl;
	}

	cout << endl << "Perpetual American Options:\n" << endl;
	//	test data
	K = 100, sig = 0.1, r = 0.1, b = 0.02, S = 110;
	Ameoption AmericanOpt(K, T, r, sig, b, 'C');
	//	test output
	cout << "Call perpetual American option price: " << AmericanOpt.Price(S) << endl;
	//	swtich call option to put option
	AmericanOpt.toggle();
	cout << "Put perpetual American option price: " << AmericanOpt.Price(S) << endl << endl;

	//	declare an input order S, K, T, r, sig, b
	vector<double> inputs_American{ S, K, T, r, sig, b };
	vector<vector<double>> mtxS_American = mesher(inputs_American, "S", 10, 51, 1);

	//	input matrix
	print_mesh(mtxS_American);

	//	change option to a call option	
	AmericanOpt.type = 'C';

	//	regular code to print a vector of prices
	vector<double> res_groupB_b;
	cout << "\nUsing regular code to price a matrix input:\n\n";
	for (int i = 0; i != mtxS_American.size(); i++) {
		res_groupB_b.push_back(AmericanOpt.Price(mtxS_American[i][0]));
		cout << res_groupB_b[i] << " ";
	}

	//	use matrix pricer
	MatrixCal<Ameoption> MatricPricerAme(AmericanOpt, mtxS_American, 0.01, 'C');
	vector<double> AmericanPX = MatricPricerAme.Calculate("Pricing");

	cout << "\n\nMatrix by changing S from 10 to 50 with step of 1:\n";
	cout << endl << "The matrix price results with call option are: " << endl;
	for (int i = 0; i != AmericanPX.size(); i++) {
		cout << AmericanPX[i] << ' ';
	}

	return 0;
}

//	mesher function to product a matrix. The input vector should be a group of input for option
vector<vector<double>> mesher(const vector<double>& v, const string& Param, const double& start, const double& end, const double& h) {
	//	create and init param map
	map<string, int> Param_dict;
	vector<string> params{ "S", "K", "T", "r", "sig", "b" };
	for (int i = 0; i < 6; i++) {
		Param_dict[params[i]] = i;
	};
	//	output matrix that stores vector for each inputs
	vector<vector<double>> res_matrix;
	//	number of values for the changed item
	int size = floor((end - start) / h);

	//	tem vector to store each result
	vector<double> v_tem = v;

	int idx = Param_dict[Param];		//	index to modify the input vector
	for (int i = 0; i != size; i++) {
		v_tem[idx] = i * h + start;
		res_matrix.push_back(v_tem);
	}
	return res_matrix;
}

//	mesher printer, to print the input matrix
void print_mesh(vector<vector<double>>& matrix) {
	cout << " S  K   T    r  sig  b\n";

	for (int i = 0; i != matrix.size(); i++) {
		for (int j = 0; j != 6; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}