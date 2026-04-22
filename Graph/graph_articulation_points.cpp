#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Graph{
    int V;
    list<int>*l;
    int timer;

    vector<int>disc;
    vector<int>low;
    vector<int>parent;
    vector<bool>vis;
    vector<bool>ap; // articulation point

public:
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
        timer=0;

        disc.assign(V, 0);
        low.assign(V, 0);
        parent.assign(V, -1);
        vis.assign(V, false);
        ap.assign(V, false);
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u); // undirected graph
    }

    void dfsHelper(int u){
        vis[u]=true;

        disc[u]=low[u]=++timer;

        int children=0;

        for(int v : l[u]){
            if(!vis[v]){
                children++;
                parent[v]=u;

                dfsHelper(v);

                low[u]=min(low[u],low[v]);

                // non-root articulation point
                if(parent[u]!=-1 && low[v]>=disc[u]){
                    ap[u]=true;
                }
            }else if(v!=parent[u]){
                low[u]=min(low[u],disc[v]);
            }
        }
        if(parent[u]==-1 && children>1){
            ap[u]=true;
        } 
    }

    void dfs(){
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsHelper(i);
            }
        }

        cout<<"Articulation Points :\n";
        for(int i=0;i<V;i++){
            if(ap[i]){
                cout<<i<<endl;
            }
        }
    }
};

int main(){
    int V,E;
    cin>>V>>E;

    Graph g(V+1);

    for(int i=1;i<=E;i++){
        int u,v;

        cin>>u>>v;

        g.addEdge(u,v);
    }

    g.dfs();
}
