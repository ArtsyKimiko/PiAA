#include <iostream>
#include <vector>
using namespace std;

class MergeSort 
{   
    int *arr;
    int size;
public:    
    MergeSort() {
        arr = new int[10];
        arr[0] = 10;
        arr[1] = 9;
        arr[2] = 8;
        arr[3] = 7;
        arr[4] = 6;
        arr[5] = 5;
        arr[6] = 4;
        arr[7] = 3;
        arr[8] = 2;
        arr[9] = 1;
        size = 10;
    }
    ~MergeSort() {}

    void mergeSort(int low, int high)
    {
        if (low < high)
        {
            int middle = (low + high) / 2;

            mergeSort(low, middle); // sort [low, middle]
            mergeSort(middle + 1, high); // sort (middle, high], in other words [middle + 1, high]

            merge(low, high, middle);
        }
        return;
    }
    void merge(int low, int high, int middle)
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
        for(int i = low; i< k; i++)
            arr[i] = temp[i];
    }
    void printData()
    {
        for(int i = 0; i<size; i++)
            cout<<arr[i]<<" ";
        cout << '\n';
    }
};