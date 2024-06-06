#include "graph.cpp"
#include <chrono>
#pragma once 

const int density[]={25,50,75,100};
const int vertexAmount[]={10,50,100,500,1000};
void Tests()
{
    std::chrono::high_resolution_clock::time_point startL, startM, endL, endM;
    std::chrono::microseconds timeL, timeM;
    for(int i=0; i<4; i++)
        for(int j=0; j<5;j++)
        {
            timeL=std::chrono::microseconds::zero();
            timeM=std::chrono::microseconds::zero();
            for(int k=0; k<100;k++)
            {
                Graph *graph=new Graph(vertexAmount[j]);
                graph->GenerateGraph(density[i]);
                startL=std::chrono::high_resolution_clock::now();
                graph->DijkstraList(0);
                endL=std::chrono::high_resolution_clock::now();
                timeL+=std::chrono::duration_cast<std::chrono::microseconds>(endL-startL);
                startM=std::chrono::high_resolution_clock::now();
                graph->DijkstraMatrix(0);
                endM=std::chrono::high_resolution_clock::now();
                timeM+=std::chrono::duration_cast<std::chrono::microseconds>(endM-startM);
                delete graph;
            }
            cout<<"Dijkstra List: density "<<density[i]<<", vertex amount "<<vertexAmount[j]<<" : "<<timeL.count()/100<<" ms"<<endl;
            cout<<"Dijkstra Matrix: density "<<density[i]<<", vertex amount "<<vertexAmount[j]<<" : "<<timeM.count()/100<<" ms"<<endl;
        }
}