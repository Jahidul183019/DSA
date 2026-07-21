// https://cses.fi/problemset/task/1634

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MOD = 1e9 + 7;
#define ll long long

const ll INF = 1e18;
int minimizingCoins(vector<ll>&coins,int x){
    int n=coins.size();

    vector<ll>dp(x+1,INF);

    dp[0]=0;

    for(ll sum=1;sum<=x;sum++){
        for(ll i=0;i<n;i++){
            if(coins[i]<=sum){
                dp[sum]=min(dp[sum],dp[sum-coins[i]]+1);
            }
        }
    }
    return dp[x]==INF ? -1 : dp[x];

}
int main() {
    ll n,x;
    cin>>n>>x;

    vector<ll> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout<<minimizingCoins(coins,x)<<endl;
    return 0;
}