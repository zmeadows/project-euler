#include "euler.h"
#include <algorithm>
using namespace std;

vector <int> pentagonals (1,1);

/* This function doesn't work unless called sequentially,
 * i.e must call pentagonal(2) before pentagonal(3), etc. */
int pentagonal(unsigned int n)
{
    if (pentagonals.size() < n )
        pentagonals.push_back((n*((3*n)-1))/2);
    return pentagonals[n-1];
}

bool ispentagonal(int n)
{
    int i = pentagonals.size();
    int p = -1;
    if (pentagonals.back() < n)
        for ( ; p < n; i++){
            p = pentagonal(i);
        }
    if (p == n)
        return true;
    return (binary_search (pentagonals.begin(), pentagonals.end(), n));
}


int main()
{
    int i,j,ip,jp;

    for (i=1; ; i++){
        ip = pentagonal(i);
        for (j=1; j < i; j++){
            jp = pentagonal(j);
            if (ispentagonal(ip+jp) && ispentagonal(abs(ip-jp)))
                goto end;
        }
    }

    end:
    cout << abs(ip-jp) << endl;
}
