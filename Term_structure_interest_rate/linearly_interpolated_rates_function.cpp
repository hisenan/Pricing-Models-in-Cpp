#include <iostream>
#include <vector>
using namespace std;

double linearly_interpolated_rate(const vector<double>& times, const vector<double>& rates,
	const double& t) {
	int n = times.size();
	double t_min = times[0];
	double t_max = times[n-1];
	if (t <= t_min) {
		return rates[0];
	}
	else if (t >= t_max) {
		return rates[n - 1];
	}
	else {
		int i = 0;
		while (t > times[i]) ++i;
		double m = (rates[i] - rates[i - 1]) / (times[i] - times[i - 1]);
		return (rates[i - 1] + m * (t - times[i - 1]));
	}
	 

}