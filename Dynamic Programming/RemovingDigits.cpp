// https://cses.fi/problemset/task/1637

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MOD = 1e9 + 7;

#define ll long long

int removingDigits(ll n){
    vector<ll>dp(n+1,1e9);

    dp[0]=0;

    for(int i=1;i<=n;i++){
        int x=i;

        while(x>0){
            int digit=x%10;

            if(digit!=0){
            dp[i]=min(dp[i],dp[i-digit]+1);
        }
          x/=10;
     }
   
    }
    return dp[n];

}
int main() {
    int n;
    cin>>n;

    cout<<removingDigits(n)<<endl;
    return 0;
}