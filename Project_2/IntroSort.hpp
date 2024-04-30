#include <iostream>
#include <cmath>
using namespace std;

class IntroSort
{
    int *arr;
    int size;
public:
    IntroSort() {
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
    ~IntroSort() {}

    void introSort()
    {
        int maxdepth = 2 * log(size);
        introsort_recursion(0, size - 1, maxdepth);
    }
    void introsort_recursion(int low, int high, int maxdepth)
    {
        if(low < high)
        {
            if(maxdepth == 0)
            {
                heapSort(low, high);
            }
            else
            {
                int pivot = partition(low, high);
                introsort_recursion(low, pivot - 1, maxdepth - 1);
                introsort_recursion(pivot + 1, high, maxdepth - 1);
            }
        }
    }
    int partition(int low, int high)
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
    void heapSort(int low, int high)
    {
        for(int i = high / 2 - 1; i >= low; i--)
            heapify(high, i);
        for(int i = high - 1; i >= low; i--)
        {
            swap(arr[low], arr[i]);
            heapify(i, low);
        }
    }
    void heapify(int high, int i)
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
            heapify(high, largest);
        }
    }

    void printData()
    {
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};