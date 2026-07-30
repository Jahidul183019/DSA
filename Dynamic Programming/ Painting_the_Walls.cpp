//Leetcode 2742

//Memorization DP
class Solution {
public:
    int helper(vector<int>& cost, vector<int>& time,int remain,int n,vector<vector<int>>&dp){
        const int INF=1e9;
        if (remain <= 0)
             return 0;

        if (n == 0)
         return INF;

        if(dp[n][remain]!=-1) return dp[n][remain];

        int c=cost[n-1];
        int cover=time[n-1]+1;

        int include=c+helper(cost,time,max(0,remain-cover),n-1,dp);

        int exclude=helper(cost,time,remain,n-1,dp);

        return dp[n][remain]=min(include,exclude);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();

        vector<vector<int>> dp(n + 1,vector<int>(n + 1, -1));

        return helper(cost, time, n, n, dp);
    }
};


//Tabulation DP
class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();

        const int INF=1e9;

        vector<vector<int>>dp(n+1,vector<int>(n+1,INF));
        
        for (int i = 0; i <= n; i++)
          dp[i][0] = 0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int cover=time[i-1]+1;
                dp[i][j]=min(dp[i-1][j],dp[i-1][max(0,j-cover)]+cost[i-1]);
            }
        }

        return dp[n][n];
    }
};