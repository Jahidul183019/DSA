#include <iostream>
#include <vector>

using namespace std;

class DisjointSetUnion{
public: 
     int n;
     vector<int>par,rank;

     DisjointSetUnion(int n){
        this->n=n;

        for(int i=0;i<n;i++){
            par.push_back(i);
            rank.push_back(0);
        }
     }

     void unionByRank(int a,int b){
        int parA=find(a);
        int parB=find(b);

        if(parA==parB){
            return;
        }

        if(rank[parA] == rank[parB]){ // Case 1
            par[parB]=parA;
            rank[parA]++;
        } else if(rank[parA] > rank[parB]){ // Case 2
            par[parB]=parA;
        }else{ // Case 3
            par[parA]=parB;
        }
     }

     int find(int x){
        if(par[x]==x){
            return x;
        }

        // return find(par[x]); without path compression
        return par[x] = find(par[x]); // path compression
     }

     void getInfo(){
        for(int i=0;i<n;i++){
            cout<<par[i]<<" ";
        }
        cout<<endl;

         for(int i=0;i<n;i++){
            cout<<rank[i]<<" ";
        }
        cout<<endl;
     }
};

int main(){
     DisjointSetUnion dsu(6);

     dsu.unionByRank(0,2);
     cout<<dsu.find(2)<<endl;

     dsu.unionByRank(1,3);
     dsu.unionByRank(2,5);
     dsu.unionByRank(0,3);

     cout<<dsu.find(2)<<endl;

     dsu.unionByRank(0,4);

     dsu.getInfo();
     return 0;

}
