#include <vector>
#include "header.h"
using namespace std;

interpolated_term_structure::interpolated_term_structure(const vector<double>& in_times, const vector<double>& in_rates)
	: times(in_times), rates(in_rates) {}

void interpolated_term_structure::set_times_rates(const vector<double>& in_times, const vector<double>& in_rates) {
	times = in_times;
	rates = in_rates;
}

double interpolated_term_structure::r(const double& t) const {
	return linearly_interpolated_rate(times, rates, t);
}