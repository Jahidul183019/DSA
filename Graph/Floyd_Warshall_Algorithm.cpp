//Problem link : https://www.codechef.com/problems/HOMDEL?tab=statement

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n;
    cin>>n;
    
    vector<vector<ll>>dist(n,vector<ll>(n));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dist[i][j];
        }
    }
    
    // Floyd-Warshall
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }
    }
    
    int t;
    cin>>t;
    
    while(t--){
        int S,G,D;
        cin>>S>>G>>D;
        
        ll x=dist[S][G] + dist[G][D];
        ll y=dist[S][D];
        
        cout<<x<<" "<<(x-y)<<endl;
    }
    return 0;
}
