#include <iostream>
#include <vector>
#include "MergeSort.hpp"
#include "QuickSort.hpp"
#include "IntroSort.hpp"
#include "BucketSort.hpp"
#include "ReadFile.hpp"

using namespace std;

int main()
{     
    MergeSort *ms = new MergeSort();
    ms->printData();
    ms->mergeSort(0, 9);
    ms->printData();
  
    QuickSort *qs = new QuickSort();
    qs->printData();
    qs->quickSort();
    qs->printData();
    
    IntroSort *is = new IntroSort();
    is->printData();
    is->introSort();
    is->printData();

    BucketSort *bs = new BucketSort();
    bs->printData();
    bs->bucketSort();
    bs->printData();

    return 0;
}