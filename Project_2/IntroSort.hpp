#include <iostream>
#include <cmath>
using namespace std;

class IntroSort
{
public:
    IntroSort(double arr[], int size) 
    {
        int maxdepth = 2 * log(size);
        introsort_recursion(arr, 0, size - 1, maxdepth);
    }
    ~IntroSort() {}

    void introsort_recursion(double arr[], int low, int high, int maxdepth)
    {
        if(low < high)
        {
            if(maxdepth == 0)
            {
                heapSort(arr, low, high);
            }
            else
            {
                int pivot = partition(arr, low, high);
                introsort_recursion(arr, low, pivot - 1, maxdepth - 1);
                introsort_recursion(arr, pivot + 1, high, maxdepth - 1);
            }
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
    void heapSort(double arr[], int low, int high)
    {
        for(int i = high / 2 - 1; i >= low; i--)
            heapify(arr, high, i);
        for(int i = high - 1; i >= low; i--)
        {
            swap(arr[low], arr[i]);
            heapify(arr, i, low);
        }
    }
    void heapify(double arr[], int high, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < high && arr[left] > arr[largest])
            largest = left;
        if(right < high && arr[right] > arr[largest])
            largest = right;
        if(largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, high, largest);
        }
    }
    void printData(double arr[], int size)
    {
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};