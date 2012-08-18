#include "euler.h"
#include <fstream>
#include <sstream>
#include<scvode/cvode_dense.h>
using namespace std;

int main()
{
    float vertices[6];
    int c,i,ty; // test y
    bool rpi, rni; // "real positive intercept, real negative intercept"
    c = 0;

    ifstream triangles ("triangles.txt");
    string line;

    while (getline(triangles, line)){
        istringstream tokenizer(line);
        string token;

        for (i = 0; i < 6; i++){
            getline(tokenizer, token, ',');
            istringstream point(token);
            point >> vertices[i];
        }

    triangles.close();
    }

    return 0;
}

