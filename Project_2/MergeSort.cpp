#include <iostream>
#include <vector>
#include "MergeSort.hpp"
using namespace std;

void MergeSort::merge(vector<int>& arr, int left, int middle, int right) 
{
    vector<int> temp(right - left + 1);
    int i = left, j = middle + 1, k = 0;

    while (i <= middle && j <= right) 
    {
        if (arr[i] <= arr[j]) 
            temp[k++] = arr[i++];
        else 
            temp[k++] = arr[j++];
    }

    while (i <= middle) 
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left, k=0; i <= right; ++i, ++k)
        arr[i] = temp[k];
}

void MergeSort::mergeSort(vector<int>& arr, int left, int right) 
{
    if (left < right) 
    {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}