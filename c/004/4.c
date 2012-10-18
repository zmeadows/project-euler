#include "../euler.h"

int main(void) {

  int i,j,p;
  int pal = 0;

  for (i=100;i<1000;++i) {
    for (j=i;j<1000;++j) {
      p = i * j;
      if (is_palindrome(p) && p > pal) pal = p;
    }
  }

  printf("%d\n",pal);
  return 0;
}
