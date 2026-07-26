#include<iostream>
#include<vector>
#include<list>
#include <algorithm>
#include <stack>

using namespace std;

class Graph{
    int V;
    vector<vector<int>>adj;

    public:
        Graph(int V){
            this->V=V;
            adj.resize(V);
        }

    void addEdge(int u,int v){
        adj[u].push_back(v);
    }

    void topoSort(int curr,vector<bool>&vis,stack<int>&s){
        vis[curr]=true;

        for(int neigh : adj[curr]){
            if(!vis[neigh]){
                topoSort(neigh,vis,s);
            }
        }
        s.push(curr);
    }

    void dfs(int curr, vector<bool>& vis,vector<vector<int>>&transpose) {
        vis[curr] = true;

        cout<<curr<<" ";

        for (int neigh : transpose[curr]) {
            if (!vis[neigh]) {
                dfs(neigh, vis, transpose);
            }
        }
    }

    void kosarajuSCC(){
        //step 1 - topo order => O(V+E)
        stack<int>s;

        vector<bool>vis(V,false);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                topoSort(i,vis,s);
            }
        }

        //step 2 - transpose graph => O(V+E)
        vector<vector<int>>transpose(V);

        for(int u=0;u<V;u++){// u --> v
            vis[u]=false;
            for(int v : adj[u]){
                transpose[v].push_back(u);
            }
        }

        //step 3 - dfs on transpose graph
        cout<<"Printing the SCC: \n";

        while(s.size()>0){
            int curr=s.top();
            s.pop();

            if(!vis[curr]){
                dfs(curr,vis,transpose); // scc print
                cout<<endl;
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

    g.kosarajuSCC();
   
    return 0;
}
