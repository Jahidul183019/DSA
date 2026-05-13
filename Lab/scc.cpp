#include<iostream>
#include<vector>
#include <list>
#include <algorithm>

using namespace std;

class Graph{
    int V;
    list<int>*l;

    public:
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
    }

    Graph getTranspose(){
        Graph g(V);

        for(int i=0;i<V;i++){
            for(auto v : l[i]){
                g.addEdge(v,i);
            }
        }
        return g;
    }

    void dfsHelper(int u,vector<bool>&vis,vector<int>&finish_time){
        vis[u]=true;

        for(auto v : l[u]){
            if(!vis[v]){
                dfsHelper(v,vis,finish_time);
            }
        }
        finish_time.push_back(u);
    }

    void dfs(int u, vector<bool>& vis){
    vis[u] = true;

        for (int v : l[u]) {
            if (!vis[v]) {
                dfs(v, vis);
            }
        }
    }

    int kosarajuSCC(){
        vector<bool>vis(V,false);
        vector<int>finish_time;

    for(int i=0;i<V;i++){
        if(!vis[i]){
        dfsHelper(i,vis,finish_time);
        }
    }

    Graph gt=getTranspose();

    fill(vis.begin(),vis.end(),false);

    int scc=0;

    for(int i=finish_time.size()-1;i>=0;i--){
        int node=finish_time[i];

        if(!vis[node]){
            gt.dfs(node,vis);
            scc++;
        }
    }
    return scc;
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

    cout<<g.kosarajuSCC()<<endl;
   
    return 0;
}