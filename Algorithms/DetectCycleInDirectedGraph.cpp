#include <bits/stdc++.h>
using namespace std;

// Function to check if a cycle exists using DFS
bool dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &recStack) {
    visited[node] = 1;      // Mark the current node as visited
    recStack[node] = 1;     // Add this node to the recursion stack

    // Visit all adjacent vertices
    for (auto neighbor : adj[node]) {
        // If the neighbor is not visited, do a DFS on it
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, recStack)) {
                return true; // Found a cycle
            }
        }
        // If the neighbor is already in recursion stack → cycle found
        else if (recStack[neighbor]) {
            return true;
        }
    }

    // Remove the node from recursion stack before returning
    recStack[node] = 0;
    return false;
}

// Function to check if the directed graph has a cycle
bool isCyclic(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);
    vector<int> recStack(V, 0);

    // Check each node (for disconnected graphs)
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack)) {
                return true; // If cycle found
            }
        }
    }
    return false; // No cycle
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];
    cout << "Enter edges (u -> v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Directed edge
    }

    if (isCyclic(V, adj))
        cout << "Cycle detected in the graph.\n";
    else
        cout << "No cycle found in the graph.\n";

    return 0;
}
