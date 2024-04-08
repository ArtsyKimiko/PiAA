#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Packet
{
    int data;
    int priority;
};
void heap(Packet tab[], int size, int i)
{
    int max=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<size&&tab[left].priority>tab[max].priority)
        max=left;

    if(right<size&&tab[right].priority>tab[max].priority)
        max=right;

    if(max!=i) 
    {
        swap(tab[i],tab[max]);
        heap(tab,size,max);
    }
}
void sort(Packet tab[], int i, int size)
{
    swap(tab[0],tab[i]);
    heap(tab,i,0);
}
void print(Packet tab[], int size)
{
    for(int i=0;i<size;i++)
        cout<<tab[i].priority<<" ";
    cout << endl;
}
int main()
{
    int option=1;
    Packet *tab=nullptr;
    Packet *tab2=nullptr;
    int size=10;

    while(option!=0)
    {
        cout<<"Choose option: "<<endl<<"1. Size of the array"<<endl<<"2. Before sorting"<<endl
            <<"3. After sorting"<<endl<<"4. Sorting time"<<endl;
        cin>>option;
        
        switch(option)
        {
            case 1:
            {
                cout<<"Enter the size of the array: ";
                cin>>size;
                tab=new Packet[size];
                srand(time(NULL));
                for(int i=0;i<size;i++)
                    tab[i].priority=rand()%size;
                tab2=new Packet[size];
                for (int i=0;i<size;i++)
                    tab2[i].priority=tab[i].priority;
                break;
            }
            
            case 2:
            {
                print(tab2,size);
                break;
            }

            case 3:
            {
                for (int i=size/2-1;i>=0;i--)
                    heap(tab,size,i);
                for (int i=size-1;i>0;i--)
                    sort(tab,i,size);
                print(tab,size);
                break;
            }

            case 4:
            {
                auto start = chrono::high_resolution_clock::now();
                for (int i=size/2-1;i>=0;i--)
                    heap(tab,size,i);
                for (int i=size-1;i>0;i--)
                    sort(tab,i,size);
                auto stop = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
                cout<<duration.count()<<" milliseconds"<<endl;
                break;
            }

            default: 
            {
                cout<<"Wrong option"<<endl;
                option=0;
                break;
            }
        }
    }   
    delete [] tab;
    delete [] tab2;
    return 0;
}
