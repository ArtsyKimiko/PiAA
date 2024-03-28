#include <iostream>
using namespace std;

void insert(int tab[], int i)
{
    if(((i-1)/2)>(-1)&& tab[(i-1)/2]<tab[i])
    {
        swap(tab[(i-1)/2], tab[i]);
        insert(tab,(i-1)/2);
    }
}
void ins2(int tab[], int i, int size)
{
    if((2*i+1)<size && tab[2*i+1]>tab[i])
    {
        swap(tab[2*i+1], tab[i]);
        ins2(tab,2*i+1,size);
    }
    if((2*i+2)<size && tab[2*i+2]>tab[i])
    {
        swap(tab[2*i+2], tab[i]);
        ins2(tab,2*i+2,size);
    }
}

void sort(int tab[], int i, int size)
{
    if((2*i+2)<size && (2*i+1)<size && tab[2*i+1]<tab[2*i+2])
    {
        swap(tab[2*i+1],tab[2*i+2]);
        ins2(tab,(2*i+2),size);

        sort(tab,(2*i+1),size);
    }
}

int main()
{
    int size = 15;
    int tab[size];
    
    for(int i=0;i<(size+1);i++)
        tab[i]=i;

    for(int i=0;i<size;i++)
    {
        int s=0;
        if(i==0) s=(size/2);
        if(i>0 && i<3) s=(size/3);
        if(i>2 && i<7) s=(size/6);
        for(int j=0;j<s;j++)
            cout<<" ";

        cout<<tab[i]<<" ";
        
        if(i==0 || i==2 || i==6)
            cout<<endl;
    }
    
    for(int i=0;i<size;i++)
        insert(tab,i);

    cout<<endl<<endl;
    for(int i=0;i<size;i++)
    {
        int s=0;
        if(i==0) s=(size/2);
        if(i>0 && i<3) s=(size/3);
        if(i>2 && i<7) s=(size/6);
        for(int j=0;j<s;j++)
                cout<<" ";
        cout<<tab[i]<<" ";
        
        if(i==0 || i==2 || i==6)
            cout<<endl;
    }

    for(int i=0;i<size;i++)
        sort(tab,i,size);

    cout<<endl<<endl;
    for(int i=0;i<size;i++)
        cout<<tab[i]<<" ";
    
        
        
    cout<<endl;

    return 0;
}
