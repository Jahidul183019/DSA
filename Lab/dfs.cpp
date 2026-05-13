#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph{
    int V;
    list<int>*l;
    int timer;
    public:
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
        timer=0;
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfsHelper(int u,vector<bool>&vis,vector<int>&visit_time,vector<int>&finish_time){
       vis[u]=true;
       visit_time[u]=++timer;

       for(int v : l[u]){
        if(!vis[v]){
            dfsHelper(v,vis,visit_time,finish_time);
         }
       }
       finish_time[u]=++timer;
    }

    void dfs(){
        vector<bool>vis(V,false);
        vector<int>visit_time(V),finish_time(V);


        for(int i=0;i<V;i++){
        if(!vis[i]){
        dfsHelper(i,vis,visit_time,finish_time);
        }
    }
        for(int i=0;i<V;i++){
        cout<<i<<": "<<visit_time[i]<<" "<<finish_time[i]<<endl;
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

    g.dfs();

    return 0;
}