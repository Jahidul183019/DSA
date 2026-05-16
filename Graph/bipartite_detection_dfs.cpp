#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int>* l;
    
public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }
    
    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    
    bool dfsHelper(int u, vector<int>& color, int c) {
        color[u] = c;  // color current node
        
        for (int v : l[u]) {
            if (color[v] == -1) {                    // unvisited
                if (!dfsHelper(v, color, 1 - c)) {   // recurse with opposite color
                    return false;
                }
            } else if (color[v] == color[u]) {       // same color = conflict
                return false;
            }
        }
        return true;
    }
    
    bool dfs() {
        vector<int> color(V, -1);
        
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {          // unvisited = new component
                if (!dfsHelper(i, color, 0)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    Graph g(V);
    
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    
    if (g.dfs())
        cout << "Graph is Bipartite\n";
    else
        cout << "Graph is NOT Bipartite\n";
    
    return 0;
}