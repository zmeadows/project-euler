#include "euler.h"
#include <fstream>
#include <sstream>
using namespace std;

const vector <int> candidates[8] = {0,1,2,3,6,7,8,9};

int main()
{
    int tries[50][3];
    int pdigits[8];
    int password[8];

    ifstream handlog ("poker.txt");
    string line;
    
    int i,j;
    for (i = 0; i < 50; i++){
        getline(entries, line);
        for (j = 0; j < 3; j++){
            digit = (line.substr (j,1));
            tries[i][j] = atoi(digit.c_str());
        }
    }

    pdigits = candidates;
    for (i = 0; i < 50; i++){
        for (j = 0; j < 3; j++){
            if (j == 0 || tries[i][j-1] == -1)
                continue;

            

    return 0;
}
