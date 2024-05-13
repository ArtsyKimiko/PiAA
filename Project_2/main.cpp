#include <iostream>
#include<chrono>
#include"Sorts.cpp"

using namespace std;

int main() 
{
    int sort_number;
    cout<<"Enter how much data you want to read from the file (0 to read all data): ";
    cin >> sort_number;
    Sorts<int>* s;
    chrono::high_resolution_clock::time_point start, end;
    chrono::duration<double, milli> elapsed;

    if (sort_number == 0)
    {
        start = chrono::high_resolution_clock::now();
        s = new Sorts<int>();
        end = chrono::high_resolution_clock::now();
    }
    else
    {
        start = chrono::high_resolution_clock::now();
        s = new Sorts<int>(sort_number);
        end = chrono::high_resolution_clock::now();
    }
    elapsed = end - start;
    cout << "Time to load correct data: " << elapsed.count() << " ms" << endl;
    int choice = 0;

    while (true) 
    {
        cout << "\nChoose function:\n"
             << "1. Show elements\n"
             << "2. Show median value\n"
             << "3. Show average value\n"
             << "4. Show array size\n"
             << "5. Quicksort\n"
             << "6. Mergesort\n"
             << "7. Bucketsort\n"
             << "8. Introsort\n"
             << "9. Exit\n";
        cin >> choice;
        switch (choice) 
        {
        case 1:
            s->PrintArray();
            break;
        case 2:
            cout << "Median value: " << s->Median() << endl;
            break;
        case 3:
            cout << "Average value: " << s->Average() << endl;
            break;
        case 4:
            cout << "Size: " << s->Getsize() << endl;
            break;
        case 5:
            start = chrono::high_resolution_clock::now();
            s->QuickSort();
            end = chrono::high_resolution_clock::now();
            elapsed = end - start;
            cout << "Quicksort time: " << elapsed.count() << " ms" << endl;
            break;
        case 6:
            start = chrono::high_resolution_clock::now();
            s->MergeSort();
            end = chrono::high_resolution_clock::now();
            elapsed = end - start;
            cout << "Mergesort time: " << elapsed.count() << " ms" << endl;
            break;
        case 7:
            start = chrono::high_resolution_clock::now();
            s->BucketSort();
            end = chrono::high_resolution_clock::now();
            elapsed = end - start;
            cout << "Bucketsort time: " << elapsed.count() << " ms" << endl;
            break;
        case 8:
            start = chrono::high_resolution_clock::now();
            s->IntroSort();
            end = chrono::high_resolution_clock::now();
            elapsed = end - start;
            cout << "Introsort time: " << elapsed.count() << " ms" << endl;
            break;
        case 9:
            delete s;
            return 0;
        default:
            cout << "Wrong choice\n";
            break;
        }
    }
}