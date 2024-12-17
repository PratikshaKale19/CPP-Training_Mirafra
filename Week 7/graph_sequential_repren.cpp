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

    // Delete an edge from the graph
    void deleteEdge(int u, int v) {
        if (adjMatrix[u][v] == 1 && adjMatrix[v][u] == 1) {
            adjMatrix[u][v] = 0; // Remove edge u -> v
            adjMatrix[v][u] = 0; // Remove edge v -> u (for undirected graph)
            cout << "Edge between " << u << " and " << v << " has been deleted." << endl;
        } else {
            cout << "No edge exists between " << u << " and " << v << " to delete." << endl;
        }
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

    // Delete an edge and display the updated graph
    g.deleteEdge(0, 4); // Deleting edge 0 -> 4

    cout << "\nAdjacency Matrix after deleting the edge 0 -> 4:" << endl;
    g.display();

    // Try to delete an edge that doesn't exist
    g.deleteEdge(3, 4); // Trying to delete edge 3 -> 4 (non-existent)

    return 0;
}
