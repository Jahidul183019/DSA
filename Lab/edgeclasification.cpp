#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph{
    int V;
    list<int>* l;
    int timer;

public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
        timer = 0;
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
    }

    void dfsHelper(int u,
                   vector<char>& color,
                   vector<int>& disc,
                   vector<int>& fin){

        color[u] = 'B';
        disc[u] = ++timer;

        for(int v : l[u]){

            if(color[v] == 'W'){
                cout << u << " " << v << " Tree Edge\n";
                dfsHelper(v, color, disc, fin);
            }

            else if(color[v] == 'B'){
                cout << u << " " << v << " Back Edge\n";
            }

            else if(color[v] == 'C'){
                if(disc[u] < disc[v])
                    cout << u << " " << v << " Forward Edge\n";
                else
                    cout << u << " " << v << " Cross Edge\n";
            }
        }

        color[u] = 'C';
        fin[u] = ++timer;
    }

    void dfs(){
        vector<char> color(V,'W');
        vector<int> disc(V,0), fin(V,0);

        for(int i=0;i<V;i++){
            if(color[i]=='W'){
                dfsHelper(i,color,disc,fin);
            }
        }
    }
};

int main(){
    int V,E;
    cin >> V >> E;

    Graph g(V);

    for(int i=0;i<E;i++){
        int u,v;
        cin >> u >> v;
        g.addEdge(u,v);
    }

    g.dfs();

    return 0;
}