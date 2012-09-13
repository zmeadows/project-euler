#include "../euler.h"

int criteria(int n) {

  if (n % 2 != 0) return 0;

  int i;
  for (i=3;i<=20;++i) {
    if (n % i != 0) return 0;
  }

  return 1;
}

int main(void) {

  int i = 2522;
  while (!criteria(i)) { i += 2; }

  printf("%i\n",i);
  return 0;
}

