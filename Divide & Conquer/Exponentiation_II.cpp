// https://cses.fi/problemset/task/1712

#include<iostream>
 
using namespace std;

#define ll long long

const int MOD=1e9+7;

ll powerMod(ll A,ll k,ll M){
    if(k==0) return 1;

    if(k%2==0){
        ll half=powerMod(A,k/2,M);
        
        return (half*half)%M;
    }else{
        ll half=powerMod(A,(k-1)/2,M);

         return ((A % M) * ((half * half) % M)) % M;
    }
}

int main()
{
    int n;
    cin>>n;
    while(n--){
    long long a,b,c;

    cin>>a>>b>>c;
    
    ll exponent = powerMod(b,c,MOD-1);
    
    cout<<powerMod(a,exponent,MOD)<<endl;

    }

    return 0;
}