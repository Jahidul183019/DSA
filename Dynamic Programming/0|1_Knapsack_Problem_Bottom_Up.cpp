#include <iostream>
#include <vector>

using namespace std;

int knapsack(int m,vector<int>&profit,vector<int>&wt){
    int n=profit.size()-1;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for(int i=0;i<=n;i++){
        for(int w=0;w<=m;w++){
            if(i==0 || w==0){
                dp[i][w]=0;
            }else if(wt[i]<=w){
                dp[i][w]=max(profit[i]+dp[i-1][w-wt[i]],dp[i-1][w]);
            }else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }

    int i=n,j=m;
    while(i>0){
        if(j==0 || dp[i][j]==dp[i-1][j]){
            cout<<i<<" = "<<0<<endl;
            i--;
        }else{
            cout<<i<<" = "<<1<<endl;
            j=j-wt[i];
            i--;
        }
    }
    return dp[n][m];
}

int main()
{   
    int m,n;
    cin>>m>>n;

    vector<int>profit(n+1,0);
    vector<int>wt(n+1,0);

    for(int i=1;i<=n;i++){
        cin>>profit[i];
    }

    for(int i=1;i<=n;i++){
        cin>>wt[i];
    }

    cout<<knapsack(m,profit,wt)<<endl;

    return 0;
}
