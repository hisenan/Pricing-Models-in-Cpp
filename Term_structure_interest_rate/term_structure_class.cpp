#include "header.h"

double term_structure_class::r(const double& t) const {
	return spot_rate_from_discount_factor(d(t), t);
}

double term_structure_class::d(const double& t) const {
	return discount_factor_from_spot_rate(r(t), t);
}

double term_structure_class::f(const double& t1, const double& t2) const {
	return forward_rate_from_spot_rate(r(t1), r(t2), t1, t2);
}