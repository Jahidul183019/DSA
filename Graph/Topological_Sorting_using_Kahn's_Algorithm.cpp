#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph{
    int V;
    list<int>*l;

    public:
    Graph(int V){
        this->V= V;
        l=new list<int>[V];
        
    }
        void addEdge(int u,int v){
            l[u].push_back(v); //only directed edges
        }

        void topoSort(){
            vector<int>res;

            //Calculate indegree
            vector<int>indeg(V,0);

            for(int u=0;u<V;u++){
                for(int v : l[u]){
                    indeg[v]++;
                }
            }

            //0 indegree => Q

            queue<int>q;
            
            for(int i=0;i<V;i++){
                if(indeg[i]==0){
                    q.push(i);
                }
            }

            //bfs
            while(q.size()>0){
                int curr=q.front();
                q.pop();
                res.push_back(curr);

                for(int v:l[curr]){
                    indeg[v]--;
                    if(indeg[v]==0){
                        q.push(v);
                    }
                }
            }

            //result
            for(int val : res){
                cout<<val<<" ";
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
    g.addEdge(5,2);

    g.topoSort();
}
