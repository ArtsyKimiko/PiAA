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
    rf->printData(10);
   
    // MergeSort *ms = new MergeSort();
    // ms->printData();
    // ms->mergeSort(0, 9);
    // ms->printData();
  
    QuickSort *qs = new QuickSort();
    qs->printData();
    qs->quickSort();
    qs->printData();
    
    // IntroSort *is = new IntroSort();
    // is->printData();
    // is->introSort();
    // is->printData();

    // BucketSort *bs = new BucketSort();
    // bs->printData();
    // bs->bucketSort();
    // bs->printData();

    delete rf;
    // delete ms;
    delete qs;
    // delete is;
    // delete bs;

    return 0;
}