// https://cses.fi/problemset/task/1093

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MOD = 1e9 + 7;

#define ll long long

int twoSets(int n){
    ll total = 1LL * n*(n+1)/2;

    if(total%2!=0) return 0;

    int target=total/2;

    vector<ll>dp(target+1,0);

    dp[0] = 1;

    for(int num=1;num<=n;num++){
        for(int sum=target;sum>=num;sum--){
            dp[sum]=(dp[sum]+dp[sum-num])%MOD;
        }
    }

    return (dp[target]*500000004)%MOD;
}
int main() {
    int n;
    cin>>n;

    cout<<twoSets(n)<<endl;
    return 0;
}