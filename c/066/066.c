#include "stdio.h"
#include "math.h"

inline int is_integer(double n)
{
  return n - (double)(int)n == 0.0;
}

int main(void) {
    double x_max = 0;
    double D_max = 5.0;

    double x,y,D;

    for (D = 5.0;D <= 1000.0; D = D+1) {
        for (x = floor(sqrt(floor((double) D) + 1)); ;x = x+1) {
            // printf("%f,%f\n", D, x);
            y = sqrt( (x*x-1)/D );
            if (is_integer(y)) {
                x_max = fmax( x, x_max );
                if (x_max == x) { D_max = D; }
                printf("x = %f,y = %f,D = %f,x_max = %f, D_max = %f\n", x,y,D,x_max,D_max);
                break;
            }
        }
    }
}
