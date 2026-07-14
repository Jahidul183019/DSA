// https://cses.fi/problemset/task/1633

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MOD = 1e9 + 7;

#define ll long long

int diceComb(ll n){
    vector<ll>dp(n+1,0);

    dp[0]=1;

    for(ll sum=1;sum<=n;sum++){
        for(ll dice=1;dice<=6;dice++){
            if(sum-dice>=0){
                dp[sum]=(dp[sum] + dp[sum-dice]) % MOD;
            }
        }
    }
    return dp[n];

}
int main() {
    ll n;
    cin>>n;

    cout<<diceComb(n)<<endl;
    return 0;
}
