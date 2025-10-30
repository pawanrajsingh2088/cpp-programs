// ================================================
// 🚀 Depth First Search (DFS) in C++
// ================================================
//
// 🧠 Concept:
// Depth First Search (DFS) is a graph traversal algorithm that
// explores as far as possible along each branch before backtracking.
//
// 📘 Key Idea:
// - Use recursion or a stack to visit nodes.
// - Visit → Mark as visited → Explore all unvisited neighbors.
//
// -----------------------------------------------
// 🧩 Example Graph Used:
//
//        0
//       / \
//      1   2
//     /     \
//    3       4
//
// -----------------------------------------------
// 🔁 DFS Traversal Order (starting from 0):
// 0 → 1 → 3 → (backtrack) → 2 → 4
//
// ✅ Expected Output:
// DFS starting from vertex 0:
// 0 1 3 2 4
// ================================================

#include <bits/stdc++.h>
using namespace std;

class DFS {
    int V;                         // Number of vertices
    vector<vector<int>> adj;        // Adjacency list

public:
    // Constructor to initialize the graph
    DFS(int v) {
        V = v;
        adj.resize(v);             // Create V empty lists
    }

    // Function to add an edge (undirected)
    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    // Recursive helper function for DFS traversal
    void dfsUtil(int v, vector<bool>& visited) {
        visited[v] = true;           // Mark node as visited
        cout << v << " ";            // Print current node

        // Explore all unvisited neighbors
        for (int n : adj[v]) {
            if (!visited[n]) {
                dfsUtil(n, visited);
            }
        }
    }

    // Function to perform DFS traversal
    void dfs(int start) {
        vector<bool> visited(V, false);  // Track visited nodes
        cout << "DFS starting from vertex " << start << ":\n";
        dfsUtil(start, visited);
    }
};

// Main function
int main() {
    // Create a graph with 5 vertices (0–4)
    DFS graph(5);

    // Adding edges to form the graph:
    // 0 connected to 1 and 2
    // 1 connected to 3
    // 2 connected to 4
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    // Perform DFS starting from vertex 0
    graph.dfs(0);

    return 0;
}
