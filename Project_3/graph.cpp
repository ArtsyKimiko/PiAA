#include "graph.hpp"
#pragma once
#include <random>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <limits.h>

void Graph::ZeroMatrix()
{ 
    for(int i=0; i<this->vertexCount; i++)
        for(int j=0; j<this->vertexCount; j++)
            matrix[i][j]=0;
}
 
void Graph::ClearList()
{
    for(int i=0; i<this->vertexCount; i++)
        List[i].clear();
}

Graph::Graph(int vertices) 
{
    this->vertexCount=vertices;
    this->edgesCount=0;

    matrix=new int*[this->vertexCount];
    for (int i=0; i<this->vertexCount; i++) 
        matrix[i]=new int[vertexCount];
    ZeroMatrix();

    List=new list<vPair>[vertices];
}

Graph::~Graph() 
{
    for (int i=0; i<this->vertexCount; i++) 
        delete[] matrix[i];
    delete[] matrix; 
    delete[] List;
}

void Graph::InsertEdge(int vertexCount1, int vertexCount2, int length) 
{
    matrix[vertexCount1][vertexCount2]=length;
    matrix[vertexCount2][vertexCount1]=length;
    List[vertexCount1].push_back(make_pair(vertexCount2, length));
    List[vertexCount2].push_back(make_pair(vertexCount1, length));
    this->edgesCount++;
}

void Graph::DeleteEdge(int vertexCount1, int vertexCount2) 
{
    matrix[vertexCount1][vertexCount2]=0;
    matrix[vertexCount2][vertexCount1]=0;
    for (auto i=List[vertexCount1].begin(); i!=List[vertexCount1].end(); i++) 
        if (i->first==vertexCount2) 
        {
            List[vertexCount1].erase(i);
            break;
        }
    for (auto i=List[vertexCount2].begin(); i!=List[vertexCount2].end(); i++) 
        if (i->first==vertexCount1) 
        {
            List[vertexCount2].erase(i);
            break;
        }
    this->edgesCount--;
}

void Graph::DijkstraList(int start)
{
    priority_queue<vPair, vector<vPair>, greater<vPair>> queue;
    int *totalLength=new int[this->vertexCount]; 
    bool *checked=new bool[this->vertexCount];
    for(int i=0; i<this->vertexCount; i++)
    {
        totalLength[i]=INT_MAX;
        checked[i]=false;
    }
    queue.push(make_pair(0, start));
    totalLength[start]=0;
    while(!queue.empty())
    {
        int vertexCount=queue.top().second;
        queue.pop();
        if(checked[vertexCount]==true)
            continue;  
        
        for(auto i:List[vertexCount])
        {
            int target=i.first;
            if(checked[target]==true)
                continue; 
            int length=i.second;

            if(totalLength[target]>totalLength[vertexCount]+length)
            {
                totalLength[target]=totalLength[vertexCount]+length;
                queue.push(make_pair(totalLength[target], target));
            }
        }
        checked[vertexCount]=true;
    }
    delete[] totalLength;
    delete[] checked;
}

void Graph::DijkstraMatrix(int start)
{
    priority_queue<vPair, vector<vPair>, greater<vPair>> queue;
    int *totalLength=new int[this->vertexCount];
    bool *checked=new bool[this->vertexCount];
    for(int i=0; i<this->vertexCount; i++)
    {
        totalLength[i]=INT_MAX;
        checked[i]=false;
    }
    queue.push(make_pair(0, start));
    totalLength[start]=0;
    while(!queue.empty())
    {
        int vertexCount=queue.top().second;
        queue.pop();
        if(checked[vertexCount]==true)
            continue;
        for(int i=0; i<this->vertexCount; i++)
            if(matrix[vertexCount][i]!=0)
            {
                int target=i;
                if(checked[target]==true)
                    continue;
                int length=matrix[vertexCount][i];
                if(totalLength[target]>totalLength[vertexCount]+length)
                {
                    totalLength[target]=totalLength[vertexCount]+length;
                    queue.push(make_pair(totalLength[target], target));
                }
            }
        checked[vertexCount]=true;
    }
    delete[] totalLength;
    delete[] checked;
}

void Graph::Solution(int *totalLength){
    cout<<"Distance beween start and ";
    for(int i=0; i<this->vertexCount; i++)
        cout<<i<<": "<<totalLength[i]<<"\n";
}

int Graph::VertexCount()
{
    return this->vertexCount;
}

int Graph::EdgesCount()
{
    return this->edgesCount;
}

void Graph::PrintList()
{
    for(int i=0; i<this->vertexCount; i++)
    {
        cout<<"Vertex "<<i<<" connected: ";
        for(auto j : List[i])
            cout<<j.first<<" length: "<<j.second<<"\n";
        cout<<"\n";
    }
}

void Graph::PrintMatrix()
{
    for(int i=0; i<this->vertexCount; i++)
    {
        for(int j=0; j<this->vertexCount; j++)
            cout<<matrix[i][j]<<"\t";
        cout<<"\n";
    }
}

void Graph::GenerateGraph(int density)
{
    vector<pair<int, int>> edges;
    set<pair<int, int>> checkedEdges;
    random_device rd;
    default_random_engine rng(rd());
    ZeroMatrix();
    ClearList();
    this->edgesCount=0;

    for (int u=0; u<this->vertexCount; ++u)
        for (int v=u+1; v<this->vertexCount; ++v)
            edges.push_back(make_pair(u, v));

    shuffle(edges.begin(), edges.end(), rng);

    int maxEdges=edges.size();
    int addEdges=(density * maxEdges) / 100;

    for (int i=0; i<this->vertexCount - 1; ++i) 
    {
        int currentVertex=i; 
        int nextVertex=i+1;
        int length=rand()%50+1;
        InsertEdge(currentVertex, nextVertex, length);
        checkedEdges.insert(make_pair(min(currentVertex, nextVertex), max(currentVertex, nextVertex)));
    }

    addEdges=addEdges-(this->vertexCount-1);

    int index=0;
    while (addEdges>0 && index<maxEdges)
    {
        int vertex1=edges[index].first;
        int vertex2=edges[index].second;

        if (checkedEdges.find(make_pair(min(vertex1, vertex2), max(vertex1, vertex2)))!=checkedEdges.end()) 
        {
            index++;
            continue;
        }

        InsertEdge(vertex1, vertex2, rand()%100+1);
        checkedEdges.insert(make_pair(min(vertex1, vertex2), max(vertex1, vertex2)));
        addEdges--;
        index++;
    }
}