#include "../euler.h"

int main(void) {

  int sumsq = 0;
  int sqsum = 0;

  int i;
  for (i=1;i<=100;++i) {
    sumsq += i*i;
    sqsum += i;
  }

  sqsum *= sqsum;

  printf("%i\n",abs(sumsq - sqsum));
  return 0;
}
