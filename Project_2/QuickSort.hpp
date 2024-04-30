#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class QuickSort
{
    int *arr;
    int size;
public:    
    QuickSort() {
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
    ~QuickSort() {}

    void quickSort()
    {
        srand(time(NULL));
        quicksort_recursion(0, size - 1);
    }
    void quicksort_recursion(int low, int high)
    {
        if(low < high)
        {
            int pivot = partition(low, high);
            quicksort_recursion(low, pivot - 1);
            quicksort_recursion(pivot + 1, high);
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
    void printData()
    {
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};