#include <iostream>
#include "header.h"
#include <vector>
using namespace std;

int main(){
	
	// Creating a flat_term_structure class with constant flat rate of 10%
	double r = 0.1;
	flat_term_structure t(r);
	cout << "FLAT TERM STRUCTURE" << endl;
	cout << "Discount factor for year 1 and year 2 is: " << t.d(1) << " and " <<
		t.d(2) << " respectively" << endl;
	cout << "The forward rate between year 1 and year 2 is: " << t.f(1, 2) << endl;
	vector<double> times = { 1, 2 };
	vector<double> cashflows = { 10, 110 };
	cout << "Price of a 2-year, 10% bond: " << bond_price(cashflows, times, t) << endl;
	cout << "Bond Duration: " << bond_duration(cashflows, times, t) << endl;
	cout << "Bond Convexity: " << bond_convexity(cashflows, times, t) << endl;
	
	//Creating an interpolated_term_structure class with rates 5%, 7% and 8% at times 0.1,1 and 5 year
	times = { 0.1, 1, 5 };
	vector<double> rates = { 0.05, 0.07, 0.08 };
	interpolated_term_structure its(times, rates);
	cout << "\n";
	cout << "INTERPOLATED TERM STRUCTURE" << endl;
	cout << "Spot rate for year 1 and year 2 is: " << its.r(1) << " and " <<
		its.r(2) << " respectively" << endl;
	cout << "Discount factor for year 1 and year 2 is: " << its.d(1) << " and " <<
		its.d(2) << " respectively" << endl;
	cout << "The forward rate between year 1 and year 2 is: " << its.f(1, 2) << endl;
	times = { 1, 2 };
	cashflows = { 10, 110 };
	cout << "Price of a 2-year, 10% bond: " << bond_price(cashflows, times, its) << endl;
	cout << "Bond Duration: " << bond_duration(cashflows, times, its) << endl;
	cout << "Bond Convexity: " << bond_convexity(cashflows, times, its) << endl;

	return 0;
}