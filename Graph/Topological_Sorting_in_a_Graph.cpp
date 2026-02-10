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
        l[u].push_back(v);//only directed edges
    }

    void dfs(int curr,vector<bool>&vis,stack<int>&s){
        vis[curr]=true;

        for(int v : l[curr]){
            if(!vis[v]){
                dfs(v,vis,s);
            }
        }
        s.push(curr);
    }

    void topoSort(){
        vector<bool>vis(V,false);
        stack<int>s;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,s);
            }
        }

        while(s.size()>0){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
    

    
};

int main(){
    Graph g(6);

    g.addEdge(3,1);
    g.addEdge(2,3);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(5,0);
    g.addEdge(5,3);

    g.topoSort();

    return 0;
}