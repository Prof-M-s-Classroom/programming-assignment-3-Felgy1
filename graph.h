#ifndef GRAPH_H
#define GRAPH_H
#include "heap.h"

class Graph {
public:
    Graph(int vertices) {
        numVertices = vertices;

        adjMatrix = new int*[vertices]; //Creates adjacency matrix
        for (int i = 0; i < vertices; i++) { //Created arrays in matrix
            adjMatrix[i] = new int[vertices];

            for (int j = 0; j < vertices; j++) { //initializes edges to 0
                adjMatrix[i][j] = 0;
            }
        }
    }

    ~Graph() {
        for (int i = 0; i < numVertices; i++) { //deletes the adjacency matrix
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    void primMST() {
        int* key = new int[numVertices]; //stores min weight to add each vertex
        int* parent = new int[numVertices]; //stores MST structure
        bool* inMST = new bool[numVertices]; //tracks vertices included

        MinHeap minHeap(numVertices);

        for (int v = 0; v < numVertices; v++) { //initializes keys and MST
            key[v] = INT_MAX;
            parent[v] = -1;
            inMST[v] = false;
        }

        key[0] = 0; //starts at vertex 0
        for (int v = 0; v < numVertices; v++) {
            minHeap.insert(v, key[v]);
        }

        std::cout << "Edge \tWeight\n";
        int totalWeight = 0;

        while (!minHeap.isEmpty()) {
            int u = minHeap.extractMin(); //vertex with smallest key value
            inMST[u] = true;

            for (int v = 0; v < numVertices; v++) { //runs for every adjacent vertices v of u
                if (adjMatrix[u][v] && !inMST[v] && adjMatrix[u][v] < key[v]) {
                    key[v] = adjMatrix[u][v];
                    parent[v] = u;
                    minHeap.decreaseKey(v, key[v]);
                }
            }
        }
        for (int i = 1; i < numVertices; i++) { //prints edges
            std::cout << parent[i] << " - " << i << "\t" << adjMatrix[i][parent[i]] << "\n";
            totalWeight += adjMatrix[i][parent[i]];
        }

        std::cout << "Total Weight: " << totalWeight << std::endl;

        delete[] key;
        delete[] parent;
        delete[] inMST;
    }// Must print MST edges and total weight

private:
    int** adjMatrix;
    int numVertices;
};

#endif