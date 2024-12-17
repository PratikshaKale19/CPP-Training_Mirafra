#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adjMatrix; // Adjacency matrix

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        adjMatrix.resize(V, vector<int>(V, 0)); // Initialize matrix with 0s
    }

    // Add an edge to the graph
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1; // For directed graph
        adjMatrix[v][u] = 1; // For undirected graph (if needed)
    }

    // Display the adjacency matrix
    void display() {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    // Display the adjacency matrix
    cout << "Adjacency Matrix of the Graph:" << endl;
    g.display();

    return 0;
}
