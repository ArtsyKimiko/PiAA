#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;

void heap(int tab[], int size, int i)
{
    int max=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<size&&tab[left]>tab[max])
        max=left;

    if(right<size&&tab[right]>tab[max])
        max=right;

    if(max!=i) 
    {
        swap(tab[i],tab[max]);
        heap(tab,size,max);
    }
}
void sort(int tab[], int i, int size)
{
    swap(tab[0],tab[i]);
    heap(tab,i,0);
}
void print(int tab[], int size)
{
    for(int i=0;i<size;i++)
        cout<<tab[i]<<" ";
    cout << endl;
}
int main()
{
    cout<<"Enter the size of the array: ";
    int size;
    cin>>size;
    int *tab = new int[size];
    srand(time(NULL));
    for(int i=0;i<size;i++)
        tab[i]=rand()%size;

    cout<<"Choose option: "<<endl
        <<"1. Before sorting"<<endl
        <<"2. After sorting"<<endl
        <<"3. Sorting time"<<endl;
    int option;
    cin>>option;

    if(option==1)
        print(tab,size);

    auto start = chrono::high_resolution_clock::now();

    for (int i=size/2-1;i>=0;i--)
        heap(tab,size,i);
    for (int i=size-1;i>0;i--)
        sort(tab,i,size);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

    if(option==2)
        print(tab,size);

    if(option==3)
        cout<<duration.count()<<" milliseconds"<<endl;

    if(option!=1&&option!=2&&option!=3)
        cout<<"Wrong option"<<endl;
        
    delete [] tab;
    return 0;
}
