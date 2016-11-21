#ifndef EULER_H
#define EULER_H

#include "math.h"
#include "stdlib.h"

typedef unsigned long long int uint_t;

uint_t
is_prime(uint_t n)
{
    if (n % 2 == 0 && n != 2)
        return 1;

    uint_t i;
    for (i = 3; i*i <= n; i += 2){
        if (n % i == 0)
            return 1;
    }
    return 0;
}

uint_t
lpd(uint_t n)
{
    if (n % 2 == 0)
        return 2;
    if (n % 3 == 0)
        return 3;
    uint_t i,j,k;
    for (i = 1; ;i++){
        j = 6*i + 1;
        if (n % j == 0 && is_prime(j))
            return j;
        k = 6*i - 1;
        if (n % k == 0 && is_prime(k))
            return k;
    }
}

uint_t
n_prime_factors(uint_t n)
{
    uint_t f, facs;
    facs = 0;
    while (n != 1){
        f = lpd(n);
        ++facs;
        n = n/f;
    }
    return facs;
}

uint_t
totient(uint_t n)
{
    uint_t f = 0;
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

uint_t
gcd(int m, int n) {
    if(m == 0 && n == 0)
        return -1;

    if(m < 0) m = -m;
    if(n < 0) n = -n;

    int r;
    while(n) {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int coprime(int m, int n) {
    return (gcd(m,n) == 1);
}

#endif
