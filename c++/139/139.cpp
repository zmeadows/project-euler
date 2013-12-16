/* http://projecteuler.net/problem=139 */

#include "math.h"
#include <stdio.h>
#include <stdint.h>
#include "../euler.h"

#define MAX_PERIMETER 100000000

int main() {

    uint64_t a,b,c,m,n,count;

    count = 0;

    /* Euclid's formula for generating primitive pythagorean triples */
    for (m=2;2*m*(m+1)<MAX_PERIMETER;m++) {
        for (n=1; n<m && 2*m*m+2*m*n < MAX_PERIMETER ;n++) {

            /* only deal with PRIMTIVE triples (m,n coprime and m-n odd) */
            if (gcd(m,n) == 1 && ((m-n) % 2) == 1) {

                a = m*m - n*n;
                b = 2*m*n;
                c = m*m + n*n;

                /* check if the triple obeys tiling properties */
                if (c % (a<b?b-a:a-b) == 0) {

                    /* account for all non-primitive multiples of a,b,c
                     * that still have less than MAX_PERIMETER perimeter */
                    count += MAX_PERIMETER / (a+b+c);
                }

            }
        }
    }

    printf ("%llu\n",count);

    return 0;
}


