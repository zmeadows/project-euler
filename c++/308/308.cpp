#include "euler.h"
#include <gmp.h>
using namespace std;


int main()
{
    int frac,iteration;
    mpz_t seed, goal, top, toptest, bottom, modulo;
    mpz_inits (goal, seed, top, toptest, bottom, modulo, NULL);
    mpz_set_ui (seed, 2);
    mpz_ui_pow_ui (goal, 3, 104743);

    unsigned long int numerator[14] = {17,78,19,23,29,77,95,77,1,11,13,15,1,55};
    unsigned long int denominator[14] = {91,85,51,38,33,29,23,19,17,13,11,2,7,1};

    for (iteration = 1; ; iteration++){
        if ((mpz_cmp (seed, goal)) == 0)
            break;
        for (frac = 0; frac < 14; frac++){
            mpz_set_ui (top, numerator[frac]);
            mpz_set_ui (bottom, denominator[frac]);
            mpz_mul (toptest, seed, top);
            mpz_mod (modulo, toptest, bottom);
            if ((mpz_cmp_ui (modulo, 0)) == 0){
                mpz_divexact (seed, toptest, bottom);
                break;
            }
        }
    }

    cout << iteration - 1 << endl;
    return 0;
}
