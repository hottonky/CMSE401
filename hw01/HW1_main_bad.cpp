#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>

#include "print.h"

int main()
{
    float x_min = 0;
    float x_max = 10;
    float n_x_lo = 511;
    float n_x = n_x_lo + 1;

    float d_x = (x_max-x_min)/n_x_lo;

    std::vector<double> x(n_x);

    std::generate(x.begin(), x.end(), [n = 0, d_x] () mutable { return d_x * n++; });

    float t_min = 0;
    float t_max = 1;
    float n_t = 100; //1000000

    float d_t = (t_max-t_min)/n_t;

    std::vector<double> t(n_t);

    std::generate(t.begin(), t.end(), [n = 0, d_t] () mutable {return d_t * n++; });

    std::vector<double> y(n_x);

    std::generate(y.begin(), y.end(), [n = 0, x] () mutable { return std::exp(-1*std::pow(x[n++]-5,2)); });

    y.at(0) = 0;
    y.at(n_x-1) = 0;

    std::vector<double> v(n_x, 0); // y acceleration for all n_x
    std::vector<double> a(n_x, 0); // y acceleration for all n_x

    float gamma = 1;

    std::ofstream HW1_curve_pos;
    HW1_curve_pos.open("Data/HW1_curve_pos.csv");
    
    std::ofstream HW1_curve_vel;
    HW1_curve_vel.open("Data/HW1_curve_vel.csv");
    
    std::ofstream HW1_curve_acc;
    HW1_curve_acc.open("Data/HW1_curve_acc.csv");

    // save x positions as the first line
    for(int i=0; i < x.size(); i++) {
        if (i == (x.size() - 1)) {
            HW1_curve_pos << x.at(i);
        }
        else {
            HW1_curve_pos << x.at(i) << ',';
        }
    }

    HW1_curve_pos << '\n';

    for (int j = 0; j < n_t; j++) {

        a.at(0) = 0;

        for(int i = 1; i < (n_x-1); i++) {
            a.at(i) = gamma * ( y.at(i+1) + y.at(i-1) - (2*y.at(i)) ) / (d_x*d_x);

            y.at(i) = y.at(i) + v.at(i)*d_t;
            v.at(i) = v.at(i) + a.at(i)*d_t;
        }

        a.at(n_x - 1) = 0;

        // save each set of y positions as a new line in the csv
        for(int i=0; i < y.size(); i++) {
            if (i == (y.size() - 1)) {
                HW1_curve_pos << y.at(i);
                HW1_curve_vel << v.at(i);
                HW1_curve_acc << a.at(i);
            }
            else {
                HW1_curve_pos << y.at(i) << ',';
                HW1_curve_vel << v.at(i) << ',';
                HW1_curve_acc << a.at(i) << ',';
            }
        }
        
        HW1_curve_pos << '\n';
        HW1_curve_vel << '\n';
        HW1_curve_acc << '\n';

    }

    HW1_curve_pos.close();
    HW1_curve_vel.close();
    HW1_curve_acc.close();
    
}