/* 
 * File:   main.cpp
 * Author: Zak
 *
 * Created on January 4, 2011, 1:26 PM
 */

#include "../euler.h"

/*
 * 
 */
int main(int argc, char** argv) {

    unsigned long long tot = 0;
    for (int i = 2; i <= 1000000; ++i){
        tot += totient(i);
    }
    cout << tot << endl;
}

