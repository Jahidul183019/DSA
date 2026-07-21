// https://cses.fi/problemset/task/1158

#include <iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int maxpage(int n,int x,vector<int>&prices,vector<int>&pages){
     vector<vector<int>> dp(n + 1, vector<int>(x + 1,0));
 
     for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(prices[i]<=j){
                dp[i][j]=max(dp[i-1][j],pages[i]+dp[i-1][j-prices[i]]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
     }
     return dp[n][x];
}
int main() {
    int n,x;
    cin>>n>>x;
 
    vector<int>profit(n+1,0);
    vector<int>wt(n+1,0);
 
 
    for(int i=1;i<=n;i++){
        cin>>wt[i];
    }
 
    for(int i=1;i<=n;i++){
        cin>>profit[i];
    }
 
    cout<<maxpage(n,x,wt,profit)<<endl;
    return 0;
}