#ifndef EULER_H
#define EULER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <sstream>
#include <numeric>
using namespace std;

bool isPrime(int n)
{
    if (n < 0 || (n % 2 == 0 && n != 2))
        return false;

    int i;
    for (i = 3; i*i <= n; i += 2){
        if (n % i == 0)
            return false;
    }
    return true;
}

int lpd(int n)
{
    if (n % 2 == 0)
        return 2;
    if (n % 3 == 0)
        return 3;
    int i,j,k;
    for (i = 1; ;i++){
        j = 6*i + 1;
        if (n % j == 0 && isPrime(j))
            return j;
        k = 6*i - 1;
        if (n % k == 0 && isPrime(k))
            return k;
    }
}

vector <int> primeFactors(int n)
{
    vector <int> facs;
    int f;
    while (n != 1){
        f = lpd(n);
        facs.push_back(f);
        n = n/f;
    }
    return facs;
}

int NprimeFactors(int n)
{
    int f, facs;
    facs = 0;
    while (n != 1){
        f = lpd(n);
        ++facs;
        n = n/f;
    }
    return facs;
}

int totient(int n)
{
    int f = 0;
    double q;
    double tot = (double) n;
    while (n != 1){
        q = (double) lpd(n);
        if (q != f){
            tot = tot * (1.0 - (1.0/q));
            f = q;
        }
        n = n/f;
    }
    return (int) tot;
}

int divisors(int n)
{
    vector<int> pf = primeFactors(n);
    int exp = 1;
    int divs = 1;
    for (int i = 0; i < pf.size(); i++){
        if (pf[i] == pf[i+1]){
            exp++;
        }else{
            divs *= (exp + 1);
            exp = 1;
        }
    }
    return divs;
}

vector <int> digitsof(int n)
{
    vector <int> digs (1,n % 10);
    while (n > 10){
        n /= 10;
        digs.push_back(n % 10);
    }
    return digs;
}

void perms(vector<int> init, vector<int> choices)
{
    vector<int> initCopy, choicesCopy;
    if (choices.size() == 0){
    }
    else{
        for (unsigned int j = 0; j < choices.size(); j++){
            rotate(choices.begin(), choices.begin() + 1, choices.end());
            choicesCopy = choices;
            initCopy = init;
            initCopy.push_back(choicesCopy[0]);
            choicesCopy.erase(choicesCopy.begin());
            perms(initCopy, choicesCopy);
        }
    }
}

int gcd(int a, int b)
{
	int t;
	while (b != 0){
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

unsigned long long int reverse(unsigned long long int n)
{
    unsigned long long int revn = 0;
    while (n != 0){
        revn = (revn*10) + (n % 10);
        n = n / 10;
    }
    return revn;
}

bool isPalindromic(unsigned long long int n)
{
    return (n == reverse(n));
}

#endif
