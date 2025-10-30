#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Structure to store one edge (start -> end -> weight)
struct Edge {
    int u, v, w;
};

// Function to find shortest paths using Bellman-Ford
void bellmanFord(int V, int E, vector<Edge>& edges, int src) {
    // Step 1: Set all distances to infinity
    vector<int> dist(V, INT_MAX);
    dist[src] = 0; // Distance to source is 0

    // Step 2: Relax all edges V-1 times
    // (Each vertex can have at most V-1 edges in the shortest path)
    for (int i = 0; i < V - 1; i++) {
        for (auto e : edges) {
            // If distance to u is known and a shorter path to v is found
            if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Step 3: Check for negative weight cycles
    for (auto e : edges) {
        if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
            cout << "⚠️ Graph has a negative weight cycle!\n";
            return;
        }
    }

    // Step 4: Print shortest distances from source
    cout << "\nShortest distances from source vertex " << src << ":\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << "Vertex " << i << " : Not reachable\n";
        else
            cout << "Vertex " << i << " : " << dist[i] << "\n";
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    bellmanFord(V, E, edges, src);

    return 0;
}
git 