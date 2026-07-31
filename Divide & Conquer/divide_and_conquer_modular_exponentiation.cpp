#include<iostream>
 
using namespace std;

#define ll long long

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
    int t;
    cin>>t;
    while(t--){
    long long A, k, M;

    cin>>A>>k>>M;

    cout<<powerMod(A, k, M)<<endl;

    }

    return 0;
}