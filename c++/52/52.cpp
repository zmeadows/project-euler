#include "euler.h"
using namespace std;

int main()
{
    vector <int> a,b,c,d,e,f;
    unsigned long long int i;

    for (i = 1; ;i++){
        a = digitsof(i);
        b = digitsof(2*i);
        if (a != b)
            continue;
        c = digitsof(3*i);
        if (c != b)
            continue;
        d = digitsof(4*i);
        if (d != c)
            continue;
        e = digitsof(5*i);
        if (e != d)
            continue;
        f = digitsof(6*i);
        if (f == e)
            break;
    }
    
    cout << i << endl;
    return 0;
}
