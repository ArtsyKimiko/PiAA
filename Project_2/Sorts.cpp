#include<iostream>
#include<fstream>
#include <algorithm> 
#include<vector>
#include<random>
#include<string>
#include<sstream>
using namespace std;
#include"Sorts.hpp"

template <typename T>
int Sorts<T>::FileSize()
{
    int size = 0;
    ifstream file("projekt2_dane.csv");
    if (!file.is_open()){
        cout << "Error opening file" <<  endl;
        return 0;
    }
    string line,data;
    size_t pos = string::npos;
    int grade = 0;
    while (std::getline(file, line)) 
    {
        pos = line.find_last_of(",");
        if(pos != string::npos)
        {
            data = line.substr(pos + 1);
            try 
            {
                grade = std::stoi(data);
                size++;
            } catch (const std::invalid_argument& e) {}
        }
    }
    file.clear();
    file.seekg(0);
    return size;
}
template <typename T>
Sorts<T>::Sorts()
{
    this->size = FileSize();
    this->arr = new T[this->size];
    ReadFile();
}
template <typename T>
Sorts<T>::Sorts(size_t customSize)
{
    this->size = customSize;
    this->arr = new T[this->size];
    ReadFile();
}
template <typename T>
void Sorts<T>::ReadFile()
{
    ifstream file("projekt2_dane.csv");
    if (!file.is_open())
        return;
    
    string line, data;
    size_t  pos = string::npos;
    for (int i = 0; i < this->size && getline(file,line); i++)
    {
        pos = line.find_last_of(",");
        if(pos != string::npos)
        {
            data = line.substr(pos + 1);
            try
            {
                this->arr[i] = stoi(data);
            } 
            catch(const invalid_argument& e){ i--; }
        }
    }
    file.close();
}
template <typename T>
Sorts<T>::~Sorts()
{
    delete[] arr;
}
template <typename T>
int Sorts<T>::Getsize()
{
    return size;
}
template <typename T>
double Sorts<T>::Median()
{
    if(size % 2 == 0)
        return (arr[size / 2] + arr[size / 2 - 1]) / 2.0;
    else
        return arr[size / 2];
}
template <typename T>
double Sorts<T>::Average()
{
    double sum = 0;
    for(int i = 0; i < size; i++)
        sum += arr[i];
    return sum / size;
}
template <typename T>
void Sorts<T>::PrintArray()
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
template <typename T>
void Sorts<T>::QuickSort(int low, int high)
{
    if(high == -1)
        high = size - 1;
        
    int low2 = low, high2 = high;
    T pivot = arr[(low + high) / 2];
    while (low2 <= high2) 
    {
        while (arr[low2] < pivot)
            low2++;
        while (arr[high2] > pivot)
            high2--;
        if (low2 <= high2)
        {
            swap(arr[low2], arr[high2]);
            low2++;
            high2--;
        }
    }
    if (low < high2)
        QuickSort(low, high2);
    if (low2 < high)
        QuickSort(low2, high);
}
template <typename T>
void Sorts<T>::MergeSort(int low, int high)
{
    if (high == -1)
        high = size - 1;
    if (low < high)
    {
        int middle = (low + high) / 2;

        MergeSort(low, middle);
        MergeSort(middle + 1, high);

        Merge(low, middle, high);
    }
    return;
}
template <typename T>
void Sorts<T>::Merge(int low, int middle, int high)
{
    int i = low, j = middle + 1, k = low;
    T *temp = new T[size];
    while(i<=middle && j<=high)
    {
        if(arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i<=middle)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for(int i = low; i< k; i++)
        arr[i] = temp[i];

    delete temp;
}
template<typename T>
void Sorts<T>::BucketSort() 
{
    double max = arr[0];
    for(int i = 1; i < size; i++)
        if(arr[i] > max)
            max = arr[i];
    
    int bucket_size = static_cast<int>(max) + 1;
    double *bucket = new double[bucket_size];

    for(int i = 0; i < bucket_size; i++)
        bucket[i] = 0;
    for(int i = 0; i < size; i++)
        bucket[static_cast<int>(arr[i])]++;
    for(int i = 0, j = 0; i < bucket_size; i++)
    {
        while(bucket[i] > 0)
        {
            arr[j++] = i;
            bucket[i]--;
        }
    }
    delete bucket;
}
template<typename T>
void Sorts<T>::IntroSort() 
{
    int max_depth = 2 * log(size);
    IntroSortRecursion(0, size - 1, max_depth);
}
template<typename T>
void Sorts<T>::IntroSortRecursion(int low, int high, int max_depth) 
{
    if (max_depth == 0)
    {
        MergeSort(low, high);
        return;
    }
    else
    {
        int low2 = low, high2 = high;
        T pivot = arr[(low + high) / 2];
        while (low2 <= high2) 
        {
            while (arr[low2] < pivot)
                low2++;
            while (arr[high2] > pivot)
                high2--;
            if (low2 <= high2)
            {
                swap(arr[low2], arr[high2]);
                low2++;
                high2--;
            }
        }
        if (low < high2)
            IntroSortRecursion(low, high2, max_depth - 1);
        if (low2 < high)
            IntroSortRecursion(low2, high, max_depth - 1);
    }
}