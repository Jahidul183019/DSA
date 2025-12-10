#include <iostream>
#include <vector>

using namespace std;

vector<int>parent,rankArr;

void makeSet(int n){
    parent.resize(n+1,-1);
    rankArr.resize(n+1,0);

    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
}

int findSet(int x){
    if(parent[x]!=x){
        parent[x]=findSet(parent[x]); // Path Compression
    }
    return parent[x];
}

void unionSet(int a,int b){
    int rootA=findSet(a);
    int rootB=findSet(b);

    if(rootA != rootB){
         if(rankArr[rootA] < rankArr[rootB]) {
            parent[rootA] = rootB;
        }
        else if(rankArr[rootA] > rankArr[rootB]) {
            parent[rootB] = rootA;
        }
        else {
            parent[rootB] = rootA;
            rankArr[rootA]++;
        }
    }
}
int main(){
     int n = 7;
     makeSet(n);

    unionSet(1, 2);
    unionSet(2, 3);
    unionSet(4, 5);
    unionSet(6, 7);
    unionSet(5, 6);

    cout << "Find(3): " << findSet(3) << endl;
    cout << "Find(7): " << findSet(7) << endl;

    if(findSet(3) == findSet(7))
        cout << "Same set" << endl;
    else
        cout << "Different set" << endl;
    return 0;
}