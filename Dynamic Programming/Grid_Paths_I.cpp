// https://cses.fi/problemset/task/1638

#include<iostream>
#include<vector>
#include<string>

using namespace std;

const int MOD=1e9+7;

#define ll long long
int gridPaths(int n,vector<string>&grid){
    vector<vector<ll>>dp(n,vector<ll>(n,0));

    if(grid[0][0]=='*'){
        return 0;
    }

    dp[0][0]=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='*'){
                dp[i][j]=0;
                continue;
            }

            if(i==0 && j==0){
                continue;
            }

            if(i>0){
                dp[i][j]+=dp[i-1][j];
            }

            if(j>0){
                dp[i][j]+=dp[i][j-1];
            }

            dp[i][j]%=MOD;
        }
    }

    return dp[n-1][n-1];
}

int main() {
    int n;
    cin>>n;

    vector<string>grid(n);

    for (int i=0;i<n;i++) {
        cin>>grid[i];
    }

    cout<<gridPaths(n, grid)<< endl;
}