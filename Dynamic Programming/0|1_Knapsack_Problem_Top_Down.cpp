
#include <iostream>
#include <vector>
using namespace std;

// Recursive Approach : TC O(2^n)

double knapsack01_Rec(vector<vector<int>>&items,int W,int n){
    if(n==0 || W==0) return 0;

    int val=items[n-1][0];
    int wt=items[n-1][1];

    if(wt<=W){
        int include= val + knapsack01_Rec(items,W-wt,n-1);

        int exclude=knapsack01_Rec(items,W,n-1);

        return max(include,exclude);

    }else{
        return knapsack01_Rec(items,W,n-1);
    }
}

//Memorization DP : TC (n*W)

double knapsack01_MemoDP(vector<vector<int>>&items,int W,int n,vector<vector<int>>&dp){
    if(n==0 || W==0) return 0;

    if(dp[n][W]!=-1) return dp[n][W];

    int val=items[n-1][0];
    int wt=items[n-1][1];

    if(wt<=W){
        int include= val + knapsack01_MemoDP(items,W-wt,n-1,dp);

        int exclude=knapsack01_MemoDP(items,W,n-1,dp);

        return dp[n][W]= max(include,exclude);

    }else{
        return dp[n][W]= knapsack01_MemoDP(items,W,n-1,dp);
    }
}

//Tabulation DP : TC (n*W)

double knapsack01_TabDP(vector<vector<int>>&items,int W,int n){
    vector<vector<int>>dp(n+1,vector<int>(W+1,0));

    for(int i=1;i<=n;i++){// i items
        for(int j=1;j<=W;j++){// j knapsack capacity
            int val=items[i-1][0];
            int wt=items[i-1][1];

            if(wt<=j){
                dp[i][j]=max(val+dp[i-1][j-wt],dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;

    cin >> n >> W;

    vector<vector<int>> items;

    for (int i = 0; i < n; i++) {
        int v, w;
        cin >> v >> w;

        items.push_back({v, w});   // {value, weight}
    }


    // cout<< knapsack01_Rec(items,W,n) << endl;

    // vector<vector<int>>dp(n+1,vector<int>(W+1,-1));

    // cout<<knapsack01_MemoDP(items,W,n,dp)<<endl;

    cout<<knapsack01_TabDP(items,W,n);

    return 0;
}
