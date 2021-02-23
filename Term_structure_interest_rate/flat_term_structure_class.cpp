#include "header.h"

flat_term_structure::flat_term_structure(const double& r) { m_r = r; }
double flat_term_structure::r(const double& t) const { return m_r; }
void flat_term_structure::set_flat_rate(const double& r) { m_r = r; }
