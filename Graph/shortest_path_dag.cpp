#include <bits/stdc++.h>
using namespace std;

void topoSort(int node,
              vector<vector<pair<int, int>>>& adj,
              vector<int>& visited,
              stack<int>& st) {

    visited[node] = 1;

    for (auto edge : adj[node]) {
        int nextNode = edge.first;

        if (!visited[nextNode]) {
            topoSort(nextNode, adj, visited, st);
        }
    }

    st.push(node);
}

int main() {

    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);

    // Input edges: u v weight
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;

        adj[u].push_back({v, weight});
    }

    // -------------------------
    // Topological Sort
    // -------------------------

    vector<int> visited(V, 0);
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topoSort(i, adj, visited, st);
        }
    }

    // -------------------------
    // Shortest Path
    // -------------------------

    vector<int> dist(V, INT_MAX);

    int source = 0;
    dist[source] = 0;

    while (!st.empty()) {

        int u = st.top();
        st.pop();

        // If source cannot reach u
        if (dist[u] == INT_MAX) {
            continue;
        }

        // Relax all outgoing edges
        for (auto edge : adj[u]) {

            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // -------------------------
    // Print Answer
    // -------------------------

    cout << "Shortest distances from source " << source << ":\n";

    for (int i = 0; i < V; i++) {

        if (dist[i] == INT_MAX) {
            cout << i << " -> -1\n";
        } else {
            cout << i << " -> " << dist[i] << "\n";
        }
    }

    return 0;
}
