/* 
 * File:   main.cpp
 * Author: Zak
 *
 * Created on January 3, 2011, 2:53 AM
 */

#include "../euler.h"

/*
 * 
 */
#define LIMIT 3162

int primes[LIMIT];

int leastPrimeDivisor(int n)
{
    int q;
    for (int i = 0; i < LIMIT; i++){
        q = primes[i];
        if (q != 0 && n % q == 0)
            return q;
    }
    return n;
}

int totDivisors(int n)
{
    vector <int> facs;
    int f;
    while (n != 1){
        f = leastPrimeDivisor(n);
        facs.push_back(f);
        n = n/f;
    }

    int tot(1), exp(1);
    for (int i = 0; i < facs.size(); i++){
        if (facs[i] == facs[i+1])
            exp++;
        else{
            tot *= exp + 1;
            exp = 1;
        }
    }

    return tot;
}

int stepUp () {
    static int current = 2;
    return current++;
}

void genPrimes(){
    generate_n (primes, LIMIT, stepUp);
    for (int p = 2; p*p <= LIMIT; p++){
        for (int i = 2; i <= LIMIT / p; i++){
            primes[(i*p)-2] = 0;
        }
    }
}

int main(int argc, char** argv) {
    genPrimes();
    for (int i = 1; i < 10000000; i++){
        cout << totDivisors(i) << " " << i << endl;
    }
}

