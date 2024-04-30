#include <iostream>
using namespace std;

class BucketSort
{
    int *arr;
    int size;
public:
    BucketSort() {
        arr = new int[10];
        arr[0] = 100;
        arr[1] = 19;
        arr[2] = 28;
        arr[3] = 7;
        arr[4] = 16;
        arr[5] = 9;
        arr[6] = 4;
        arr[7] = 10;
        arr[8] = 7;
        arr[9] = 13;
        size = 10;
    }
    ~BucketSort() {}

    void bucketSort()
    {
        int max = arr[0];
        for(int i = 1; i < size; i++)
        {
            if(arr[i] > max)
                max = arr[i];
        }
        int *bucket = new int[max + 1];
        for(int i = 0; i <= max; i++)
            bucket[i] = 0;
        for(int i = 0; i < size; i++)
            bucket[arr[i]]++;
        for(int i = 0, j = 0; i <= max; i++)
        {
            while(bucket[i] > 0)
            {
                arr[j++] = i;
                bucket[i]--;
            }
        }
    }
    void printData()
    {
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};