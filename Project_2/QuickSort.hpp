#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

class QuickSort {
public:    
    QuickSort(double arr[], int size) 
    {
        srand(time(NULL));
        quicksort(arr, 0, size - 1);
    }
    void quicksort(double arr[], int low, int high) 
    {
        while (low < high) {
            int pivotIndex = partition(arr, low, high);
            if (pivotIndex - low < high - pivotIndex) 
            {
                quicksort(arr, low, pivotIndex - 1);
                low = pivotIndex + 1;
            } 
            else 
            {
                quicksort(arr, pivotIndex + 1, high);
                high = pivotIndex - 1;
            }
        }
    }
    int partition(double arr[], int low, int high) 
    {
        int pivotIndex = getPivotIndex(arr, low, high);
        if (pivotIndex != high)
            swap(arr[pivotIndex], arr[high]);

        double pivot = arr[high];
        int i = low;
        for (int j = low; j < high; j++) 
            if (arr[j] <= arr[high]) 
            {
                swap(arr[i], arr[j]);
                i++;
            }

        swap(arr[i], arr[high]);
        return i;
    }
    int getPivotIndex(double arr[], int low, int high) 
    {
        int indices[5];
        for (int i = 0; i < 5; i++)
            indices[i] = rand() % (high - low + 1) + low;
        sort(indices, indices + 5, [&](int a, int b) { return arr[a] < arr[b]; });
        return indices[2];
    }
    void swap(double& a, double& b) 
    {
        double temp = a;
        a = b;
        b = temp;
    }
    void printData(double arr[], int size) 
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};
