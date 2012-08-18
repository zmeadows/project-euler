/* 
 * File:   main.cpp
 * Author: Zak
 *
 * Created on January 5, 2011, 11:50 AM
 */

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

struct cont {
    int a,b,den;
};

bool operator == (cont param, cont param2) {
    if (param.a == param2.a &&
            param.b == param2.b &&
            param.den == param2.den)
        return true;
    return false;
}

int sqrtPeriod(int n)
{
    vector<cont> period;
    int a,b,den;
    double sqn = sqrt(n);
    a = floor(sqn);
    den = n - a*a;
    b = a;
    for (int i = b + 1; ;++i){
        if (i % den == 0 && ((sqn + (b - i)) / den) < 1){
            a = i / den;
            b = - (b - i);
            den = (n - b*b) / den;
            i = b + 1;
            cont entry;
            entry.a = a;
            entry.b = b;
            entry.den = den;
            period.push_back(entry);
            int psize = period.size();
            if (psize % 2 == 0 && psize != 0){
                vector<cont> firstHalf;
                vector<cont> secondHalf;
                for (int r = 0; r < psize / 2; ++r){
                    firstHalf.push_back(period[r]);
                    secondHalf.push_back(period[(psize / 2) + r]);
                }
                cout << firstHalf[0].a << " " << secondHalf[0].a << endl;
                if (firstHalf == secondHalf){
                    return period.size() / 2;
                }
            }
            cout << entry.den << " " << entry.b << " " << entry.a << endl;
        }
    }          
    return period.size();
}

int main(int argc, char** argv) {

    cout << sqrtPeriod(2) << endl;
    return 0;
}

