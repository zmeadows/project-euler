#include "euler.h"
using namespace std;

struct pair {
    int a,b,cps;
} coefficients;

int main()
{
    int i,j,n,f;
    coefficients.cps = 0;

    for (i = -999; i <= 999; i++){
        for (j = -999; j <= 999; j++){
            for (n = 1, f = j; isPrime(f); n++){
                f = n*n + i*n + j;
            }
            if (n > coefficients.cps){
                coefficients.a = i;
                coefficients.b = j;
                coefficients.cps = n;
            }
        }
    }

    cout << coefficients.a * coefficients.b << endl;
    return 0;
}
