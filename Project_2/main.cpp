#include <iostream>
#include <vector>
#include "MergeSort.hpp"
//#include "QuickSort.hpp"
//#include "IntroSort.hpp"
//#include "BucketSort.hpp"

using namespace std;

int main()
{
    int size = 7;
    int arr[7] = { 12, 11, 13, 5, 6, 7, 1 };
    //int *arr = new int[size];
    int low = 0;
    int high = size - 1;

    MergeSort m;

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    m.mergeSort(arr, size, low, high);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}