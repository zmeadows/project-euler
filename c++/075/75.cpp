#include "../euler.h"

#include <algorithm>
#include <set>
#include <stdio.h>

int
main(void)
{
    const uint_t MAX_L = 1500000;
    std::set<uint_t> candidates;
    std::set<uint_t> failures;

    // Euclid's Formula: https://en.wikipedia.org/wiki/Pythagorean_triple
    for (uint_t n = 1; n < sqrt(MAX_L/2); n++) {
        for (uint_t m = n+1; 2*m*(m+n) <= MAX_L ; m += 2) {
            if (coprime(m,n)) {
                uint_t L = 2*m*(m+n);
                for (uint_t k = 1; k*L <= MAX_L; k++) {
                    if (candidates.count(k*L)) {
                        failures.insert(k*L);
                    } else {
                        candidates.insert(k*L);
                    }
                }
            }
        }
    }

    printf("%lu\n",candidates.size() - failures.size());
    return 0;
}
