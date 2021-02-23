#include <iostream>
#include <vector>

using namespace std;

const double Precision = 1.0e-5

double present_value(const vector<double>& cflow_times, const vector<double>& cflow_values, const double& r){
    double PV = 0.0;
    for(int t = 0; t < cflow_times.size(); t++){
        PV += cflow_values[t]/pow(1+r, cflow_times[t]);
    }
    return PV;
}

double IRR(const vector<double>& cflow_times, const vector<double>& cflow_values){
    double r1 = 0.0;
    double r2 = 0.2;

    double a = 1/(1+r2);
    double b = 1/(1+r1);
    double c = (a+b)/2;
    double r3 = 1/c - 1;
    while(present_value(cflow_times, cflow_values, r1) * present_value(cflow_times, cflow_values, r2) < 0
          && fabs(present_value(cflow_times, cflow_values, r3)) > Precision){
            c = (a+b)/2;
            r3 = 1/c - 1;
            if(present_value(cflow_times, cflow_values, r2) * present_value(cflow_times, cflow_values, r3) < 0){
                b = c;
                r1 = r3;
            } else {
                a = c;
                r2 = r3;
            }
          }
}

int main(){

    vector<double> cflows; cflows.push back(100.0); cflows.push back(10.0); cflows.push back(110.0);
    vector<double> times; times.push back(0.0); times.push back(1); times.push back(2);
    double r=0;
    cout << IRR(times, cflows) << endl;
}


