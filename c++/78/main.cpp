/* 
 * File:   main.cpp
 * Author: Zak
 *
 * Created on January 3, 2011, 6:05 PM
 */

#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;
/*
 * 
 */

std::map<unsigned long long int, unsigned long long int> results;
unsigned long long int total = 0;

unsigned long long int genCombos(unsigned long long int lastCoin, unsigned long long int goal, unsigned long long int coinTotal = 0)
{
    if (coinTotal == goal){
        ++total;
    }else{
        for (unsigned long long int i = 1; i <= lastCoin && i + coinTotal <= goal; ++i){
            genCombos(i, goal, coinTotal + i);
        }
    }
    return total;
}

unsigned long long int getCombos(unsigned long long int n)
{
    if (results.find(n) != results.end())
        return results[n];
    unsigned long long int answer = genCombos(n,n);
    results[n] = answer;
    return answer;
}

int main(int argc, char** argv) {
    for (unsigned long long int i = 1; i < 300; ++i){
        if (getCombos(i) % 1000000 == 0){
            cout << i << endl;
            break;
        }
        total = 0;
    }
    return 0;
}

