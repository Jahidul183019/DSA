#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Graph{
    int V;
    list<int> *l;

    public:

    Graph(int V){
        this->V=V;
        l=new list<int>[V];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
    }

    //cycle detection
    bool isCycleDirDFS(int curr,vector<bool>&vis,vector<bool>&recPath){
        vis[curr]=true;
        recPath[curr]=true;

        for(int v : l[curr]){
            if(!vis[v]){
                if(isCycleDirDFS(v,vis,recPath)){
                    return true;
                }
            }else if(recPath[v]){
                    return true;
                }
        }
        recPath[curr]=false;
        return false;
    }

    bool isCycle(){
        vector<bool>vis(V,false);
        vector<bool>recPath(V,false);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCycleDirDFS(i,vis,recPath)){
                    return true;
                }
            }
        }
        return false;
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

    cout<<g.isCycle()<<endl;

    return 0;
}