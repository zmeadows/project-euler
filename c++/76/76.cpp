#include "euler.h"

int totalWays = 0;

void hundredSums(int runningTotal)
{
    if (runningTotal == 100){
        totalWays++;
    }
    for (int i = 1; runningTotal + i <= 100; i++){
        cout << i << endl;
        hundredSums(runningTotal + i);
    }
}

int main()
{
    hundredSums(1);
    cout << totalWays;
}
