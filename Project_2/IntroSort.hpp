#include <iostream>
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
        for(int i = 0; i < size; i++)
        {
            int key = arr[i];
            int j = i - 1;
            while(j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    void printData()
    {
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};