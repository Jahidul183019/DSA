#include<iostream>
#include<vector>
#include<vector>
#include<queue>
#include <climits>
#include<algorithm>

using namespace std;

class Edge{
    public:
    int v;
    int wt;

    Edge(int v,int wt){
        this->v=v;
        this->wt=wt;
    }
};

void bellmanFord(int src, vector<vector<Edge>>& g, int V){

    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);

    dist[src] = 0;

    int x;

    for(int i = 0; i < V; i++){

        x = -1;

        for(int u = 0; u < V; u++){

            for(Edge e : g[u]){

                if(dist[u] != INT_MAX &&
                   dist[e.v] > dist[u] + e.wt){

                    dist[e.v] = dist[u] + e.wt;

                    parent[e.v] = u;

                    x = e.v;
                }
            }
        }
    }

    // No negative cycle
    if(x == -1){

        cout << "No Negative Cycle\n";

        for(int i = 0; i < V; i++){
            cout << dist[i] << " ";
        }

        cout << endl;
        return;
    }

    // Move inside cycle
    for(int i = 0; i < V; i++){
        x = parent[x];
    }

    vector<int> cycle;

    int cur = x;

    while(true){

        cycle.push_back(cur);

        cur = parent[cur];

        if(cur == x && cycle.size() > 1)
            break;
    }

    reverse(cycle.begin(), cycle.end());

    cout << "Negative Cycle: ";

    for(int node : cycle){
        cout << node << " ";
    }

    cout << endl;
}

int main(){
    int V,E;

    cin>>V>>E;

    vector<vector<Edge>>g(V);

    for(int i=0;i<E;i++){
        int u,v,wt;
        cin>>u>>v>>wt;

        g[u].push_back(Edge(v,wt));
    }

    int src=0;

    bellmanFord(src, g, V);


}

