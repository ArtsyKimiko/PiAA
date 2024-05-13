#include<iostream>
#include<cstddef>
#pragma once
using namespace std;


template <typename T>
class Sorts
{
    private:
        T *arr;
        size_t size;
        void ReadFile();
        void ReadFile(int);
        void Merge(int low, int middle, int high);
        void IntroSortRecursion(int low, int high, int depth);
    public:
        Sorts();
        Sorts(size_t);
        ~Sorts();
        int FileSize();
        void PrintArray();
        int Getsize();
        double Median();
        double Average();
        void QuickSort(int low = 0, int high = -1);
        void BucketSort();
        void MergeSort(int low = 0, int high = -1);
        void IntroSort();
};