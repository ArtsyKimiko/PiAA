#include <iostream>
#include <fstream>
#include <vector>
#include "MergeSort.hpp"
#include "QuickSort.hpp"
#include "IntroSort.hpp"
#include "BucketSort.hpp"
#include "ReadFile.hpp"

using namespace std;

int main()
{     
    ifstream input("projekt2_dane.csv");
    if (!input.is_open())
        return 1;

    ReadFile *rf = new ReadFile(input);
    input.close();
    int size = 10;
    double *arr = new double[size];

    for(int i = 0; i < size; i++)
        arr[i] = rf->array[i];

    BucketSort *bs = new BucketSort(arr, size);
    delete bs;

    IntroSort *is = new IntroSort(arr, size);
    delete is;

    MergeSort *ms = new MergeSort();
    ms->mergeSort(rf->array, size, 0, size);
    delete ms;
  
    QuickSort *qs = new QuickSort(arr , size);
    delete qs;
    
    delete rf;
    
    return 0;
}