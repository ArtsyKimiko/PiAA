#include <iostream>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <fstream>
#include "MergeSort.hpp"
#include "QuickSort.hpp"
#include "IntroSort.hpp"
#include "BucketSort.hpp"
#include "ReadFile.hpp"

using namespace std;

class Test
{
    double *arr;
    int size;
public:
    Test(ifstream &input, int orginal_size)
    {
        size = orginal_size;
        arr = new double[size];
        testReadFile(input, size);
        testSorts(arr);
    }
    ~Test()
    {
        delete[] arr;
    }
    void reload(double orginal[], int size)
    {
        for(int i = 0; i < size; i++)
            arr[i] = orginal[i];
    }
    void testReadFile(ifstream &input, int size)
    {
        auto start = chrono::high_resolution_clock::now();
        ReadFile *rf = new ReadFile(input, size);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
       
        cout<<"ReadFile\t"<<size<<"\t"<<duration.count()<<" microseconds"<<endl;
        reload(rf->array, rf->real_size);
        delete rf;
    }
    void testSorts(double array_to_sort[])
    {
        reload(array_to_sort, size);
        auto start = chrono::high_resolution_clock::now();
            BucketSort *bs = new BucketSort(arr, size);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout<<"BucketSort\t"<<size<<"\t"<<duration.count()<<" microseconds"<<endl;
        delete bs;

        reload(array_to_sort, size);
        start = chrono::high_resolution_clock::now();
            IntroSort *is = new IntroSort(arr, size);
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout<<"IntroSort\t"<<size<<"\t"<<duration.count()<<" microseconds"<<endl;
        delete is;

        reload(array_to_sort, size);
        start = chrono::high_resolution_clock::now();
            MergeSort *ms = new MergeSort(arr, size);
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout<<"MergeSort\t"<<size<<"\t"<<duration.count()<<" microseconds"<<endl;
        delete ms;

        // reload(array_to_sort, size);
        // start = chrono::high_resolution_clock::now();
        //     QuickSort *qs = new QuickSort(arr, size);
        // stop = chrono::high_resolution_clock::now();
        // duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        // cout<<"QuickSort\t"<<size<<"\t"<<duration.count()<<" microseconds"<<endl;
        // delete qs;
    }
};