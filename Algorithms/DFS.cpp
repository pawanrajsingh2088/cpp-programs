#include <bits/stdc++.h>
using namespace std;

void dfs_recursive(int u, const vector<vector<int>>& adj, vector<bool>& vis, vector<int>& order) {
    vis[u] = true;
    order.push_back(u);
    for (int v : adj[u]) if (!vis[v]) dfs_recursive(v, adj, vis, order);
}

vector<int> dfs_iterative(int start, const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> vis(n, false);
    vector<int> order;
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (vis[u]) continue;
        vis[u] = true;
        order.push_back(u);
        // push neighbors in reverse to mimic recursive order
        for (auto it = adj[u].rbegin(); it != adj[u].rend(); ++it) if (!vis[*it]) st.push(*it);
    }
    return order;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cout << "DFS (recursive + iterative)\nEnter number of nodes: ";
    if (!(cin >> n) || n <= 0) return 0;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> adj(n);
    cout << "Enter edges (u v) 0-based indices, one per line:\n";
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        if (u < 0 || u >= n || v < 0 || v >= n) continue;
        adj[u].push_back(v);
        adj[v].push_back(u); // treat as undirected by default
    }

    int start;
    cout << "Enter start node: ";
    cin >> start;
    if (start < 0 || start >= n) start = 0;

    vector<bool> vis(n, false);
    vector<int> order_rec;
    dfs_recursive(start, adj, vis, order_rec);

    cout << "Recursive DFS order: ";
    for (int x : order_rec) cout << x << ' ';
    cout << '\n';

    vector<int> order_it = dfs_iterative(start, adj);
    cout << "Iterative DFS order: ";
    for (int x : order_it) cout << x << ' ';
    cout << '\n';

    return 0;
}
