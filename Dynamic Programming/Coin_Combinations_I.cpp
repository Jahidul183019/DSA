// https://cses.fi/problemset/task/1635

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MOD = 1e9 + 7;

#define ll long long

int coinComb(vector<ll>&coins,int x){
    int n=coins.size();

    vector<ll>dp(x+1,0);

    dp[0]=1;

    for(ll sum=1;sum<=x;sum++){
        for(ll i=0;i<n;i++){
            if(coins[i]<=sum){
                dp[sum]=(dp[sum]+dp[sum-coins[i]])%MOD;
            }
        }
    }
    return dp[x];

}
int main() {
    ll n,x;
    cin>>n>>x;

    vector<ll> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout<<coinComb(coins,x)<<endl;
    return 0;
}