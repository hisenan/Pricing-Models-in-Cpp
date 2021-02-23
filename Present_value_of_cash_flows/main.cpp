#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double present_value(const vector<double>& cflow_times, const vector<double>& cflow_values, const double& r){
    double PV = 0.0;
    for(int t = 0; t < cflow_times.size(); t++){
        PV += cflow_values[t]/pow(1+r, cflow_times[t]);
    }
    return PV;
}

int main()
{
    // Present of value of cash flows -100, 75 and 75 at times 0, 1 and 2 respectively, discounting done at the rate of 10%
    vector<double> cflow_values;
    cflow_values.push_back(-100);
    cflow_values.push_back(75);
    cflow_values.push_back(75);
    vector<double> cflow_times;
    cflow_times.push_back(0);
    cflow_times.push_back(1);
    cflow_times.push_back(2);
    double r = 0.1;
    double PV;
    PV = present_value(cflow_times, cflow_values, r);
    cout << "The present value is:" << PV << endl;
    return 0;
}
