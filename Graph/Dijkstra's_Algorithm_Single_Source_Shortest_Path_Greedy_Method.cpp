#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Edge{
    public:
    int v;
    int wt;

    Edge(int v,int wt){
        this->v=v;
        this->wt=wt;
    }
};

void dijkstra(int src,vector<vector<Edge>>g,int V){
    vector<int>dist(V,INT_MAX);
        dist[src]=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> >pq;
        //<dist[u],u>

        pq.push({0,src});

        while(pq.size()>0){
            int u=pq.top().second;
            pq.pop();

            for(Edge e : g[u]){//Edge Relaxation Step
                if(dist[e.v] > dist[u] + e.wt){
                    dist[e.v] = dist[u] + e.wt;
                    pq.push({dist[e.v],e.v});
                }
            }
        }

        for(int i=0;i<V;i++){
            cout<<dist[i]<<" ";
        }
        cout<<endl;
}
int main(){
    int V=6;

    vector<vector<Edge>>g(V);

    g[0].push_back(Edge(1,2));
    g[0].push_back(Edge(2,4));

    g[1].push_back(Edge(2,1));
    g[1].push_back(Edge(3,7));

    g[2].push_back(Edge(4,3));

    g[3].push_back(Edge(5,1));
 
    g[4].push_back(Edge(3,2));
    g[4].push_back(Edge(5,5));

    dijkstra(0,g,V);
    return 0;
}
