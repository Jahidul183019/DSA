// https://cses.fi/problemset/task/1636

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MOD = 1e9 + 7;

#define ll long long

int coinComb(vector<int>&coins,int x){
    int n=coins.size();

    vector<int>dp(x+1,0);

    dp[0]=1;

    for(int i=0;i<n;i++){
     for(int sum=1;sum<=x;sum++){
            if(coins[i]<=sum){
                dp[sum]=(dp[sum]+dp[sum-coins[i]])%MOD;
            }
        }
    }
    return dp[x];

}
int main() {
    int n,x;
    cin>>n>>x;

    vector<int>coins(n);

    for (int i=0;i<n;i++) {
        cin>>coins[i];
    }
    cout<<coinComb(coins,x)<<endl;
    return 0;
}