#include<iostream>
#include<vector>

using namespace std;

class Graph{
    vector<vector<pair<int,int> >>adj;
    int V;
    
    public:
    Graph(int V){
        this->V=V;
        adj.resize(V);
    }

    void addEdge(int u,int v,int wt){
        adj[u].push_back({v,wt});
    }

    void floydWarshall(){
        const int INF=1e9; // 1 billion

        vector<vector<int>>dist(V,vector<int>(V,INF));

        for(int i=0;i<V;i++){
                dist[i][i]=0;
        }
        
        for(int u=0;u<V;u++){
            for(auto edge : adj[u]){
                int v=edge.first;
                int wt=edge.second;

                dist[u][v]=wt;
            }
        }

        //core logic 
        for(int k=0;k<V;k++){
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                    dist[i][j]=min(dist[i][j],
                                   dist[i][k]+dist[k][j]);
                }
            }
        }

        //print
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dist[i][j]==INF){
                    cout<<"INF ";
                }else{
                    cout<<dist[i][j]<<" ";
                }
            }
            cout<<endl;
        }
    }
};

int main(){
    int V, E;

    cin >> V >> E;

    Graph g(V);

    for (int i=0;i<E; i++) {

        int u, v, wt;

        cin>>u>>v>>wt;

        g.addEdge(u, v, wt);
    }

    g.floydWarshall();


}