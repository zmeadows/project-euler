/* 
 * File:   main.cpp
 * Author: Zak
 *
 * Created on January 4, 2011, 12:53 PM
 */

#include "../euler.h"

vector<int> primes(0);

bool isPrimez(int n)
{
    for (int i = 2; i*i < n; ++i){
        if (n % i == 0)
            return false;
    }
    return true;
}

void genPrimes(int limit)
{
    int curMaxPrime = primes.back();
    static int i = 1;
    int j,k;

    for ( ; primes.size() <= limit; ++i){
        j = (6*i) - 1;
        k = (6*i) + 1;
        if (isPrime(j))
            primes.push_back(j);
        if (isPrime(k))
            primes.push_back(k);
    }
}

int getNthPrime(int n)
{
    if (primes.size() < n)
        genPrimes(n);
    return primes[n-1];
}

int main(int argc, char* argv[])
{
    primes.push_back(2);
    primes.push_back(3);
    cout << getNthPrime(522385) << endl;

    return 0;
}

