#include "euler.h"
using namespace std;

int divSum(int n)
{
    int i, c;
    c = 1;
    
    for (i = 2; i*i <= n; i++){
        if (n % i == 0 && i*i == n)
            c += i;
        else if (n % i == 0)
            c += i + n/i;
    }

    return c;
}

int main()
{
    vector <int> abunds;
    vector <int> candidates;
    int i;
    
    for (i = 1; i <= 28123; i++){
        if (divSum(i) > i)
            abunds.push_back(i);
    }

    for (i = 0; i <= 28123; i++){
        candidates.push_back(i);
    }

    int cansize = candidates.size();
    int abunsize = abunds.size();
    int j,k,ja,ka;
    for (j = 0; j < abunsize; j++){
        ja = abunds[j];
        for (k = j; k < abunsize; k++){
            ka = abunds[k];
            if (ja + ka > cansize)
                break;
            if (ja + ka < cansize)
                candidates[ja + ka] = 0;
        }
    }

    int c = 0;
    for (i = 0; i < cansize; i++){
        c += candidates[i];
    }

    cout << c << endl;
	cin.get();
    return 0;
}
