#include<vector>
#include "header.h"
using namespace std;

double bond_price(const vector<double>& cashflows, const vector<double>& times, const term_structure_class& ts) {
	double P = 0;
	int n = times.size();
	for (int i = 0; i < n; ++i) {
		P += cashflows[i] * ts.d(times[i]);
	}
	return P;
}

double bond_duration(const vector<double>& cashflows, const vector<double>& times, const term_structure_class& ts) {
	double dur = 0;
	int n = times.size();
	double P = bond_price(cashflows, times, ts);
	for (int i = 0; i < n; ++i) {
		dur += times[i] * cashflows[i] * ts.d(times[i]);
	}
	return dur / P;
}

double bond_convexity(const vector<double>& cashflows, const vector<double>& times, const term_structure_class& ts)
{
	double convx = 0;
	int n = times.size();
	double P = bond_price(cashflows, times, ts);
	for (int i = 0; i < n; ++i) {
		convx += times[i] * times[i] * cashflows[i] * ts.d(times[i]);
	}
	return convx / P;
}