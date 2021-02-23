#include <cmath>

double spot_rate_from_discount_factor(const double& d_t, const double& t) {
	return (-log(d_t) / t);
}

double discount_factor_from_spot_rate(const double& r_t, const double& t) {
	return exp(-r_t * t);
}

double forward_rate_from_spot_rate(const double& r_t1, const double& r_t2,
	const double& t1, const double& t2) {
	return (r_t2 * t2 - r_t1 * t1) / (t2 - t1);
}