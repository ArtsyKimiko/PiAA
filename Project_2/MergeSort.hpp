#include <iostream>
#include <vector>
using namespace std;

class MergeSort 
{
public:
    void mergeSort(vector<int>& arr, int left, int right); // Sorts an array using merge sort.
    void merge(vector<int>& arr, int left, int middle, int right); // Merge two subarrays of arr[].
};