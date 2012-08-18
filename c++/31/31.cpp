#include "euler.h"
using namespace std;

int main()
{
    int a,b,c,d,e,f,g,h,count;

    for (a = 0; a <= 200; a += 200){
        for (b = 0; b <= 200; b += 100){
            for (c = 0; c <= 200; c += 50){
                for (d = 0; d <= 200;  d += 20){
                    for (e = 0; e <= 200; e += 10){
                        for (f = 0; f <= 200; f += 5){
                            for (g = 0; g <= 200; g += 2){
                                for (h = 0; h <= 200; h += 1){
                                    if (a+b+c+d+e+f+g+h == 200)
                                        count++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}
