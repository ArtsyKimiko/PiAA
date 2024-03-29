#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;

void insert(int tab[], int i)
{
    if(((i-1)/2)>(-1)&& tab[(i-1)/2]<tab[i])
    {
        swap(tab[(i-1)/2], tab[i]);
        insert(tab,(i-1)/2);
    }
}
void sort(int tab[], int i, int size)
{
    swap(tab[0],tab[i]);
    for(int j=0;j<i;j++)
        insert(tab,j);
}
int main()
{
    int size = 50000;
    int tab[size];

    srand(time(NULL));
    for(int i=0;i<(size+1);i++)
        tab[i]=rand()%1000;

    auto start = chrono::high_resolution_clock::now();

    for(int i=0;i<size;i++)
        insert(tab,i);

    for(int i=size;i>0;i--)
        sort(tab,i,size);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

    cout << size << "\t" << duration.count() << endl;

    return 0;
}
