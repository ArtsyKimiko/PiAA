#include <iostream>
using namespace std;

class BucketSort
{
    int *arr;
    int size;
public:
    BucketSort() {}
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