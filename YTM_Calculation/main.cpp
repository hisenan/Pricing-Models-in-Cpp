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

double YTM(const double& F, const double& c, const int& T, const double& P){
    const double PRECISION = 1e-5;
    const int MAX_ITER = 200;
    double bot = 0, top = 1;
    double mid;
    for(int i = 0; i < MAX_ITER; ++i){
        mid = (bot+top)/2;
        double diff = bond_price(F, c, mid, T) - P;
        if(fabs(diff) < PRECISION){
           return mid;
        } else {
            if(diff > 0){
                bot = mid;
            } else {
                top = mid;
            }
        }
    }
    return mid;
}

double duration(const double& F, const double& c, const double& r, const int& T){
    double P = bond_price(F, c, r, T);
    double C = F*c;
    double dur = 0;
    for(int t = 1; t <= T; ++t){
        dur += t*C/pow((1+r), t);
    }
    dur += T*F/pow(1+r,T);
    return dur/P;
}

double mod_duration(const double& F, const double& c, const double& r, const int& T){
    // Assuming annual compounding
    // r == y  for flat term structure
    return duration(F, c, r, T)/(1+r);
}

double convexity(const double& F, const double& c, const double& r, const int& T){
    double convx = 0;
    double P = bond_price(F, c, r, T);
    double C = F*c;
    for(int t = 1; t <= T; ++t){
        convx += (t + t*t)*C/pow(1+r, t);
    }
    convx += (T + T*T)*F/pow(1+r, T);
    convx /= (P*pow(1+r, 2));
    return convx;
}

int main()
{
    double F = 100, c = 0.1, P = 102.53, r = 0.09;
    int T = 3;
    cout << "Price of the bond is: " << bond_price(F, c, r, T) << endl;
    cout << "Yield to maturity is: " << YTM(F, c, T, P) << endl;
    cout << "Macaulay duration of the bond is: " << duration(F, c, r, T) << endl;
    cout << "Modified duration of the bond is: " << mod_duration(F, c, r, T) << endl;
    cout << "Convexity of the bond is: " << convexity(F, c, r, T) << endl;
    return 0;
}
