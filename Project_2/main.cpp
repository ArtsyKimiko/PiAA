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
    
    
    int size[12] = {10000, 50000, 100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, read->fileSize()};
    for(int i = 0; i < 12; i++)
    {
        Test *t = new Test(input, size[i]);
        delete t;
    }
    input.close();

    delete read;
    return 0;
}