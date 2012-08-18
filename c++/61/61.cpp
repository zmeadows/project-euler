#include "euler.h"
#include <cstdio>

vector<int> triangles, squares, pentagonals,
            hexagonals, heptagonals, octagonals;

vector< vector<int> > lists;

int triangle(int n)
{
    return (n * (n+1) / 2);
}

int square(int n)
{
    return (n * n);
}

int pentagonal(int n)
{
    return (n * (3*n-1) / 2);
}

int hexagonal(int n)
{
    return (n * (2*n-1));
}

int heptagonal(int n)
{
    return (n * (5*n-3) / 2);
}

int octagonal(int n)
{
    return (n * (3*n-2));
}

void fillVector(vector<int>& results, int (*function)(int))
{
    int member = 1;
    for (int i = 2; member < 10000; i++){
        if ((member > 999) && (member % 100 >= 10))
            results.push_back(member);
        member = (*function)(i);
    }
}

void findSet(vector <int> setsLeft, vector <int> accumSet)
{
    if (accumSet.size() == 6 && accumSet[5] % 100 == accumSet[0] / 100){
        int sum = 0;
        for (unsigned int k = 0; k < accumSet.size(); k++){
            sum += accumSet[k];
        }
        cout << "SUM: " << sum << endl;
    }
    
    int lastEntry = accumSet.back();
    vector <int> setsLeftCopy, accumSetCopy;
    for (unsigned int i = 0; i < setsLeft.size(); i++){
        for (unsigned int j = 0; j < lists[setsLeft[i]].size(); j++){
            if (lastEntry % 100 == (lists[setsLeft[i]])[j] / 100){
                setsLeftCopy = setsLeft;
                setsLeftCopy.erase(setsLeftCopy.begin()+i);
                accumSetCopy = accumSet;
                accumSetCopy.push_back((lists[setsLeft[i]])[j]);
                findSet(setsLeftCopy, accumSetCopy);
                break;
            }
        }
    }
}

int main()
{
    int baseInts[] = {0,1,2,3,4};
    vector<int> baseSet (baseInts, baseInts + sizeof(baseInts) / sizeof(int) );
    vector<int> triangleSeed;
    
    fillVector(triangles, &triangle);
    fillVector(squares, &square);
    fillVector(pentagonals, &pentagonal);
    fillVector(hexagonals, &hexagonal);
    fillVector(heptagonals, &heptagonal);
    fillVector(octagonals, &octagonal);

    lists.push_back(squares);
    lists.push_back(pentagonals);
    lists.push_back(hexagonals);
    lists.push_back(heptagonals);
    lists.push_back(octagonals);
    
    for (unsigned int i = 0; i < triangles.size(); i++){
        triangleSeed.push_back(triangles[i]);
        findSet(baseSet, triangleSeed);
        triangleSeed.clear();
    }
}
