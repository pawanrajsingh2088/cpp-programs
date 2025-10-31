#include<bits/stdc++.h>
#define int long long
#define fast ios::sync_with_stdio(false),cin.tie(NULL);
const int MAX=1e9+7;
using namespace std;

void Prims(int n, vector<vector<pair<int, int>>>& adj) {
    vector<int> key(n, MAX);      // Minimum weight edge to connect each vertex
    vector<int> parent(n, -1);    // Store MST parent
    vector<bool> inMST(n, false); // Track vertices already in MST
    key[0] = 0; 
    for (int i = 0; i < n - 1; i++) {
        int u = -1;
        // vertex with smallest key not yet in MST
        for (int v = 0; v < n; v++) {
            if (!inMST[v] && (u == -1 || key[v] < key[u]))
                u = v;
        }
        inMST[u] = true; // Include u in MST
        // Update adjacent vertices
        for (auto &val : adj[u]) {
            if (!inMST[val.first] && val.second < key[val.first]) {
                key[val.first] = val.second;
                parent[val.first] = u;
            }
        }
    }
    // Print MST
    int totalWeight = 0;
    cout << "Edges in MST:"<<endl;
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " (weight = " << key[i] << ")"<<endl;
        totalWeight += key[i];
    }
    cout << "Total weight of MST = " << totalWeight <<endl;
}

int32_t main(){
fast;
int t=1;
// cin>>t;
while(t--){
    int n, m;
    cout << "Enter number of vertices and edges: "<<endl;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    cout << "Enter each edge as: u v w"<<endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }
    Prims(n, adj);
}
return 0;
}

