#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

class Graph{
    int V;
    list<int>* l;
    
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

    void dfsHelper(int u,vector<bool>&vis,vector<int>&finishing_order){
        vis[u]=true;

        for(auto v : l[u]){
            if(!vis[v]){
                dfsHelper(v,vis,finishing_order);
            }
        }
        finishing_order.push_back(u);
    }


    void dfs(int u,vector<bool>&vis){
        vis[u]=true;
        cout<<u<<" ";
         for(auto v : l[u]){
            if(!vis[v]){
                dfs(v,vis);
            }
        }
    }

    void printSCC(){
        vector<bool>vis(V,false);
        vector<int>finishing_order;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsHelper(i,vis,finishing_order);
            }
        }

        Graph gt=getTranspose();

        fill(vis.begin(),vis.end(),false);

        int scc=0;

        for(int i=finishing_order.size()-1;i>=0;i--){
            int node=finishing_order[i];

            if(!vis[node]){
                gt.dfs(node,vis);
                cout<<endl;
            }
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

    g.printSCC();
}