#include <iostream>
#include <vector>
#include "MergeSort.hpp"
//#include "QuickSort.hpp"
//#include "IntroSort.hpp"
//#include "BucketSort.hpp"

using namespace std;

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();
    MergeSort m;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    m.mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}