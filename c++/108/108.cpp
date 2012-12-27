#include <cstdio>
#include <cmath>

unsigned long long int
distinct_solutions(unsigned long long int n)
{
    unsigned long long int x, y;
    unsigned long long int solutions = 0;

    for (x = n+1; x < y; ++x) {
        y = n*x / (x-n);
        if ((x*y) % (x+y) == 0) solutions++;
    }

    return solutions;
}

int
main(void)
{
    unsigned long long int n;
    unsigned long long int sol = 0;
    for (n = 50000; sol <= 1000; ++n) {
        sol = distinct_solutions(n);
    }
    printf("%d\n",n);
}
