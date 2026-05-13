#include<iostream>
#include<vector>
#include<list>
#include<queue>

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
        l[v].push_back(u);
    }

    void bfs(){
        queue<int>q;
        vector<bool>vis(V,false);
        vector<int>dist(V,-1); // -1 means not reachable

        q.push(0);
        vis[0]=true;
        dist[0]=0;

        while(!q.empty()){
            int u=q.front();
            q.pop();
            cout<<u<<" ";
            
            for(auto v : l[u]){
                if(!vis[v]){
                    vis[v]=true;
                    dist[v]=dist[u]+1;
                    q.push(v);
                }
            }
        }
        cout<<endl;
        cout<<"Distances from node 0:\n";
        for(int i=0;i<V;i++){
            cout<<"Node "<<i<<" -> "<<dist[i]<<endl;
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

    g.bfs();

    
}