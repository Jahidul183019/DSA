// https://cses.fi/problemset/task/3403/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(int m,vector<int>&a,int n,vector<int>&b,vector<int>&sol) {
        

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i] == b[j]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int i=m,j=n;

        while(i>0 && j>0){
            if(a[i]==b[j]){
                sol.push_back(a[i]);
                i--;
                j--;
            }else if(dp[i-1][j]>=dp[i][j-1]){
               i--;
            }
            else{
                j--;
            }
        }
        reverse(sol.begin(),sol.end());

        return dp[m][n];
    }
};

int main() {
    Solution obj;

    int m,n;
    cin>>m>>n;

    vector<int>a(m+1,0);

    vector<int>b(n+1,0);

    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    vector<int>sol;
    int ans = obj.longestCommonSubsequence(m,a,n,b,sol);

    cout << ans << endl;
    for(int x : sol){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}
