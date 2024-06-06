#include"graph.cpp"
#include <chrono>
#pragma once


void driver()
{
    int vertex;
    cout<<"Vertices in graph: "; cin>>vertex;
    Graph *g = new Graph(vertex); 
    while(1)
    {
        int option;
        cout<<"1. Add edge\n2. Remove edge\n3. Generate random graph\n"
        <<"4. Dijkstra - adjacency list\n5. Dijkstra - adjacency matrix\n6. Check how many vertices\n"
        <<"7. Check how many edges\n8. Print matrix\n9. Print list\n10. Change number of vertices\nChoose option: ";
        cin>>option;
        int vertex1,vertex2,length,start;
        std::chrono::high_resolution_clock::time_point begin, end;
        switch(option)
        {
            case 1:
                cout<<"First vertex:"; cin>>vertex1;
                cout<<"Second vertex:"; cin>>vertex2;
                cout<<"Length:"; cin>>length;
                g->InsertEdge(vertex1, vertex2, length);
                break;
            case 2:
                cout<<"First vertex:"; cin>>vertex1;
                cout<<"Second vertex:"; cin>>vertex2;
                g->DeleteEdge(vertex1, vertex2);
                break;
            case 3:
                int density;
                cout<<"Graph density: "; cin>>density;
                g->GenerateGraph(density);
                break;
            case 4:
                cout<<"Start vertex: "; cin>>start;
                begin = std::chrono::high_resolution_clock::now();
                g->DijkstraList(start);
                end = std::chrono::high_resolution_clock::now();
                cout<<"Time: "<<std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()<<"ms\n";
                break;
            case 5:
                cout<<"Start vertex: "; cin>>start;
                begin = std::chrono::high_resolution_clock::now();
                g->DijkstraMatrix(start);
                end = std::chrono::high_resolution_clock::now();
                cout<<"Time: "<<std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()<<"ms\n";
                break;
            case 6:
                cout<<g->VertexCount()<<endl;
                break;
            case 7:
                cout<<g->EdgesCount()<<endl;
                break;
            case 8:
                g->PrintMatrix();
                break;
            case 9:
                g->PrintList();
                break;
            case 10:
                cout<<"New vertex number: "; cin>>vertex;
                delete g;
                g = new Graph(vertex);
                break;
            default:
                cout<<"Wrong option!"<<endl;
                return;
        }
    }
    delete g;
}

