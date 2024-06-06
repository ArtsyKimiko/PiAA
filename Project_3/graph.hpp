#include <iostream>
#include <list>
#pragma once
using namespace std;

typedef pair<int, int> vPair; // Vertex Pair to store weight and destination vertex
class Graph {
    private:
        int vertexCount; // Ilość wierzchołków
        int edgesCount; // Ilość krawędzi
        int **matrix;    // macierz sąsiedztwa (wskażnik na wskażniki)
        list<pair<int,int>> *List; // Lista sąsiedztwa
        void InitializationMatrix(); // inicjalizaacja macierzy sąsiedztwa - jednocześnie ustawienie wszystkich wartości na 0
        void DestroyMatrix(); // Usunięcie macierzy sąsiedztwa
        void ZeroMatrix(); // Ustawienie wszystkich wartości macierzy na 0
        void ClearList(); // Czyszczenie listy sąsiedztwa
    public:
        Graph(int vertexCount); // Konstruktor

        void InsertEdge(int V1, int V2, int weight); // Dodanie krawędzi
        void DeleteEdge(int V1, int V2); // Usunięcie krawędzi
        void DijkstraMatrix(int StartVertex); // Dijkstra algorytm z macierzą sąsiedztwa
        void DijkstraList(int StartVertex); // Dijkstra algorithm with acency List
        void Solution(int *dist); // Print the solution of Dijkstra algorithm
        void PrintMatrix(); // Print acency Matrix
        void PrintList(); // Print acency List
        int VertexCount(); // Get number of vertices
        int EdgesCount(); // Get number of edges
        void GenerateGraph(int density); // Generate random graph
        ~Graph(); // Destrucktor
};