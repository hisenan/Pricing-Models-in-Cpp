#include <iostream>
#include <cmath>
using namespace std;

double bond_price(const double& F, const double& c, const double& r, const int& T){
    // Price of a bond with Face value F, coupon rate c, time to maturity T
    // A flat term structure is assumed with rate r
    double P = 0;
    double C = F*c;
    for(int t = 1; t <= T; ++t){
        P += C/pow(1+r,t);
    }
    P += F/pow(1+r, T);
    return P;
}

int main()
{
    double F = 100.0, c = 0.1, r = 0.09;
    int T = 3;
    cout << "Price of the bond: " << bond_price(F, c, r, T) << endl;
    return 0;
}
