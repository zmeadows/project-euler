/* 
 * File:   main.cpp
 * Author: Zak
 *
 * Created on January 5, 2011, 5:11 PM
 */

#include "../euler.h"

bool twoFactors(int n)
{
    vector <int> facs;
    int f;
    while (n != 1){
        if (facs.size() == 2)
            return false;
        f = lpd(n);
        facs.push_back(f);
        n = n/f;
    }
    if (facs.size() != 2)
        return false;
    return true;
}

int main(int argc, char** argv) {

    int tot(0);
    for (int i = 1; i< 300000; ++i){
        if (twoFactors(i))
            ++tot;
    }
    cout << tot << endl;
    return 0;
}

