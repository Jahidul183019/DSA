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

void bellmanFord(int src,vector<vector<Edge>>&g,int V){
    vector<int>dist(V,INT_MAX);
    dist[src]=0;

    for(int i=0;i<V-1;i++){
        for(int u=0;u<V;u++){
            for(Edge e : g[u]){
                if(dist[e.v]>dist[u]+e.wt){
                    dist[e.v]=dist[u]+e.wt;
                }
            }
        }
    }
    bool negativeCycle=false;

    for(int u=0;u<V;u++){
            for(Edge e : g[u]){
                if(dist[u]!=INT_MAX && dist[e.v]>dist[u]+e.wt){
                    negativeCycle=true;
                }
            }
        }

    if(negativeCycle){
        cout<<"Negative Weight Cycle Detected"<<endl;
        return;
    }

    for(int i=0;i<V;i++){
    cout<<dist[i]<<" ";
    }
    cout<<endl;
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

