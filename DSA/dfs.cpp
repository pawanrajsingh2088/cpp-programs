#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> buildGraph(int n, const vector<pair<int,int>>& edges, bool directed = false) {
    vector<vector<int>> adj(n);
    for (auto &e : edges) {
        int u = e.first, v = e.second;
        adj[u].push_back(v);
        if (!directed) adj[v].push_back(u);
    }
    return adj;
}

void dfsUtil(int u, const vector<vector<int>> &adj, vector<int> &visited, vector<int> &parent) {
    visited[u] = 1;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            dfsUtil(v, adj, visited, parent);
        }
    }
}

void dfs(const vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> visited(n, 0), parent(n, -1);
    int components = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            components++;
            cout << "Component " << components << ": ";
            dfsUtil(i, adj, visited, parent);
            cout << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // --u; --v; // uncomment if input is 1-indexed
        edges.emplace_back(u, v);
    }

    vector<vector<int>> adj = buildGraph(n, edges, false);
    cout << "DFS Traversal:\n";
    dfs(adj);

    return 0;
}