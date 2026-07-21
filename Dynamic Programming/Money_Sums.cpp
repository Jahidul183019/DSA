// https://cses.fi/problemset/task/1745

#include <iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
void moneySums(int n,vector<int>&coins){
    int total=0;

    for(auto x : coins){
        total+=x;
    }
     vector<bool>dp(total+1,false);
 
     dp[0]=true;

     for(int c : coins){
        for(int sum=total-c;sum>=0;sum--){
            if(dp[sum]){
                dp[sum+c]=true;
            }
        }
     }

     vector<int>ans;

     for(int sum=1;sum<=total;sum++){
        if(dp[sum]){
            ans.push_back(sum);
        }
     }

     cout<<ans.size()<<endl;

     for(int sum:ans){
        cout<<sum<<" ";
     }
     cout<<endl;
}
int main() {
    int n;
    cin>>n;
 
    vector<int>coins(n);

    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
 
 
    moneySums(n,coins);
    return 0;
}