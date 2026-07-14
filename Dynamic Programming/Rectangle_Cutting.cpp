// https://cses.fi/problemset/task/1744/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int rectangleCutting(int a,int b){
    vector<vector<int>>dp(a+1,vector<int>(b+1,0));

    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j){
                dp[i][j]=0;
            }else{
                dp[i][j]=1e9;

                for(int k=1;k<i;k++){
                    dp[i][j]=min(dp[i][j],1+dp[i-k][j]+dp[k][j]);
                }

                for(int k=1;k<j;k++){
                    dp[i][j]=min(dp[i][j],1+dp[i][j-k]+dp[i][k]);
                }
            }
        }
    }

    return dp[a][b];
}
int main(){
    int a,b;
    cin>>a>>b;

    cout<<rectangleCutting(a,b)<<endl;
}