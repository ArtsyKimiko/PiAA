#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class QuickSort
{
public:    
    QuickSort(double arr[], int size) 
    {
        srand(time(NULL));
        quicksort_recursion(arr, 0, size - 1);
    }
    ~QuickSort() {}

    void quicksort_recursion(double arr[], int low, int high)
    {
        if(low < high)
        {
            int pivot = partition(arr, low, high);
            quicksort_recursion(arr, low, pivot - 1);
            quicksort_recursion(arr, pivot + 1, high);
        }
    }
    int partition(double arr[], int low, int high)
    {
        int pivot = low + rand() % (high - low + 1);
        if(pivot != high)
            swap(arr[pivot], arr[high]);

        int i = low;
        for(int j = low; j < high; j++)
        {
            if(arr[j] <= arr[high])
            {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[high]);
        return i;
    }
    void printData(double arr[], int size)
    {
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};