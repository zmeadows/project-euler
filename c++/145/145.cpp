#include "euler.h"

int reverse(int n)
{
    int revn = 0;
    while (n > 0){
        revn = revn*10 + (n % 10);
        n /= 10;
    }
    return revn;
}

bool oddDigits(int n)
{
    while(n > 0){
        if (n % 2 == 0)
            return false;
        n /= 10;
    }
    return true;
}

int main()
{
    int count = 0;
    for (int i = 1; i < 1000000000; i++){
        if (i % 10 == 0)
            continue;
        if (oddDigits(i + reverse(i)))
            count++;
    }
    cout << count << endl;
}
