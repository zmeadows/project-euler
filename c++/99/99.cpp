#include "euler.h"

int main()
{
    int base, exp, logNum, lineNum, max, maxLine;
    lineNum = 0;
    max = 0;
    maxLine = 0;
    
    ifstream baseExpPairs ("base_exp.txt");
    string line;
    
    while (getline(baseExpPairs, line)){
        istringstream tokenizer(line);
        string token;
        lineNum++;

        getline(tokenizer, token, ',');
        istringstream baseStream(token);
        baseStream >> base;
        
        getline(tokenizer, token, ',');
        istringstream expStream(token);
        expStream >> exp;
        
        logNum = exp * log(base);
        
        if (logNum > max){
            max = logNum;
            maxLine = lineNum;
        }
    }
    
    baseExpPairs.close();
    cout << maxLine << endl;
    
    return 0;
}
