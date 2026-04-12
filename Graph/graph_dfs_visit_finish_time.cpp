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

    void dfsHelper(int u,vector<char>&color,vector<int>&visit_time,vector<int>&finish_time){
       color[u]='B';
       visit_time[u]=++timer;

       for(int v : l[u]){
        if(color[v]=='W'){
            dfsHelper(v,color,visit_time,finish_time);
         }
       }
       finish_time[u]=++timer;
    }

    void dfs(){
        vector<char>color(V,'W');
        vector<int>visit_time(V),finish_time(V);


        for(int i=0;i<V;i++){
        if(color[i]=='W'){
        dfsHelper(i,color,visit_time,finish_time);
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
