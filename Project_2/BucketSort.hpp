#include <iostream>
using namespace std;

class BucketSort
{
public:
    BucketSort(double arr[], int size) 
    {
        double max = arr[0];
        for(int i = 1; i < size; i++)
            if(arr[i] > max)
                max = arr[i];
        
        int bucketSize = static_cast<int>(max) + 1;
        double *bucket = new double[bucketSize];

        for(int i = 0; i < bucketSize; i++)
            bucket[i] = 0;
        for(int i = 0; i < size; i++)
            bucket[static_cast<int>(arr[i])]++;
        for(int i = 0, j = 0; i < bucketSize; i++)
        {
            while(bucket[i] > 0)
            {
                arr[j++] = i;
                bucket[i]--;
            }
        }
    }
    ~BucketSort() {}

    void printData(double arr[], int size)
    {
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};