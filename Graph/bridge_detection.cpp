#include<iostream>
#include<vector>
#include<list>
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


    public:
        Graph(int V){
            this->V=V;
            l=new list<int>[V];
            timer=0;

            disc.assign(V, 0);
            low.assign(V, 0);
            parent.assign(V, -1);
            vis.assign(V, false);
        }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }


    void dfsHelper(int u){
        vis[u]=true;

        disc[u]=low[u]=++timer;

        for(int v : l[u]){
            if(!vis[v]){
                parent[v]=u;

                dfsHelper(v);

                low[u]=min(low[u],low[v]);

                if(low[v]>disc[u]){
                   cout << u << " - " << v << " is a BRIDGE\n";
                }
            }else if(v!=parent[u]){
                low[u]=min(low[u],disc[v]);
            }
        }
    }

    void findBridge() {
         for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsHelper(i);
            }
        }
    }
};

int main(){
    int V,E;

    cin>>V>>E;
    Graph g(V);

    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;

        g.addEdge(u,v);
    }

    g.findBridge();
   
    return 0;
}
