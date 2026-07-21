// http://cses.fi/problemset/task/1097

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MOD = 1e9 + 7;

#define ll long long

ll removalGame(int n,vector<ll>&a){
    vector<vector<ll>>dp(n,vector<ll>(n,0));

    for(int i=0;i<n;i++){
        dp[i][i]=a[i];
    }

    for(int len=2;len<=n;len++){
        for(int l=0;l+len-1<n;l++){
            int r=l+len-1;

            ll takeleft=a[l]-dp[l+1][r];

            ll takeRight=a[r]-dp[l][r-1];

            dp[l][r]=max(takeleft,takeRight);
        }
    }

    ll total= 0;

    for (ll x : a) {
        total += x;
    }

    return (total + dp[0][n - 1]) / 2;
}
int main() {
    int n;
    cin>>n;

    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout<<removalGame(n,a)<< endl;
    return 0;
}