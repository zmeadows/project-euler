/* 
 * File:   main.cpp
 * Author: Zak
 *
 * Created on January 3, 2011, 1:41 AM
 */

#include "../euler.h"

/*
 * 
 */
vector <unsigned long long int> psqsums;

bool isNotIn(unsigned long long int n)
{
    for (int i = 0; i < psqsums.size(); i++){
        if (n == psqsums[i])
            return false;
    }
    return true;
}

int main(int argc, char** argv) {

    unsigned long long int sum, track;
    track = 0;
    sum = 0;
    for (unsigned long long int a = 1; a < 10000; a++){
        sum = a*a;
        for (unsigned long long int b = a + 1; b < 10000; b++){
            sum += b*b;
            if (sum > 100000000)
                break;
            if (isPalindromic(sum) && isNotIn(sum))
                psqsums.push_back(sum);
        }
    }

    for (int q = 0; q < psqsums.size(); q++){
        track += psqsums[q];
    }
    cout << track << endl;
    return 0;
}

