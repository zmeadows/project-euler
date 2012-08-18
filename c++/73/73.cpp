#include "euler.h"

int main()
{
	const double oneThird = 1.0/3.0;
	const double oneHalf = 1.0/2.0;
	double n,d,f;
	int total = 0;

	for (d = 1.0; d <= 12000; d += 1.0){
		for (n = 1.0; n < d; n += 1.0){
			f = n / d;
			if (gcd(n,d) == 1 && f > oneThird && f < oneHalf){
				total++;
			}
		}
	}

	cout << total;
}
