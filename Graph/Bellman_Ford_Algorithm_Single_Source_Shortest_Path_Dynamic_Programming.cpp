#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Edge{
    public:
    int v;
    int wt;

    Edge(int v,int wt){
        this->v = v;
        this->wt = wt;
    }
};

void bellmanFord(int src,vector<vector<Edge>> g,int V){
    vector<int>dist(V,INT_MAX);
    dist[src]=0;

    for(int i=0;i<V-1;i++){
        for(int u=0;u<V;u++){ //u---->v
            for(Edge e : g[u]){
                if(dist[e.v]>dist[u]+e.wt){
                    dist[e.v]=dist[u]+e.wt;
                }
            }
        }
    }
    for(int i=0;i<V;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int V=5;

    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1,2));
    g[0].push_back(Edge(2,4));

    g[1].push_back(Edge(4,-1));
    g[1].push_back(Edge(2,-4));

    g[2].push_back(Edge(3,2));

    g[3].push_back(Edge(4,4));

    bellmanFord(0,g,V);

}