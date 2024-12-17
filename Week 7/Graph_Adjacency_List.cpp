#include <iostream>
#include <list>
#include <map>
#include <algorithm> // For remove function
using namespace std;

class Graph {
    map<int, list<int> > adjList; // Adjacency list to store the graph

public:
    // Function to add an edge between vertices u and v of the graph
    void add_edge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Function to delete an edge between vertices u and v of the graph
    void delete_edge(int u, int v) {
        // Remove v from the adjacency list of u
        adjList[u].remove(v);
        // Remove u from the adjacency list of v
        adjList[v].remove(u);
    }

    // Function to print the adjacency list representation of the graph
    void print() {
        cout << "Adjacency list for the Graph: " << endl;
        // Iterate over each vertex
        for (auto i : adjList) {
            cout << i.first << " -> ";
            // Iterate over the connected vertices
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph object
    Graph g;

    // Add edges to create the graph
    g.add_edge(1, 0);
    g.add_edge(2, 0);
    g.add_edge(1, 2);

    // Print the adjacency list before deletion
    cout << "Graph before deleting the edge:" << endl;
    g.print();

    // Delete the edge between 1 and 2
    g.delete_edge(1, 2);

    // Print the adjacency list after deletion
    cout << "\nGraph after deleting the edge between 1 and 2:" << endl;
    g.print();

    return 0;
}
