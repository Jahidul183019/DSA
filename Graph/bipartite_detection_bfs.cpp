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
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool bfs(){//O(V+E)
        queue<int>Q;
        vector<int>color(V,-1);

       for (int i = 0;i<V;i++) {

            if (color[i]==-1) {
                Q.push(i);
                color[i]=0;
            

        while(Q.size()>0){
            int u=Q.front();//u-v
            Q.pop();

            for(int v : l[u]){//v->immedieate neighbour
                if(color[v]==-1){
                    color[v]=1-color[u];
                    Q.push(v);
                }else if(color[v]==color[u]){
                    return false;
                }
            }
        }
    }
}
        return true;
    }
};

int main(){
    int V, E;
    cin>>V>>E;

    Graph g(V);


    for (int i=0;i<E;i++) {
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }

    if (g.bfs())
        cout<<"Graph is Bipartite\n";
    else
        cout<<"Graph is NOT Bipartite\n";

    return 0;
}