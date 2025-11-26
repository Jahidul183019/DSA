#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;


class Graph{
    int V;
    list<int>*l; //int *arr

    public:
    Graph(int V){
        this->V=V;
        l = new list<int>[V];
        //arr = new int[V]
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void bfs(){//O(V+E)
        queue<int>Q;
        vector<bool>vis(V,false);

        Q.push(0);
        vis[0]=true;

        while(Q.size()>0){
            int u=Q.front();//u-v
            Q.pop();
            cout<<u<<" ";

            for(int v : l[u]){//v->immedieate neighbour
                if(!vis[v]){
                    vis[v]=true;
                    Q.push(v);
                }
            }
        }
        cout<<endl;
    }

    //DFS Traversal
    void dfsHelper(int u,vector<bool>&vis){//O(V+E)
        cout<<u<<" ";
        vis[u]=true;

        for(int v : l[u]){
            if(!vis[v]){
                dfsHelper(v,vis);
            }
        }
    }

    void dfs(){
        int src=0;
        vector<bool>vis(V,false);

        dfsHelper(src,vis);
        cout<<endl;
    }

    //For Disconnected Graph
    /* 
    void dfs() {
    vector<bool> vis(V, false);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfsHelper(i, vis);
        }
    }
    cout << endl;
} */

};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    cout<<"dfs : ";
    g.dfs();

    cout<<"bfs : ";
    g.bfs();

    return 0;
}
