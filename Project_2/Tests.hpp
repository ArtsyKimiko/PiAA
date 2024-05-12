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
    int size2;
public:
    Test(ifstream &input, int orginal_size)
    {
        //size2 = orginal_size;
        arr = new double[orginal_size];
        testReadFile(input, orginal_size);
        //testSorts(orginal_size);
    }
    ~Test()
    {
        delete[] arr;
    }
    void reload(double orginal[], int size)
    {
        cout<<"jestem"<<endl;
        for(int i = 0; i < size; i++)
            this->arr[i] = orginal[i];
        cout<<"jestem2"<<endl;
    }
    void testReadFile(ifstream &input, int size)
    {
        ReadFile *rf = new ReadFile(input, size);
        auto start = chrono::high_resolution_clock::now();
            rf->readData(input, size);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
       
        cout<<"ReadFile\t"<<size<<"\t"<<duration.count()<<" microseconds"<<endl;
        //reload(rf->array, size);
        delete rf;
    }

    void averageValue(double arr[], int size)
    {
        long double sum = 0;
        for(int i = 0; i < size; i++)
            sum += arr[i];
        cout<<"Average value: "<<sum/size<<endl;
    }
    void medianValue(double arr[])
    {
        if(size2 % 2 == 0)
            cout<<"Median value: "<<(arr[size2/2] + arr[size2/2 - 1])/2<<endl;
        else
            cout<<"Median value: "<<arr[size2/2]<<endl;
    }

    // void testSorts(int size)
    // {
    //     reload(size);
    //     auto start = chrono::high_resolution_clock::now();
    //         BucketSort *bs = new BucketSort(arr, size);
    //     auto stop = chrono::high_resolution_clock::now();
    //     auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    //     cout<<"BucketSort\t"<<size<<"\t"<<duration.count()<<" microseconds"<<endl;
    //     averageValue(arr, size);
    //     medianValue(arr);
    //     delete bs;

    //     reload(size);
    //     start = chrono::high_resolution_clock::now();
    //         IntroSort *is = new IntroSort(arr, size);
    //     stop = chrono::high_resolution_clock::now();
    //     duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    //     cout<<"IntroSort\t"<<size<<"\t"<<duration.count()<<" microseconds"<<endl;
    //     averageValue(arr, size);
    //     medianValue(arr);
    //     delete is;

    //     reload(size);
    //     start = chrono::high_resolution_clock::now();
    //         MergeSort *ms = new MergeSort(arr, size);
    //     stop = chrono::high_resolution_clock::now();
    //     duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    //     cout<<"MergeSort\t"<<size<<"\t"<<duration.count()<<" microseconds"<<endl;
    //     averageValue(arr, size);
    //     medianValue(arr);
    //     delete ms;

    //     // reload(array_to_sort);
    //     // start = chrono::high_resolution_clock::now();
    //     //     QuickSort *qs = new QuickSort(arr, size);
    //     // stop = chrono::high_resolution_clock::now();
    //     // duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    //     // cout<<"QuickSort\t"<<size<<"\t"<<duration.count()<<" microseconds"<<endl;
    //     // averageValue(arr);
    //     // medianValue(arr);
    //     // delete ms;
    // }
};