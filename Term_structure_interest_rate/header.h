#pragma once

#include <vector>
using namespace std;

class term_structure_class{
public:
	virtual double r(const double& t) const; // spot rate function
	virtual double d(const double& t) const; // discount function
	virtual double f(const double& t1, const double& t2) const; //forward rate between time t1 and t2
};

class flat_term_structure : public term_structure_class {
private:
	double m_r;
public:
	flat_term_structure(const double& r);
	double r(const double& t) const override;
	void set_flat_rate(const double& r);
};

class interpolated_term_structure : public term_structure_class {
private:
	vector<double> times;
	vector<double> rates;
public:
	interpolated_term_structure (const vector<double>& times, const vector<double>& rates);
	void set_times_rates(const vector<double>& times, const vector<double>& rates);
	double r(const double& t) const;
	int observations_num() const { return times.size(); };
};

double spot_rate_from_discount_factor(const double& d_t, const double& t);
double discount_factor_from_spot_rate(const double& r_t, const double& t);
double forward_rate_from_spot_rate(const double& r_t1, const double& r_t2,
	const double& t1, const double& t2);
double linearly_interpolated_rate(const vector<double>& times, const vector<double>& rates,
	const double& t);
double bond_price(const vector<double>& cashflows, const vector<double>& times, const term_structure_class& ts);
double bond_duration(const vector<double>& cashflows, const vector<double>& times, const term_structure_class& ts);
double bond_convexity(const vector<double>& cashflows, const vector<double>& times, const term_structure_class& ts);
