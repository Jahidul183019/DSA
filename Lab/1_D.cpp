#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Graph{
    int V;
    list<int>*l;
    int timer=0;

    vector<int>disc;
    vector<int>low;
    vector<int>parent;
    vector<bool>vis;

    public: 
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
        timer=0;

        disc.assign(V,0);
        low.assign(V,0);
        parent.assign(V, -1);
        vis.assign(V,false);
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfs(int u,vector<vector<int>>&ans){
        vis[u]=true;

        disc[u]=low[u]=++timer;


        for(int v : l[u]){
            if(!vis[v]){
                parent[v]=u;
                dfs(v,ans);

                low[u]=min(low[u],low[v]);

                if(low[v]>disc[u]){
                    ans.push_back({min(u,v), max(u,v)});
                }
            }else if(v!=parent[u]){
                low[u]=min(low[u],disc[v]);
            }
        }
    }

    void findBridges(){
        vector<vector<int>>ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,ans);
            }
        }

        sort(ans.begin(),ans.end());

        for (auto &x : ans) {
            cout << x[0] << " " << x[1] << endl;
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

    g.findBridges();
}