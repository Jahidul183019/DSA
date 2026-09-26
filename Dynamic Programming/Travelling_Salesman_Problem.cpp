#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF=1e9;

int tsp(vector<vector<int>>&cost){
   int n=cost.size();

   int totalMask=1<<n;

   vector<vector<int>>dp(totalMask,vector<int>(n,INF));

   dp[1][0]=0;

   for(int mask=1;mask<totalMask;mask++){
        for(int i=0;i<n;i++){
            if(!(mask & (1<<i))){
                continue;
            }

        for(int j=0;j<n;j++){
            if(mask & (1<<j)){
                continue;
            }
        
        int newMask=mask | (1<<j);

        dp[newMask][j]=min(dp[newMask][j],dp[mask][i]+cost[i][j]);
        }
     }
   }

   int fullMask=(1<<n)-1;

   int ans=INF;

   for(int i=1;i<n;i++){
    ans=min(ans,dp[fullMask][i] + cost[i][0]);
   }

   return ans;
}
int main(){
    vector<vector<int>> cost = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    cout<<tsp(cost)<<endl;
    return 0;
}