#include <iostream>
#include <vector>
#include <list>
#include <stack>
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

    void dfs(int u,vector<bool>&vis,stack<int>&s){
       vis[u]=true;

       for(int v : l[u]){
        if(!vis[v]){
            dfs(v,vis,s);
         }
       }
       s.push(u);
    }

    void topoSort(){
        vector<bool>vis(V,false);
        stack<int>s;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,s);
            }
        }

        while(!s.empty()){
            cout<<s.top()<<endl;
            s.pop();
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

    g.topoSort();

    return 0;
}