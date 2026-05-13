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
    }

    void dfsHelper(int u,vector<char>&color,vector<int>&visit_time,vector<int>&finish_time,vector<vector<int>>&edges){
       color[u]='G';
       visit_time[u]=++timer;

       for(int v : l[u]){
        if(color[v]=='W'){
            edges.push_back({u, v, 0});
            dfsHelper(v,color,visit_time,finish_time,edges);
         }
         else if(color[v]=='G'){
            edges.push_back({u, v, 1}); 
         }
         else if(color[v]=='B' && visit_time[u]<visit_time[v]){
            edges.push_back({u, v, 2});
         }else{
             edges.push_back({u, v, 3});
         }
       }
       color[u]='B';
       finish_time[u]=++timer;
    }

    void dfs(){
        vector<char>color(V,'W');
        vector<int>visit_time(V),finish_time(V);
        vector<vector<int>>edges;

        for(int i=0;i<V;i++){
        if(color[i]=='W'){
        dfsHelper(i,color,visit_time,finish_time,edges);
        }
    }

    sort(edges.begin(), edges.end());

    string types[] = {"T","B","F","C"};
        for (auto& e : edges) {
            cout << e[0] << " " << e[1] << " (" << types[e[2]] << ")\n";
        }
    }
};

int main(){
    int V,E;

    cin>>V;
    cin>>E;

    Graph g(V);

    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;

        g.addEdge(u,v);
    }

    g.dfs();

    return 0;
}


