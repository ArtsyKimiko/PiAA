#include <iostream>
#include <vector>
using namespace std;

class MergeSort 
{   
public:    
    MergeSort() {}
    ~MergeSort() {}

    void mergeSort(int arr[], int size, int low, int high)
    {
        if (low < high)
        {
            int middle = low + high / 2;

            mergeSort(arr, size , low, middle);
            mergeSort(arr, size, middle + 1, high);

            merge(arr, size, low, high, middle);
        }
        return;
    }
    void merge(int arr[], int size, int low, int high, int middle)
    {
        int i = low, j = middle + 1, k = low;
        int *temp = new int[size];
        while(i<=middle && j<=high)
        {
            if(arr[i] < arr[j])
            {
                temp[k] = arr[i];
                i++;
            }
            else
            {
                temp[k] = arr[j];
                j++;
            }
            k++;
        }
        while(i<=middle)
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        while(j<=high)
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
        for(int i = low; i<=high; i++)
            arr[i] = temp[i];
    }
};