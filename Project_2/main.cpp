#include <iostream>
#include <fstream>
#include "Tests.hpp"

using namespace std;

int main()
{     
    ifstream input("projekt2_dane.csv");
    if (!input.is_open())
        return 1;
    ReadFile *read = new ReadFile(input,0);
    
    int size[5] = {10000, 100000, 500000, 1000000, read->testSize()};
    for(int i = 0; i < 5; i++)
    {
        Test *t = new Test(input, size[i]);
        delete t;
    }
    input.close();

    delete read;
    return 0;
}