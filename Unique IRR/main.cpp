#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

inline int sign(const double& r){
    if(r >= 0){
        return 1;
    } else {
        return -1;
    }
}

bool unique_IRR(const vector<double>& cflow_times, const vector<double>& cflow_values){
    // Applying Descartes rule
    int sign_changes = 0;
    for(int t = 1; t < cflow_values.size(); ++t){
        if(sign(cflow_values[t-1]) != sign(cflow_values[t])) sign_changes++;
    }
    if(sign_changes == 0) return false;
    if(sign_changes == 1) return true;
    // Using result by Norstrom
    sign_changes = 0;
    double C = cflow_values[0];
    for(int t = 1; t < cflow_values.size(); ++t){
        if(sign(C) != sign(C+=cflow_values[t])) sign_changes++;
    }
    return (sign_changes <= 1);
}

int main()
{
    vector<double> cflows{-100, 10, 110};
    vector<double> times{0, 1, 2};
    cout << unique_IRR(times, cflows2) << endl;
    return 0;
}
