#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double ERROR = -1e30;
const int max_iter = 100;

double present_value(const vector<double>& cflow_times, const vector<double>& cflow_values, const double& r){
    double PV = 0.0;
    for(int t = 0; t < cflow_times.size(); t++){
        PV += cflow_values[t]/pow(1+r, cflow_times[t]);
    }
    return PV;
}

int bracketing(double& r1, double& r2, const vector<double>& cflow_times, const vector<double>& cflow_values){
    double f1 = present_value(cflow_times, cflow_values, r1);
    double f2 = present_value(cflow_times, cflow_values, r2);
    if(f1*f2 < 0) return 1;
    for(int i = 0; i < max_iter; i++){
        if(fabs(f1) < fabs(f2)){
            f1 = present_value(cflow_times, cflow_values, r1 += 1.6*(r1-r2));
        } else {
            f2 = present_value(cflow_times, cflow_values, r2 += 1.6*(r2-r1));
        }
        if(f1*f2 < 0) return 1;
    }
    return -1;
}

double IRR(const vector<double>& cflow_times, const vector<double>& cflow_values){
    /* A function to find internal rate of return (if it exists) using bracketing
    and bisection approach of finding roots of a polynomial */
    const double Precision = 1.0e-5;
    double r1 = 0.0;
    double r2 = 0.2;

    if(bracketing(r1, r2, cflow_times, cflow_values) == -1) return ERROR;

    double r3;
    double dr;
    for(int i = 0; i < max_iter; i++){
        r3 = (r1+r2)/2;
        if(present_value(cflow_times, cflow_values, r2) * present_value(cflow_times, cflow_values, r3) < 0){
                r1 = r3;
            } else {
                r2 = r3;
            }
        dr = fabs(r1-r2);
        if((dr < Precision) || (fabs(present_value(cflow_times, cflow_values, r3)) < Precision)) return r3;
    }

    return ERROR;
}

int main(){
    // Internal rate of return of of cash flows -100, 10, 80 and 60 at times 0, 1, 2, 3 respectively
    vector<double> cflows{-100, 10, 80, 60};
    vector<double> times{0, 1, 2, 3};
    cout << "Internal rate of return is: " << IRR(times, cflows) << endl;
}


